class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        string rows[3] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };

        int mp[26] = {};

        for(int i = 0; i < 3; i++) {
            for(char c : rows[i]) {
                mp[c - 'a'] = i;
            }
        }

        vector<string> ans;

        for(string word : words) {

            string w = word;

            for(char &c : w)
                c = tolower(c);

            int row = mp[w[0] - 'a'];

            bool valid = true;

            for(char c : w) {
                if(mp[c - 'a'] != row) {
                    valid = false;
                    break;
                }
            }

            
            if(valid)
                ans.push_back(word);
        }

        return ans;
    }
};