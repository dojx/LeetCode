/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;

        // find the start of loop
        while (s == 0 || s != f) {
            s = nums[s];
            f = nums[nums[f]];
        }

        // floyds stupid algorithm
        s = 0;
        while (s != f) {
            s = nums[s];
            f = nums[f];
        }

        return s;
    }
};
// @lc code=end

