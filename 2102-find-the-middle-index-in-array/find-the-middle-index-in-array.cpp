
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int totalSum = prefix[n];

        for(int i = 0; i < n; i++) {

            int leftSum = prefix[i];

            int rightSum = totalSum - prefix[i + 1];

            if(leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};
