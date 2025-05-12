/*
 * @lc app=leetcode.cn id=532 lang=c
 * @lcpr version=30204
 *
 * [532] 数组中的 k-diff 数对
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} hash;
int Cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; // 升序[2,5](@ref)
}
int FindPairs(int *nums, int numsSize, int k)
{
    hash *user = NULL;
    for (int i = 0; i < numsSize; i++) {
        hash *temp = NULL;
        HASH_FIND_INT(user, &nums[i], temp);
        if (temp == NULL) {
            hash *new = (hash *)malloc(sizeof(hash));
            new->key = nums[i];
            new->value = 1;
            HASH_ADD_INT(user, key, new);
        } else {
            temp->value++;
        }
    }
    int res = 0;
    qsort(nums, numsSize, sizeof(int), Cmp);
    for (int i = 0; i < numsSize; i++) {
        hash *temp = NULL;
        HASH_FIND_INT(user, &nums[i], temp);
        if (--temp->value == 0) {
            HASH_DEL(user, temp);
        }
        temp = NULL;
        HASH_FIND_INT(user, &nums[i], temp);
        int num = nums[i] + k;
        HASH_FIND_INT(user, &num, temp);
        if (temp != NULL) {
            res += 1;
        }
        while ((i + 1) < numsSize && nums[i + 1] == nums[i]) {
            i++;
        }
    }
    hash *current = NULL, *tmp = NULL;
    HASH_ITER(hh, user, current, tmp)
    {
        HASH_DEL(user, current);
        free(current);
    }
    return res;
}
// @lc code=end

/*
// @lcpr case=start
// [3, 1, 4, 1, 5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 3, 4, 5]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1, 3, 1, 5, 4]\n0\n
// @lcpr case=end

 */
