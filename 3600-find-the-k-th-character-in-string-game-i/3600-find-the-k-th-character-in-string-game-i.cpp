class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        string append="";
        bool flag=true;

        while(flag){
            for(char &ch : word){
                append+=(ch+1);
            }
            word+=append;
            append="";
            if(word.length()>=k)flag=false;
        }
        return word[k-1];
    }
};