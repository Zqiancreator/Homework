/*
 * @lc app=leetcode.cn id=120 lang=c
 * @lcpr version=30204
 *
 * [120] 三角形最小路径和
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
int min(int a, int b)
{
    return a > b ? b : a;
}
int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
    int **dp = (int **)malloc(sizeof(int *) * triangleSize);
    if (!dp) {
        return 0;
    }
    for (int i = 0; i < triangleSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * triangleColSize[i]);
        if (!dp[i]) {
            return 0;
        }
    }
    dp[0][0] = triangle[0][0];
    for (int row = 1; row < triangleSize; row++) {
        for (int col = 0; col < triangleColSize[row]; col++) {
            if (col == 0) {
                dp[row][col] = dp[row - 1][col] + triangle[row][col];
            } else if (col == triangleColSize[row] - 1) {
                dp[row][col] = dp[row - 1][col - 1] + triangle[row][col];
            } else {
                dp[row][col] = min(dp[row - 1][col] + triangle[row][col], dp[row - 1][col - 1] + triangle[row][col]);
            }
        }
    }
    int res = dp[triangleSize - 1][0];
    for (int col = 1; col < triangleColSize[triangleSize - 1]; col++) {
        res = min(res, dp[triangleSize - 1][col]);
    }
    return res;
}
// @lc code=end

/*
// @lcpr case=start
// [[2],[3,4],[6,5,7],[4,1,8,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[-10]]\n
// @lcpr case=end

 */
