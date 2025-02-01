class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0; 

        int left = 0;
        unordered_set<char> window;
        for (int i = 0; i < s.length(); i++) {
            while (window.count(s[i])) {
                window.erase(s[left]);
                left++; // move pointer forward
            }

            window.insert(s[i]);
            ans = max(i - left + 1, ans);
        }


        return ans;
    }
};
