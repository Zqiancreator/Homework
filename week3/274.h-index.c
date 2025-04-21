/*
 * @lc app=leetcode.cn id=274 lang=c
 * @lcpr version=30204
 *
 * [274] H 指数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
int Compare(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}

int HIndex(int *citations, int citationsSize)
{
    // sort in descending order
    qsort(citations, citationsSize, sizeof(int), Compare);
    int *dp = malloc(sizeof(int) * citationsSize);
    if (dp == NULL) {
        return 0;
    }
    int res = 0;
    for (res = 0; res < citationsSize; res++) {
        if (citations[res] < (res + 1)) {
            break;
        }
    }
    free(dp);
    return res;
}
// @lc code=end

/*
// @lcpr case=start
// [3,0,6,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

 */
