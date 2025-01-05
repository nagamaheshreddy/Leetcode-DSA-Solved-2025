class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);

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

        for (int i = 1; i <= n; i++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++) {
            prefix[i] = (prefix[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + prefix[i]) % 26;
        }
        //Solved

        return s;
    }
};
