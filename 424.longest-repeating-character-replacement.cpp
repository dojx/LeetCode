/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (53.05%)
 * Likes:    9941
 * Dislikes: 447
 * Total Accepted:    619.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ABAB"\n2'
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 * 
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * There may exists other ways to achieve this answer too.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 * 
 * 
 */

/*
 * "sliding window"
 * iterate through string
 * store char, index pairs in hashmap
 * when repeat is found, subtract current index from stored index
 * if this value is less than k, update global max
 * update map to current index
 * return global max
 */


// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 1, l = 0, r = 0, s_size = s.size();
        int max_key = -1;
        map<char, int> m;
        while (r < s_size) {
            char c = s[r];
            m[c]++;
            max_key = max(max_key, m[c]);
            if ((r - l + 1) - max_key > k) {
                m[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
// @lc code=end

