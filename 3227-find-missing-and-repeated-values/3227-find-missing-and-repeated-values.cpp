class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

       unordered_set<int>s;
       int n=grid.size();
       int a,b;
       
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s.find(grid[i][j])!=s.end()){
                a=grid[i][j];
            }
            s.insert(grid[i][j]);
        }
       }

       for(int i=1;i<=n*n;i++){
        if(s.find(i)==s.end()){
            b=i;
            break;
        }
       }

       vector<int>ans;
       ans.push_back(a);
       ans.push_back(b);

       return ans;
    }
};