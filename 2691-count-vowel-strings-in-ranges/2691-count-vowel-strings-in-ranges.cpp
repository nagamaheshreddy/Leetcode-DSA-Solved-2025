class Solution {
public:
    bool isStartsEndWithVowel(string str){
        int n=str.size();
        if((str[0]=='a' || str[0]=='e' || str[0]=='i'|| str[0]=='o'|| str[0]=='u') && (str[n-1]=='a' || str[n-1]=='e' || str[n-1]=='i'|| str[n-1]=='o'|| str[n-1]=='u'))return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>ans;
        vector<int>prefix(n+1,0);

        for(int i=0;i<words.size();i++){
            if(isStartsEndWithVowel(words[i])){
                prefix[i+1]=prefix[i]+1;
            }else{
                prefix[i+1]=prefix[i];
            }
        }

        for(int k=0;k<queries.size();k++){
            int i=queries[k][0];
            int j=queries[k][1];
            ans.push_back(prefix[j+1]-prefix[i]);
        }

        return ans;
    }
};