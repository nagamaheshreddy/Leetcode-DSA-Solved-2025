class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();

        vector<int>rows(r,0);
        vector<int>cols(c,0);
        unordered_map<int,pair<int,int>>mp;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mp[mat[i][j]]={i,j};
            }
        }

        int i,j,num;
        for(int k=0;k<arr.size();k++){
            num=arr[k];
            i=mp[num].first;
            j=mp[num].second;
            rows[i]++;
            cols[j]++;

            if(rows[i]==c || cols[j]==r)return k;
        }
        return arr.size();
    }
};