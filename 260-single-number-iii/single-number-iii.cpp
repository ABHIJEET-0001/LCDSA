
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;

        for (int num : nums) {
            xr ^= num;
        }

        long long bitNo = (long long)xr & -(long long)xr;

        int group1 = 0;
        int group2 = 0;

  
        for (int num : nums) {
            if ((num & bitNo) != 0) {
                group1 ^= num;
            } else {
                group2 ^= num;
            }
        }

        
        return {group1, group2};
    }
};
