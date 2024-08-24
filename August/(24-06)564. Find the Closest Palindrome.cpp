class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> canBeNumber;
        
        // Handle edge cases
        canBeNumber.insert(long(pow(10, l)) + 1); // Case like 999 -> 1001
        canBeNumber.insert(long(pow(10, l - 1)) - 1); // Case like 1000 -> 999
        
        // Generate possible palindromes by adjusting the prefix
        long long prefix = stol(n.substr(0, (l + 1) / 2));
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend()); // Generate palindrome
            canBeNumber.insert(stol(pp));
        }
        
        // Find the closest palindrome
        long num = stol(n);
        long minDiff = LONG_MAX;
        long ans;
        for (long val : canBeNumber) {
            if (val == num) {
                continue; // Skip the original number if it's a palindrome
            }
            long currentDiff = abs(val - num);
            if (currentDiff < minDiff) {
                ans = val;
                minDiff = currentDiff;
            } else if (currentDiff == minDiff) {
                ans = min(ans, val); // Tie, take the smaller value
            }
        }
        return to_string(ans);
    }
};
