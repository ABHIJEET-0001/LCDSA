#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int previous = 0;
        int current = 0;

        int middle = (n + m) / 2;

        for (int count = 0; count <= middle; count++) {
            previous = current;

            
            if (i < n && j < m) {
               
                if (nums1[i] <= nums2[j]) {
                    current = nums1[i];
                    i++;
                } else {
                   
                    current = nums2[j];
                    j++;
                }
            } else if (i < n) {
               
                current = nums1[i];
                i++;
            } else {
                
                current = nums2[j];
                j++;
            }
        }

       
        if ((n + m) % 2 == 1) {
            return current;
        } else {
           
            return ((double)previous + current) / 2.0;
        }
    }
};
