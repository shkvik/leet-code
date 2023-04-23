//  Given an array of integers numsand an integer target, return indices of the two numbers such that they add up to target.
//  You may assume that each input would have exactly one solution, and you may not use the same element twice.
//  You can return the answer in any order.


//  Example
//  
//  Input: nums = [2, 7, 11, 15], target = 9
//  Output : [0, 1]
//  Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].




class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto umap = std::unordered_multimap<int, int>();
        auto size = nums.size();

        for (int i = 0; i < size; i++) {
            int complement = target - nums[i];
            if (umap.count(complement)) {

                auto cmp_value = umap.find(complement);

                if (cmp_value->second != i) {
                    auto result = std::vector<int>{ i, cmp_value->second };
                    std::sort(result.begin(), result.end());
                    return result;
                }
            }
            umap.emplace(nums[i], i);

        }

        return std::vector<int>{0};
    }
};