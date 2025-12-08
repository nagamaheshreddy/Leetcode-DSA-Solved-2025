class Solution {
public:
    void solve(int i,int n,vector<int>&subset,int k,vector<vector<int>>&ans){
        if(i>n+1)return ;
        if(subset.size()==k){
            ans.push_back(subset);
            return;
        }

        subset.push_back(i);
        solve(i+1,n,subset,k,ans);
        subset.pop_back();

        solve(i+1,n,subset,k,ans);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>subset;

        solve(1,n,subset,k,ans);
        return ans;
    }
};