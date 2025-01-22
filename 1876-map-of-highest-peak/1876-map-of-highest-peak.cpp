class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& water) {
       int m=water.size();
       int n=water[0].size();

       queue<pair<int,int>>q;
       vector<vector<int>>vis(m,vector<int>(n,0));

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(water[i][j]==1){
                q.push({i,j});
                vis[i][j]=1;
                water[i][j]=0;
            }
        }
       }
       vector<int>dx={-1,1,0,0};
       vector<int>dy={0,0,-1,1};

       while(!q.empty()){
         int x=q.front().first;
         int y=q.front().second;
         q.pop();

         for(int i=0;i<4;i++){
            int child_x=x+dx[i];
            int child_y=y+dy[i];

            if(child_x>=0 && child_x<m && child_y>=0 && child_y<n &&vis[child_x][child_y]==0){
                water[child_x][child_y]=1+water[x][y];
                vis[child_x][child_y]=1;
                q.push({child_x,child_y});
            }
         }
       }
       return water;

    }
};