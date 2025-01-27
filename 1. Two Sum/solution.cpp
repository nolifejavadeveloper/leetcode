class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (numToIndex.find(target - nums[i]) != numToIndex.end()) {
                // great
                return {i, numToIndex[target - nums[i]]};
            }

            numToIndex[nums[i]] =  i;
        }

        return {0, 0};
    }
};
