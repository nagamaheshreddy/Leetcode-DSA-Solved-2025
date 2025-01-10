class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>words2Map;
        unordered_map<char,int>words2MapFinal;


        for(auto &word:words2){
            for(char &ch:word){
                words2Map[ch]++;
                words2MapFinal[ch]=max(words2Map[ch],words2MapFinal[ch]);
            }
            words2Map.clear();
        }

        unordered_map<char,int>mp;
        vector<string>ans;
        for(auto &word:words1){
            mp=words2MapFinal;
            for(char ch:word){
                if(mp.find(ch)!=mp.end()){
                    mp[ch]--;
                    if(mp[ch]==0)mp.erase(ch);
                }
            }
            if(mp.size()==0)ans.push_back(word);
        }

        return ans;

    }
};