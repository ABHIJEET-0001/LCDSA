class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int hg =0;
        int n = gain.size();
        for(int i = 0; i < n ; i++){
            alt +=gain[i];
            hg = max(hg,alt);

        }
        return hg;
        
    }
};