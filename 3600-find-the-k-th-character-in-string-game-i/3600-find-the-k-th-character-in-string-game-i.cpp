class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        string append="";

        while(word.length()<k){
            for(char &ch : word){
                append+=(ch+1);
            }
            word+=append;
            append="";
        }
        return word[k-1];
    }
};