class Solution {
public:
    bool isPrefix(string word,string &prefix){
        if(word.size()<prefix.size())return false;
        int i=0;
        while(i<prefix.size()){
            if(word[i]!=prefix[i])return false;
            i++;
        }
        return i==prefix.size();
    }
    int prefixCount(vector<string>& words, string pref) {
        // sort(words.begin(),words.end());
        int count=0;

        for(int i=0;i<words.size();i++){
            if(isPrefix(words[i],pref)){
                count++;
            }
        }
        return count;
    }
};