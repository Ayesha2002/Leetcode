 
//1000000007 helps manage large numbers in a way that prevents overflow\
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            int prefix = 0;
            for (int j = i; j < n; ++j) {
                prefix += nums[j];
                arr.push_back(prefix);
            }
        }
        sort(arr.begin(), arr.end());
        int result = 0;
        int MOD = 1000000007;
        for (int i = left - 1; i < right; ++i) {
            result = (result + arr[i]) % MOD;
        }
        return result;
    }
};
