class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int minDiff=INT_MAX;
        sort(arr.begin(),arr.end());

        for(int i=1;i<arr.size();i++){
            minDiff=min(minDiff,arr[i]-arr[i-1]);
        }

        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==minDiff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};