class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int count=0,ans=0,leftZeros=0,rightOnes=0,totalOnes=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1')totalOnes++;
        }
        rightOnes=totalOnes;

        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                leftZeros++;
            }else{
                rightOnes--;
            }
            ans=max(ans,leftZeros+rightOnes);
        }
        return ans;
    }
};