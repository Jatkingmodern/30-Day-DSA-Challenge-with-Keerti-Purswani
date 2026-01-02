class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> mp;
        for (char c : secret) mp[c]++;

        int bulls = 0, cows = 0, n = secret.length();

        string left_over;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                mp[secret[i]]--;
                bulls++;
            } else {
                left_over.push_back(guess[i]);
            }
        }
        int k = left_over.size();
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                if (left_over[i] == secret[j] && mp[secret[j]] > 0) {
                    cows++;
                    mp[secret[j]]--;
                    break;
                }
            }
        }

        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
