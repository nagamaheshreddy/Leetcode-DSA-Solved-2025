class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        unordered_set<string>s;

        for(string &word:words){
            int n=word.length();
            string newWord;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    newWord=word.substr(i,j-i+1);
                    if(newWord!=word)s.insert(newWord);
                }
            }
        }
        
        for(string word:words){
            if(s.find(word)!=s.end()){
                ans.push_back(word);
            }
        }
        return ans;
    }
};