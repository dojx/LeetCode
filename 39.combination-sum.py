#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        subset = []
        def helper(i, rem):
            if i >= len(candidates):
                return
            if rem == 0:
                res.append(subset.copy())
                return
            if rem < 0:
                return
            subset.append(candidates[i])
            helper(i, rem - candidates[i])
            subset.pop()
            helper(i + 1, rem)

        helper(0, target)
        return res

# @lc code=end

