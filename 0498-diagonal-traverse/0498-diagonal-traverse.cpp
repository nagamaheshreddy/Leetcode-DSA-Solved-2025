class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        int n=mat[0].size();
        int m=mat.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int>ans;
        vector<int>temp;
        for(int i=0;i<=m+n;i++){
            temp=mp[i];
            if(i%2==0)reverse(temp.begin(),temp.end());
            for(int &num : temp)ans.push_back(num);
        }
        return ans;
    }
};