class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        int largest=-1;

        for(int &num:arr){
            mp[num]++;
        }

        for(auto &pair:mp){
            if(pair.first==pair.second && largest<pair.second){
                largest=pair.second;
            }
        }
        return largest;
    }
};