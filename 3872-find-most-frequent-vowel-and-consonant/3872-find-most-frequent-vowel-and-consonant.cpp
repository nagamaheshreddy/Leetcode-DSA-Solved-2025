class Solution {
public:
    bool isVowel(char ch){
        static const string vowels = "aeiou";
        return vowels.find(ch) != string::npos;
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        int maxVowelFreq = 0, maxConsonantFreq = 0;

        for (const auto& [ch, freq] : freqMap) {
            if (isVowel(ch)) {
                maxVowelFreq = max(maxVowelFreq, freq);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, freq);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};