// this solution is faster but it takes a bit more memory. Runtime: 0ms Memory: 11.2MB
class Solution {
public:
    int romanToInt(string s) {
        int romans[256];
        romans['I'] = 1;
        romans['V'] = 5;
        romans['X'] = 10;
        romans['L'] = 50;
        romans['C'] = 100;
        romans['D'] = 500;
        romans['M'] = 1000;

        int ans = 0;
        int last = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int thisNum = romans[s[i]];
            if (last > thisNum) {
                ans -= thisNum;
            }else {
                ans += thisNum;
            }

            last = thisNum;
        }

        return ans;
    }
};

// this solution is slower but it takes less memory. Runtime: 0ms Memory: 10MB
class Solution {
public:
    int charToInt(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int ans = 0;
        int last = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int thisNum = charToInt(s[i]);
            if (last > thisNum) {
                ans -= thisNum;
            }else {
                ans += thisNum;
            }

            last = thisNum;
        }

        return ans;
    }
};
