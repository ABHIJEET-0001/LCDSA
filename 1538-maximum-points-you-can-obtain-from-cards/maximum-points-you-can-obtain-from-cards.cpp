class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
 
        if (k < 0 || k > n) {
            return -1;
        }
 
        if (k == 0) {
            return 0;
        }
 
      
        if (k == n) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
 
        vector<int> leftSum(k + 1, 0);
        vector<int> rightSum(k + 1, 0);
 
        for (int i = 1; i <= k; i++) {
            leftSum[i] = leftSum[i - 1] + cardPoints[i - 1];
        }
 
      
        for (int i = 1; i <= k; i++) {
            rightSum[i] = rightSum[i - 1] + cardPoints[n - i];
        }
 
        int maxScore = INT_MIN;
 
      
        for (int leftCount = 0; leftCount <= k; leftCount++) {
            int rightCount = k - leftCount;
 
            int currentScore =
                leftSum[leftCount] + rightSum[rightCount];
 
           
            if (currentScore > maxScore) {
                maxScore = currentScore;
            }
        }
 
        return maxScore;
    }
};