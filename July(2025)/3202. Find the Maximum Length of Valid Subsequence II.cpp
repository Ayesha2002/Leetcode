//Time complexity:O(n^2)
//Space  complexity:O(n*k)

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 0));
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int mod = (nums[i] + nums[j]) % k;

                if (dp[j][mod]) {
                    dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
                } else {
                    dp[i][mod] = max(dp[i][mod], 2);
                }

                maxLength = max(maxLength, dp[i][mod]);
            }
        }

        return maxLength;
    }
};
