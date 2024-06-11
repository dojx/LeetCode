#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
    
        subset = []
        def dfs(i, subset):
            if i >= len(nums):
                res.append(subset.copy())
                return

            # Add current element to subset --> nums[i]
            subset.append(nums[i])
            dfs(i + 1)

            # Do NOT add current element to list --> []
            subset.pop()
            dfs(i + 1)

        dfs(0, [])
        return res
# @lc code=end

