class Solution {
public:

    bool isPrefix(string a,string b){
        if(b.size()<a.size())return false;
        int i=0;

        while(i<a.size()){
            if(a[i]!=b[i])return false;
            i++;
        }
        return true;
    }

    bool isSuffix(string a,string b){
        reverse(b.begin(),b.end());
        reverse(a.begin(),a.end());
        return isPrefix(a,b);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int n=words.size(),count=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j && isPrefix(words[i],words[j]) && isSuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};