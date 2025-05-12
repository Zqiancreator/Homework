/*
 * @lc app=leetcode.cn id=LCR 078 lang=c
 * @lcpr version=30204
 *
 * [LCR 078] 合并 K 个升序链表
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MIN_NUM 10001
struct ListNode *MergeKLists(struct ListNode **lists, int listsSize)
{
    struct ListNode *res = NULL, *tmp = NULL, *head = NULL;
    int min = MIN_NUM;
    int curIndex = 0;
    int nullNodeNum = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i] == NULL) {
            nullNodeNum++;
        }
    }
    while (nullNodeNum < listsSize) {
        min = MIN_NUM;
        for (int i = 0; i < listsSize; i++) {
            // find the cur smallest
            if (lists[i] != NULL && lists[i]->val < min) {
                tmp = lists[i];
                curIndex = i;
                min = tmp->val;
            }
        }
        if (lists[curIndex] != NULL)
            lists[curIndex] = lists[curIndex]->next;
        if (lists[curIndex] == NULL) {
            nullNodeNum++;
        }
        if (res == NULL) {
            res = tmp;
            head = res;
        } else {
            res->next = tmp;
            res = res->next;
        }
    }

    return head;
}
// @lc code=end

/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */
