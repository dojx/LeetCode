/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 *
 * https://leetcode.com/problems/car-fleet/description/
 *
 * algorithms
 * Medium (50.47%)
 * Likes:    3224
 * Dislikes: 809
 * Total Accepted:    206.6K
 * Total Submissions: 409.3K
 * Testcase Example:  '12\n[10,8,0,5,3]\n[2,4,1,1,3]'
 *
 * There are n cars going to the same destination along a one-lane road. The
 * destination is target miles away.
 * 
 * You are given two integer array position and speed, both of length n, where
 * position[i] is the position of the i^th car and speed[i] is the speed of the
 * i^th car (in miles per hour).
 * 
 * A car can never pass another car ahead of it, but it can catch up to it and
 * drive bumper to bumper at the same speed. The faster car will slow down to
 * match the slower car's speed. The distance between these two cars is ignored
 * (i.e., they are assumed to have the same position).
 * 
 * A car fleet is some non-empty set of cars driving at the same position and
 * same speed. Note that a single car is also a car fleet.
 * 
 * If a car catches up to a car fleet right at the destination point, it will
 * still be considered as one car fleet.
 * 
 * Return the number of car fleets that will arrive at the destination.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
 * Output: 3
 * Explanation:
 * The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting
 * each other at 12.
 * The car starting at 0 does not catch up to any other car, so it is a fleet
 * by itself.
 * The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting
 * each other at 6. The fleet moves at speed 1 until it reaches target.
 * Note that no other cars meet these fleets before the destination, so the
 * answer is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: target = 10, position = [3], speed = [3]
 * Output: 1
 * Explanation: There is only one car, hence there is only one fleet.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: target = 100, position = [0,2,4], speed = [4,2,1]
 * Output: 1
 * Explanation:
 * The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting
 * each other at 4. The fleet moves at speed 2.
 * Then, the fleet (speed 2) and the car starting at 4 (speed 1) become one
 * fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches
 * target.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == position.length == speed.length
 * 1 <= n <= 10^5
 * 0 < target <= 10^6
 * 0 <= position[i] < target
 * All the values of position are unique.
 * 0 < speed[i] <= 10^6
 * 
 * 
 */

/*
 * iterate through arrays, and add to stack {position, speed}
 * if current element "can become a fleet" with top of stack, just add to stack and update to slower speed
 * else, empty the stack, add current to stack and increment result by 1
 * after for is complete, guarenteed to have at least 1 element in stack so increment res by 1
 * 
 * "can become a fleet"
 * (p1 + multiple of s1 == p2 + multiple of s2) < target
 */

// @lc code=start
#include <array>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> fleets;
        vector<pair<int, float>> pos_time; // { {position_i, timeLeft_i}, {...}, ... }
         
        for(int i = 0; i < position.size(); i++)
            pos_time.push_back({ position[i], float(target - position[i]) / speed[i] });
        
        sort(pos_time.begin(), pos_time.end());
                   
        
        for(int i = 0; i < position.size(); i++){
            float fleet_i = pos_time[i].second;
         
            while(fleets.size() && (fleet_i >= fleets.top()))
                fleets.pop();
            
            fleets.push(fleet_i);
        }
        
        return fleets.size();
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v1 = {10,8,0,5,3};
    vector<int> v2 = {2,4,1,1,3};
    solution.carFleet(12, v1, v2);
    return 0;
}

