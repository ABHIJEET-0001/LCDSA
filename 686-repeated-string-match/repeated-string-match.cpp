class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        string temp = "";
        int count = 0;
        while (temp.length() < b.length()) {
            temp += a;
            count++;

        }

        
        if (temp.find(b) != string::npos) {
            return count;
        }

      
        temp += a;
        count++;
        if (temp.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};