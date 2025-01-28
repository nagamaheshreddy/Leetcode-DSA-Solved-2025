class Solution {
public:

    int dfs(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)return 0;
        int count=grid[i][j];
        grid[i][j]=0;

        int left=dfs(i,j-1,n,m,grid);
        int right=dfs(i,j+1,n,m,grid);
        int down=dfs(i+1,j,n,m,grid);
        int up=dfs(i-1,j,n,m,grid);

        int ans=count+left+right+down+up;

        return ans;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0,count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    count=dfs(i,j,n,m,grid);
                    ans=max(ans,count);
                }
            }
        }

        return ans;
    }
};