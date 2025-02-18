class Solution {
public:
    bool isPossible(string &str,string &pattern){
        if(str.size()!=pattern.size()+1)return false;

        for(int i=0;i<str.size()-1;i++){
            if(pattern[i]=='I' && str[i]>=str[i+1])return false;
            if(pattern[i]=='D' && str[i]<=str[i+1])return false;
        }

        return true;
    }
    void solve(string &perm,string &subset,vector<int>&vis,vector<string>&permutations){
        if(subset.size()==perm.size()){
            permutations.push_back(subset);
            return ;
        }

        for(int i=0;i<perm.size();i++){
            if(vis[i]==0){
                subset+=perm[i];
                vis[i]=1;
                solve(perm,subset,vis,permutations);
                subset.pop_back();
                vis[i]=0;
            }
        }

    }
    string smallestNumber(string pattern) {
        string perm;
        char ch='1';
        for(int i=0;i<=pattern.size();i++){
            perm+=ch;
            ch+=1;
        }
        string subset;
        vector<int>vis(10,0);
        vector<string>permutations;

        solve(perm,subset,vis,permutations);

        // sort(permutations.begin(),permutations.end());
        string ans="zzzzzzzzz";
        for(string &str:permutations){
            if(isPossible(str,pattern)){
                ans=min(ans,str);
            }
        }

        return ans;
    }
};