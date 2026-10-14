
class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";

        for (char digit : num) {
            while (!st.empty() && k > 0 &&
                   st.back() > digit) {
                st.pop_back();
                k--;
            }

            st.push_back(digit);
        }

        // If removals remain, remove digits from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        st = st.substr(i);

        return st.empty() ? "0" : st;
    }
};
