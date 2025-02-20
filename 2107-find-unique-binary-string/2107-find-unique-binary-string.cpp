class Solution {
public:
    void solve(int n, string &str, vector<string>&ans){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }

        str.push_back('0');
        solve(n,str,ans);
        str.pop_back();

        str.push_back('1');
        solve(n,str,ans);
        str.pop_back();

    }
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string>ans;
        string str;
        solve(nums[0].size(),str,ans);

        unordered_set<string>numsSet;
        for(string &str:nums){
            numsSet.insert(str);
        }

        for(string &str:ans){
            if(numsSet.find(str)==numsSet.end())return str;
        }

        return "";
    }
};