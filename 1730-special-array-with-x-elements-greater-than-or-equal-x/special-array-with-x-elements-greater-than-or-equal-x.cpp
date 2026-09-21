class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int x = 1; x <= n; x++) {
            int idx = n - x;

            if (nums[idx] >= x &&
                (idx == 0 || nums[idx - 1] < x)) {
                return x;
            }
        }

        return -1;
    }
};