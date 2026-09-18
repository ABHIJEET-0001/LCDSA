class Solution:
    def rob(self, nums):
        n = len(nums)

        if n == 1:
            return nums[0]

        def rob_line(left, right):
            prev2 = 0
            prev1 = 0

            for i in range(left, right + 1):
                take = nums[i] + prev2
                skip = prev1

                cur = max(take, skip)

                prev2 = prev1
                prev1 = cur

            return prev1

        return max(
            rob_line(0, n - 2),   # First include, last exclude
            rob_line(1, n - 1)    
        )