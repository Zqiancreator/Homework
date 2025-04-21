/*
 * @lc app=leetcode.cn id=146 lang=c
 * @lcpr version=30204
 *
 * [146] LRU 缓存
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} LRUCache;

int gSize;
LRUCache *usr = NULL;
LRUCache *lRUCacheCreate(int capacity)
{
    gSize = capacity;
    return usr;
}

int lRUCacheGet(LRUCache *obj, int key)
{
    LRUCache *cur;
    HASH_FIND_INT(usr, &key, cur);
    // the key have been used, we have to del and add it to make sure conforming to LRU
    if (cur != NULL) {
        HASH_DEL(usr, cur);
        HASH_ADD_INT(usr, key, cur);
        return cur->value;
    }
    return -1;
}

void lRUCachePut(LRUCache *obj, int key, int value)
{
    LRUCache *cur = NULL, *temp = NULL;
    HASH_FIND_INT(usr, &key, cur);
    // if this key has already exist, have to del and add new one
    if (cur != NULL) {
        HASH_DEL(usr, cur);
        cur->key = key;
        cur->value = value;
        HASH_ADD_INT(usr, key, cur);
    } else {
        int cnt = HASH_COUNT(usr);
        // the Cache is full, delete the LRU one
        if (cnt == gSize) {
            HASH_ITER(hh, usr, cur, temp)
            {
                HASH_DEL(usr, cur);
                free(cur);
                break;
            }
        }
        LRUCache *new = (LRUCache *)malloc(sizeof(LRUCache));
        new->key = key;
        new->value = value;
        HASH_ADD_INT(usr, key, new);
    }
    return;
}

void lRUCacheFree(LRUCache *obj)
{
    LRUCache *cur = NULL, *temp = NULL;
    HASH_ITER(hh, usr, cur, temp)
    {
        HASH_DEL(usr, cur);
        free(cur);
    }
    return;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/
// @lc code=end
