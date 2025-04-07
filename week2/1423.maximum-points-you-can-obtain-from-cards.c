/*
 * @lc app=leetcode.cn id=1423 lang=c
 * @lcpr version=30204
 *
 * [1423] 可获得的最大点数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
#include <stdio.h>
#include <string.h>

int MaxScore(int *cardPoints, int cardPointsSize, int k)
{
    if (cardPoints == NULL) {
        return 0;
    }

    int sum = 0, res;
    for (int i = 0; i < k; i++) {
        sum += cardPoints[i];
    }
    if (cardPointsSize == k) {
        return sum;
    }

    int *dp = malloc(sizeof(int) * (k + 1));
    if (dp == NULL) {
        return 0;
    }

    dp[k] = sum;
    res = sum;
    for (int i = 1; i <= k; i++) {
        dp[k - i] = dp[k - i + 1] - cardPoints[k - i] + cardPoints[cardPointsSize - i];
        res = res > dp[k - i] ? res : dp[k - i];
    }

    if (dp != NULL) {
        free(dp);
    }
    return res;
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [9,7,7,9,7,7,9]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,1000,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,79,80,1,1,1,200,1]\n3\n
// @lcpr case=end

 */
