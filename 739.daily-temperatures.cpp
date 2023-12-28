/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (65.91%)
 * Likes:    12039
 * Dislikes: 271
 * Total Accepted:    762.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 * 
 * 
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */

/*
 * Iterate through the array once, adding each element to a stack
 * If the current element is greater than the top of the stack, 
 * initialize counter at 1 and start emptying the stack incrementing
 * the counter each time an element is popped. Store counter value in 
 * result array
 * 
 * Time: O(n)
 * Space: O(n)
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<array<int, 2>> s;
        for (int i = 0; i < temperatures.size(); i++) {
            int n = temperatures[i];
            while (s.size() && n > s.top()[0]) {
                res[s.top()[1]] = i - s.top()[1];
                s.pop();
            }
            s.push({n, i});
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
    solution.dailyTemperatures(v);
    return 0;
}

