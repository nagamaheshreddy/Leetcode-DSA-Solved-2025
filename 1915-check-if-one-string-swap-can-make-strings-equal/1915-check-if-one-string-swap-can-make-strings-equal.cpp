class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        unordered_map<char, char> mp;
        int swaps = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]){
                mp[s1[i]] = s2[i];
                swaps++;
                if (swaps > 2)return false;
            }
        }

        for (auto pair : mp) {
            if (pair.first != pair.second && mp[pair.second] != pair.first)
                return false;
        }

        return true;
    }
};