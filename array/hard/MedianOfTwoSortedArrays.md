// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// 
// The overall run time complexity should be O(log(m + n)).
// 
// 
// Example 1:
// 
// Input: nums1 = [1, 3], nums2 = [2]
// Output : 2.00000
// Explanation : merged array = [1, 2, 3] and median is 2.
// 
// Example 2 :
// 
// Input : nums1 = [1, 2], nums2 = [3, 4]
// Output : 2.50000
// Explanation : merged array = [1, 2, 3, 4] and median is(2 + 3) / 2 = 2.5.

class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto merged = vector<int>(nums1.size() + nums2.size());
      
        std::copy(nums1.begin(), nums1.end(), merged.begin());
        std::copy(nums2.begin(), nums2.end(), merged.begin() + nums1.size());
        std::sort(merged.begin(), merged.end());
      
        auto size = merged.size();
        return size % 2 == 0 ?
            static_cast<float>(
                merged.at((size / 2) - 1) + merged.at(size / 2)
                    ) / 2.0f : merged.at(size / 2);
    }
};
