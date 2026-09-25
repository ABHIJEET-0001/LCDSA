class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0;
        int high = s.size();

        vector<int> ans;

        for(char c : s){
            if(c == 'I'){
                ans.push_back(low);
                low++;
            }else{
                ans.push_back(high);
                high--;
            }
        }

        ans.push_back(low);   // low == high

        return ans;
    }
};