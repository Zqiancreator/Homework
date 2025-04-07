/*
 * @lc app=leetcode.cn id=143 lang=c
 * @lcpr version=30204
 *
 * [143] 重排链表
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
#include <stdio.h>

void ReorderList(struct ListNode *head)
{
    // don't change if size <= 1
    if (head == NULL || head->next == NULL) {
        return;
    }

    // get the length of List
    struct ListNode *temp = head;
    int listLen = 0;
    while (temp != NULL) {
        listLen++;
        temp = temp->next;
    }

    // get the end half List
    temp = head;
    int remainLength = listLen - (listLen / 2);
    for (int i = 1; i < remainLength; i++) {
        temp = temp->next;
    }

    struct ListNode *newList = temp->next;
    struct ListNode *nextNode = newList->next;
    newList->next = NULL;
    temp->next = NULL;

    // size == 3
    if (nextNode == NULL) {
        newList->next = head->next;
        head->next = newList;
        return;
    }

    // get the new List
    while (nextNode->next != NULL) {
        temp = nextNode->next;
        nextNode->next = newList;
        newList = nextNode;
        nextNode = temp;
    }
    nextNode->next = newList;
    newList = nextNode;
    nextNode = newList->next;

    // start to insert
    struct ListNode *curHead = head;
    while (newList != NULL) {
        newList->next = curHead->next;
        curHead->next = newList;
        curHead = newList->next;
        newList = nextNode;
        if (newList == NULL) {
            break;
        }
        nextNode = nextNode->next;
    }

    return;
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */
