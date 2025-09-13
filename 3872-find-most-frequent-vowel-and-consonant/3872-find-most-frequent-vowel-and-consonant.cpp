class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(auto ch: s){
            mp[ch]++;
        }
        vector<int>vowels;
        vector<int>consonants;
        char ch;
        int freq;

        for(auto pair:mp){
            ch=pair.first;
            freq=pair.second;

            if(isVowel(ch)){
                vowels.push_back(freq);
            }else{
                consonants.push_back(freq);
            }
        }
        sort(vowels.begin(),vowels.end(),greater<int>());
        sort(consonants.begin(),consonants.end(),greater<int>());

        int ans=0;
        if(vowels.size()>0)ans+=vowels[0];
        if(consonants.size()>0)ans+=consonants[0];
        return ans;
        


    }
};