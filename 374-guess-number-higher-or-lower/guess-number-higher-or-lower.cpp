class Solution {
public:
    int guessNumber(int n) {

        int left = 1;
        int right = n;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            int ans = guess(mid);

            if (ans == 0) {
                return mid;
            }
            else if (ans == 1) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};