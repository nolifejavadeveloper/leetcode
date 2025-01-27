class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> stored;
        vector used(nums.size(), false);
        rec(nums, ans, stored, used);

        return ans;
    }

    void rec(vector<int>& nums, vector<vector<int>>& ans, vector<int>& stored, vector<bool>& used) {
        if (stored.size() == nums.size()) {
            ans.push_back(stored);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            stored.push_back(nums[i]);
            used[i] = true;
            rec(nums, ans, stored, used);
            stored.pop_back();
            used[i] = false;
        }
    }
};
