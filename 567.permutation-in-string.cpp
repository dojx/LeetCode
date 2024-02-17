/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.23%)
 * Likes:    10956
 * Dislikes: 370
 * Total Accepted:    780.3K
 * Total Submissions: 1.8M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 * 
 * 
 */

/*
 * vector initialized with char count of s1
 * 2nd vector
 * l = 0, r = s1.size
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_count(26, 0);
        for (char c : s1) {
            s1_count[int(c) - int('a')]++;
        }

        vector<int> s2_count(26, 0);
        for (int i = 0; i < s1.size() && i < s2.size(); i++) {
            s2_count[int(s2[i]) - int('a')]++;
        }
        
        int l = 0, r = s1.size() - 1, s2_size = s2.size() - 1;
        while (r < s2_size) {
            if (s1_count == s2_count) return true;
            s2_count[int(s2[l]) - int('a')]--;
            l++, r++;
            s2_count[int(s2[r]) - int('a')]++;
        }
        if (s1_count == s2_count) return true;
        return false;
    }
};
// @lc code=end

