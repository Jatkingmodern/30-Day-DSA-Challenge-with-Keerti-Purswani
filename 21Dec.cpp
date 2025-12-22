#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safe(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    safe[i][j] = 0;
                }
                if (j > 0 && safe[i][j - 1] != INT_MAX) {
                    safe[i][j] = min(safe[i][j], safe[i][j - 1] + 1);
                }
                if (i > 0 && safe[i - 1][j] != INT_MAX) {
                    safe[i][j] = min(safe[i][j], safe[i - 1][j] + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i < n - 1 && safe[i + 1][j] != INT_MAX) {
                    safe[i][j] = min(safe[i][j], safe[i + 1][j] + 1);
                }
                if (j < n - 1 && safe[i][j + 1] != INT_MAX) {
                    safe[i][j] = min(safe[i][j], safe[i][j + 1] + 1);
                }
            }
        }
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        auto canReach = [&](int mid) -> bool {
            if (safe[0][0] < mid) return false;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            vis[0][0] = true;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1) return true;
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && safe[nx][ny] >= mid) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            return false;
        };
        int lo = 0, hi = min(safe[0][0], safe[n - 1][n - 1]), last = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReach(mid)) {
                last = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return last;
    }
};
