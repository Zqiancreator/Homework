/*
 * @lc app=leetcode.cn id=1823 lang=c
 * @lcpr version=30204
 *
 * [1823] 找出游戏的获胜者
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
int findTheWinner(int n, int k)
{
    if (n == 1) {
        return 1;
    }
    return (k + findTheWinner(n - 1, k) - 1) % n + 1;
}
// @lc code=end

/*
// @lcpr case=start
// 5\n2\n
// @lcpr case=end

// @lcpr case=start
// 6\n5\n
// @lcpr case=end

 */
