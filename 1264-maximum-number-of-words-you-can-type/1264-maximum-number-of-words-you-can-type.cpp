class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;
        vector<string>words;

        while(ss>>word){
            words.push_back(word);
        }
        unordered_set<char>letters;
        for(auto &ch: brokenLetters){
            letters.insert(ch);
        }

        int count=0;
        for(auto &word:words){
            bool found=false;
            for(auto & ch: word){
                if(letters.find(ch)!=letters.end()){
                    found=true;
                    break;
                }
            }
            if(!found)count++;
        }
        return count;
    }
};