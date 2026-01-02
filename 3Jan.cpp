#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int OFFSET = 3000;
        const int MAX_SUM = 6001;
        const int K = 3;
        
        if (nums.size() < K) return 0;
        vector<vector<char>> dp(K + 1, vector<char>(MAX_SUM, 0));
        dp[0][OFFSET] = 1; 
        
        for (int num : nums) {
            vector<vector<char>> new_dp = dp;
            
            for (int k = 0; k < K; ++k) {
                for (int s = 0; s < MAX_SUM; ++s) {
                    if (dp[k][s]) {
                        int new_s = s + num;
                        if (new_s >= 0 && new_s < MAX_SUM) {
                            new_dp[k + 1][new_s] = 1;
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        int closest = 0;
        int min_diff = INT_MAX;
        int target_offset = target + OFFSET;
        
        for (int s = 0; s < MAX_SUM; ++s) {
            if (dp[K][s]) {
                int current_sum = s - OFFSET;
                int diff = std::abs(current_sum - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    closest = current_sum;
                }
            }
        }
        
        return closest;
    }
};
