class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for (int i = 0; i < s.size(); i++) {
            freq1[s[i]]++;
            freq2[t[i]]++;
        }

        for (auto pairVal : freq1) {
            if (pairVal.second != freq2[pairVal.first]) {
                return false;
            }
        }

        return true;
    }
};
