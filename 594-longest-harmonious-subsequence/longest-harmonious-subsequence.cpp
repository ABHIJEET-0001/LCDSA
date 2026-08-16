class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> freq;

        // Count frequency of every number
        for (int num : nums) {
            freq[num]++;
        }

        int ans = 0;

        // Check every number x with x + 1
        for (auto it : freq) {

            int x = it.first;

            if (freq.find(x + 1) != freq.end()) {

                ans = max(ans, freq[x] + freq[x + 1]);
            }
        }

        return ans;
    }
};