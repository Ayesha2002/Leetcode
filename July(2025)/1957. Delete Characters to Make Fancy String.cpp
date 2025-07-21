class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string result = "";
        
        int freq = 1;
        result.push_back(s[0]);
        
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                freq++;
            } else {
                freq = 1;
            }

            if (freq < 3) {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};
