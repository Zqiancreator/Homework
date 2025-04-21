/*
 * @lc app=leetcode.cn id=567 lang=c
 * @lcpr version=30204
 *
 * [567] 字符串的排列
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
#define LETTER_NUM 27
bool IsEqual(int *cnt1, int *cnt2, int size)
{
    for (int i = 0; i < size; i++) {
        if (cnt1[i] != cnt2[i]) {
            return false;
        }
    }
    return true;
}
bool CheckInclusion(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL) {
        return 0;
    }
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 > len2) {
        return false;
    }
    int cnt1[LETTER_NUM];
    int cnt2[LETTER_NUM];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < len1; i++) {
        cnt1[s1[i] - 'a']++;
        cnt2[s2[i] - 'a']++;
    }
    if (IsEqual(cnt1, cnt2, LETTER_NUM) == true) {
        return true;
    }

    for (int slow = 1, fast = len1; fast < len2; slow++, fast++) {
        cnt2[s2[slow - 1] - 'a']--;
        cnt2[s2[fast] - 'a']++;
        if (IsEqual(cnt1, cnt2, LETTER_NUM) == true) {
            return true;
        }
    }
    return false;
}
// @lc code=end

/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */
