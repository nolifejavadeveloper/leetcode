class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> newNums;
        bool first = true;
        int last = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (first || nums[i] != last) {
                first = false;
                newNums.push_back(nums[i]);
                last = nums[i];
            }
        }

        nums = newNums;

        return newNums.size();
    }
};
