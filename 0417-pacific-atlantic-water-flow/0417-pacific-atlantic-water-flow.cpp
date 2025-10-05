class Solution {
public:
    int m, n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    
    void bfs(vector<vector<int>>& h, queue<pair<int,int>>& q, vector<vector<bool>>& vis) {
        while (!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            vis[i][j] = true;
            for (auto &d : dirs) {
                int x = i+d[0], y = j+d[1];
                if (x>=0 && y>=0 && x<m && y<n && !vis[x][y] && h[x][y] >= h[i][j]) {
                    vis[x][y] = true;
                    q.push({x,y});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        queue<pair<int,int>> pq, aq;
        
        for (int i=0;i<m;i++) {
            pq.push({i,0}); aq.push({i,n-1});
        }
        for (int j=0;j<n;j++) {
            pq.push({0,j}); aq.push({m-1,j});
        }
        
        bfs(heights, pq, pac);
        bfs(heights, aq, atl);
        
        vector<vector<int>> res;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};