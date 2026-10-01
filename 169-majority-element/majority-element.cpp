class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cd = 0;
        int ct = 0;
        for(int x : nums){
            if(ct == 0) cd = x;
            if(x == cd) ct++;
            else ct--;
        }
        return cd; 
    }
};