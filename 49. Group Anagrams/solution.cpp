class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> records;
        vector<vector<string>> ans;
        
        for (string s : strs) {
            int index;
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            if (records[sorted] == 0) {
                // does not exist
                index = ans.size() + 1; // / +1 because i cant think of a better way to identify empty vs just index 0
                records[sorted] = index; 
                ans.push_back({});

            }else {
                index = records[sorted];
            }

            ans[index - 1].push_back(s);
        }

        return ans;
    }
};
