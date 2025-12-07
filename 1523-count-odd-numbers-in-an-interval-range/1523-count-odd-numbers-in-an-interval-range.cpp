class Solution {
public:
    int countOdds(int low, int high) {
        int diff=high-low-1;
        int ans;

        if(low%2==0 && high%2==0){
            ans=ceil((double)diff/2);
        }
        else if(low%2!=0 && high%2!=0){
            ans=floor((double)diff/2);
            ans+=2;
        }
        else{
            ans=diff/2;
            ans+=1;
        }
        return ans;
        
    }
};