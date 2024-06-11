#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#

# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        
        # base case, array of size 1
        if len(nums) == 1:
            return [nums[:]]
        
        # pop 1st element, recursively calculate permutations, then add 1st element
        for i in range(len(nums)):
            n = nums.pop(0)
            perms = self.permute(nums)

            for perm in perms:
                perm.append(n)
            res.extend(perms)
            nums.append(n)

        return res
        
# @lc code=end

