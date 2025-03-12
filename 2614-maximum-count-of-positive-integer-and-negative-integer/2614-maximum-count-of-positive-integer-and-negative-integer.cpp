class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int n=nums.size();
       int totalSize=n;
       int negativeIndex=0;

       for(int i=0;i<n;i++){
            if(nums[i]<0){
                negativeIndex++;
            }else if(nums[i]==0){
                totalSize--;
            }else{
                break;
            }
       } 

       return max(negativeIndex,totalSize-negativeIndex);
    }
};