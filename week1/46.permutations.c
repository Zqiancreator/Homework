/*
 * @lc app=leetcode.cn id=46 lang=c
 * @lcpr version=30204
 *
 * [46] 全排列
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

void BackTrace(int *nums, int numsSize, int *curSize, int **ans, int *dp, int curIndex, int *curArray)
{
    for (int i = 0; i < numsSize; i++) {
        if (dp[i] == 0) {

            curArray[curIndex] = nums[i];
            dp[i] = 1;
        } else {
            continue;
        }
        if (curIndex == numsSize - 1) {

            memcpy(ans[*curSize], curArray, numsSize * (sizeof(int)));

            dp[i] = 0;
            (*curSize)++;
            continue;
        }
        BackTrace(nums, numsSize, curSize, ans, dp, curIndex + 1, curArray);
        dp[i] = 0;
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int temp = 1;
    for (int i = 1; i <= numsSize; i++) {
        temp *= i;
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * temp);
    if (!(*returnColumnSizes)) {
        return NULL;
    }
    for (int i = 0; i < temp; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    int **ans = (int **)malloc(sizeof(int *) * temp);
    if (!ans) {
        return NULL;
    }
    for (int j = 0; j < temp; j++) {
        ans[j] = (int *)malloc(sizeof(int) * numsSize);
        if (!ans[j]) {
            return NULL;
        }
    }
    int *dp = (int *)calloc(numsSize, sizeof(int));
    int *curArray = (int *)calloc(numsSize, sizeof(int));
    if (!dp || !curArray) {
        return NULL;
    }

    *returnSize = temp;

    int curSize = 0;
    BackTrace(nums, numsSize, &curSize, ans, dp, 0, curArray);

    return ans;
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
