class Solution {
public:
    int flipLights(int n, int presses) {
        vector<vector<bool>> op_configs(4, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; i++) {
            op_configs[0][i] = true;
            if (i % 2 == 0) {
                op_configs[1][i] = true;
            }
            if (i % 2 == 1) {
                op_configs[2][i] = true;
            }
            if (i % 3 == 1) {
                op_configs[3][i] = true;
            }
        }
        int different_possible_configs = 1;
        queue<vector<bool>> q;
        q.push(op_configs[0]);
        while (presses--) {
            set<vector<bool>> unique_configs;
            int q_size = q.size();
            while (q_size--) {
                auto curr_config = q.front();
                q.pop();
                for (const auto& op_config : op_configs) {
                    vector<bool> next_config = curr_config;
                    for (int i = 1; i <= n; i++) {
                        next_config[i] = next_config[i] ^ op_config[i];
                    }
                    if (unique_configs.find(next_config) ==
                        unique_configs.end()) {
                        unique_configs.insert(next_config);
                        q.push(next_config);
                    }
                }
            }
            different_possible_configs = unique_configs.size();
        }
        return different_possible_configs;
    }
};
