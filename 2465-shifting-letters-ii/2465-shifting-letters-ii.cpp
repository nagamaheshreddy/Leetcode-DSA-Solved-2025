class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);

        // Apply shifts using difference array technique
        for (auto& shift : shifts) {
            int i = shift[0], j = shift[1], dir = shift[2];

            if (dir == 1) {
                prefix[i] += 1;
                prefix[j + 1] -= 1;
            } else {
                prefix[i] -= 1;
                prefix[j + 1] += 1;
            }
        }

        // Convert difference array to prefix sum
        for (int i = 1; i <= n; i++) {  // Change `i < n` to `i <= n`
            prefix[i] += prefix[i - 1];
        }

        // Apply shifts to characters in `s`
        for (int i = 0; i < n; i++) {  // Change `i = 1` to `i = 0`
            prefix[i] = (prefix[i] % 26 + 26) % 26; // Normalize shift in range [0, 25]
            s[i] = 'a' + (s[i] - 'a' + prefix[i]) % 26;
        }

        return s;
    }
};
