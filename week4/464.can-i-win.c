/*
 * @lc app=leetcode.cn id=464 lang=c
 * @lcpr version=30204
 *
 * [464] 我能赢吗
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
// 1 <= maxChoosableInteger <= 20
// 0 <= desiredTotal <= 300

/// @brief recurse to find if current choose can win
/// @param dp record if the current chosen can win
/// @param used record which numbers have been chosen
/// @param maxChoosableInteger the scope of num
/// @param desiredTotal the target we have to reach
/// @param curSum the sum of numbers have been chosen
/// @return 1->win -1->lose 0->null
char dfs(int *dp, int used, int maxChoosableInteger, int desiredTotal, int curSum)
{
    if (dp[used] != 0) {
        return dp[used];
    }
    for (int i = 1; i <= maxChoosableInteger; i++) {
        // this num has been chosen
        if ((used & (1 << i)) != 0) {
            continue;
        }
        // if choose a certain num can win, return true
        if ((curSum + i >= desiredTotal) || dfs(dp, used | (1 << i), maxChoosableInteger, desiredTotal, curSum + i) == -1) {
            return dp[used] = 1;
        }
    }
    return dp[used] = -1;
}

bool CanIWin(int maxChoosableInteger, int desiredTotal)
{
    // if the sum of 1...maxChooseableInteger is < desiredTotal
    if (((maxChoosableInteger * (maxChoosableInteger + 1)) >> 1) < desiredTotal) {
        return false;
    }

    int *dp = malloc(sizeof(int) * (1 << (maxChoosableInteger + 1)));
    if (dp == NULL) {
        return false;
    }
    memset(dp, 0, sizeof(int) * (1 << (maxChoosableInteger + 1)));
    int res = dfs(dp, 0, maxChoosableInteger, desiredTotal, 0);
    free(dp);
    return res == 1;
}

// @lc code=end

/*
// @lcpr case=start
// 10\n11\n
// @lcpr case=end

// @lcpr case=start
// 10\n0\n
// @lcpr case=end

// @lcpr case=start
// 10\n1\n
// @lcpr case=end

 */
