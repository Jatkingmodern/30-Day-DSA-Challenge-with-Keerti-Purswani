class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int num : nums) total += num;
        if (total == n) return n - 1;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 1) {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] + 1;
            } else {
                dp[i][0] = 0;
                dp[i][1] = dp[i - 1][0];
            }
        }
        int max_val = 0;
        for (const auto& row : dp) {
            for (int val : row) {
                if (val > max_val) max_val = val;
            }
        }
        return max_val;
    }
};
