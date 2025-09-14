class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowerMap;
        unordered_map<string, string> devowelMap;
        
        auto toLower = [](const string &s) {
            string res = s;
            for (char &c : res) c = tolower(c);
            return res;
        };
        
        auto devowel = [&](const string &s) {
            string res = toLower(s);
            for (char &c : res) {
                if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    c = '#';
            }
            return res;
        };
        
        for (auto &w : wordlist) {
            string lw = toLower(w);
            if (!lowerMap.count(lw)) lowerMap[lw] = w;
            string dv = devowel(w);
            if (!devowelMap.count(dv)) devowelMap[dv] = w;
        }
        
        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lq = toLower(q);
            if (lowerMap.count(lq)) {
                ans.push_back(lowerMap[lq]);
                continue;
            }
            string dq = devowel(q);
            if (devowelMap.count(dq)) {
                ans.push_back(devowelMap[dq]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
