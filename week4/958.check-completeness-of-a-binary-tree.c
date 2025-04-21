/*
 * @lc app=leetcode.cn id=958 lang=c
 * @lcpr version=30204
 *
 * [958] 二叉树的完全性检验
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// nodes <= 100, so nodes in queue must be < 200
#define MAX_SIZE 200
typedef struct QUEUE_STRU {
    struct TreeNode *queue[MAX_SIZE];
    int front, rear;
} Queue;

bool IsCompleteTree(struct TreeNode *root)
{
    if (root == NULL) {
        return true;
    }
    Queue *current = malloc(sizeof(Queue));
    if (current == NULL) {
        return false;
    }
    current->front = current->rear = 0;
    current->queue[(current->rear++) % MAX_SIZE] = root;

    bool hasNULL = false;
    while (current->front != current->rear) {
        struct TreeNode *temp = current->queue[current->front];
        (current->front++) % MAX_SIZE;
        if (temp == NULL) {
            hasNULL = true;
            continue;
        }
        if (hasNULL) {
            return false;
        }
        current->queue[current->rear] = temp->left;
        (current->rear++) % MAX_SIZE;
        current->queue[current->rear] = temp->right;
        (current->rear++) % MAX_SIZE;
    }
    free(current);
    return true;
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,7]\n
// @lcpr case=end

 */
