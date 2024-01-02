/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (49.40%)
 * Likes:    9691
 * Dislikes: 498
 * Total Accepted:    523.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * Koko loves to eat bananas. There are n piles of bananas, the i^th pile has
 * piles[i] bananas. The guards have gone and will come back in h hours.
 * 
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she
 * chooses some pile of bananas and eats k bananas from that pile. If the pile
 * has less than k bananas, she eats all of them instead and will not eat any
 * more bananas during this hour.
 * 
 * Koko likes to eat slowly but still wants to finish eating all the bananas
 * before the guards return.
 * 
 * Return the minimum integer k such that she can eat all the bananas within h
 * hours.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [3,6,7,11], h = 8
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [30,11,23,4,20], h = 5
 * Output: 30
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: piles = [30,11,23,4,20], h = 6
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
 * 
 * 
 */

/*
 * Each pile will take at least 1 hr, so if h == size(piles) -> k = max(piles)
 *
 * 1. Sort input
 * 2. Iterate backwards, h - piles.length times
 * 3. If previous element (i + 1) is divisible by current, return piles(i) + 1
 *    else return piles(i)
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long t = hoursToEatPile(piles, m);
            if (t > h) {
                l = m + 1;
            } else {
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }

    long long hoursToEatPile(vector<int>& piles, int k) {
        long long sum = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            sum += ceil(double(piles[i]) / k);
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> v = {1000000000};
    solution.minEatingSpeed(v, 2);
    return 0;
}

