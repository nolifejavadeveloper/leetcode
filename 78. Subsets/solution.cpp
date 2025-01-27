class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> stored;
        rec(nums, ans, 0, stored);

        return ans;
    }

    void rec(vector<int>& nums, vector<vector<int>>& ans, int index, vector<int>& stored) {
        if (index == nums.size()) {
            ans.push_back(stored);
            return;
        }
        stored.push_back(nums.at(index));
        rec(nums, ans, index +1, stored);
        stored.pop_back();
        rec(nums, ans, index +1, stored);
    }
};
