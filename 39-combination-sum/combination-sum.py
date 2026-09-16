class Solution:
    def combinationSum(self, candidates, target):
        ans = []
        path = []

        def solve(index, target):
            # Base Case 1
            if target == 0:
                ans.append(path[:])   
                return

            # Base Case 2
            if index == len(candidates):
                return

            # TAKE
            if candidates[index] <= target:
                path.append(candidates[index])
                solve(index, target - candidates[index])   # same index
                path.pop()   # backtrack

            # NOT TAKE
            solve(index + 1, target)

        solve(0, target)
        return ans