class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size(),i=0,j=0,ans=INT_MAX,whites=0;

        while(j<n){
            if(blocks[j]=='W')whites++;

            if(j-i+1==k){
                ans=min(ans,whites);
                if(blocks[i]=='W')whites--;
                i++;
            }
            j++;
        }
        return ans;
    }
};