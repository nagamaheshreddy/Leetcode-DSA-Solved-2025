class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>seen;
        unordered_set<char>unique;
        unordered_map<char,int>mp;
        int count=0,n=s.size();

        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }

        int lastIndex,j;

        for(int i=0;i<n;i++){
            if(seen.find(s[i])==seen.end()){
                lastIndex=mp[s[i]];
                for(int j=i+1;j<lastIndex;j++){
                    unique.insert(s[j]);
                }
                count+=unique.size();
                unique.clear();
            }
            seen.insert(s[i]);            
        }
        return count;
    }
};