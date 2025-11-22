#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++){
            int a = nums[i];
            int b = target - a;

            // if key b exists
            if (map.find(b) != map.end()){
                return {map[b], i};
            }

            // Add new element to the map
            map[a] = i;
        }

        return {};
    }
};