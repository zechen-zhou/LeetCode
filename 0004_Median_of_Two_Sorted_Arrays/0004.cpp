#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        int mergeSize = nums1Size + nums2Size;

        // Create a dynamic array (vector)
        // vector of size nums1.size()+nums2.size(), all elements with default value 0
        std::vector<int> merged(mergeSize);

        // if array nums1 is empty, then the merged array is simply array nums2
        if (nums1Size == 0) {
            // if the length of array is even
            if (nums2Size % 2 == 0) {
                return (nums2[nums2Size/2] + nums2[nums2Size/2 - 1]) / 2.0;
            } 
            // if the length of array is odd
            else {
                return (nums2[(nums2Size-1) /2]);
            }
        } 
        // if array nums2 is empty, then the merged array is simply array nums1
        else if (nums2Size == 0) {
            if (nums1Size % 2 == 0) {
                return (nums1[nums1Size/2] + nums1[nums1Size/2 - 1]) / 2.0;
            } else {
                return (nums1[(nums1Size-1) /2]);
            }
        } 

        // if both array are not empty, merge two array
        else {
            int nums1LastIndex = nums1Size - 1;
            int nums2LastIndex = nums2Size - 1;
            int med1Index = -1;
            int med2Index = -1;

            // if mergeSize is even
            if (mergeSize % 2 == 0) {
                med1Index = (mergeSize / 2) - 1;
                med2Index = mergeSize / 2;
            } 
            // if mergeSize is odd
            else {
                med1Index = (mergeSize - 1) / 2;
            }

            // Build the array merged up to the median
            for (int i = nums1Size + nums2Size - 1; i >= med1Index; i--) {
                if (nums1LastIndex < 0 || nums2LastIndex < 0) {
                    // if the array nums1 is exhausted
                    if (nums1LastIndex < 0 && nums2LastIndex >= 0) {
                        merged[i] = nums2[nums2LastIndex];
                        nums2LastIndex--;
                    } 
                    // if the array nums2 is exhausted
                    else if (nums2LastIndex < 0 && nums1LastIndex >= 0) {
                        merged[i] = nums1[nums1LastIndex];
                        nums1LastIndex--;
            	    }
                } else if (nums1[nums1LastIndex] >= nums2[nums2LastIndex]) {
                    merged[i] = nums1[nums1LastIndex];
                    nums1LastIndex--;
                } else if (nums1[nums1LastIndex] < nums2[nums2LastIndex]) {
                    merged[i] = nums2[nums2LastIndex];
                    nums2LastIndex--;
                }
            }

            if (mergeSize % 2 == 0) {
                // if the merged array is even, return the mean value of two medians
                return (merged[med1Index] + merged[med2Index]) / 2.0;
            } else {
                // if the merged array is odd, return the median
                return merged[med1Index];
            }
        }
    }
};