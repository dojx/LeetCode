/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (49.49%)
 * Likes:    15034
 * Dislikes: 397
 * Total Accepted:    1.6M
 * Total Submissions: 3.2M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * You are given an m x n integer matrix matrix with the following two
 * properties:
 * 
 * 
 * Each row is sorted in non-decreasing order.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Given an integer target, return true if target is in matrix or false
 * otherwise.
 * 
 * You must write a solution in O(log(m * n)) time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int l = 0, r = matrix.size() - 1;
        // int m;
        // while (l <= r) {
        //     m = l + (r - l) / 2;
        //     if (matrix[m][0] == target) {
        //         return true;
        //     } else if (matrix[m][0] < target) {
        //         l = m + 1;
        //     } else {
        //         r = m - 1;
        //     }
        // }

        // if (r < 0) {
        //     return false;
        // }

        // int row = r;
        // l = 0;
        // r = matrix[0].size() - 1;

        // while (l <= r) {
        //     m = l + (r - l) / 2;
        //     if (matrix[row][m] == target) {
        //         return true;
        //     } else if (matrix[row][m] < target) {
        //         l = m + 1;
        //     } else {
        //         r = m - 1;
        //     }
        // }
        // return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int mid_value = matrix[mid / n][mid % n];
            if (mid_value == target) {
                return true;
            } else if (mid_value < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

