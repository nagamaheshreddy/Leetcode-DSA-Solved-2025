class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int leftSum=0;
        int count=0;

        for(int i=0;i<n-1;i++){
            leftSum+=nums[i];
            sum-=nums[i];
            if(abs(leftSum-sum)%2==0)count++;
        }
        return count;
    }
};