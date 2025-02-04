class Solution {
    public int maxAscendingSum(int[] nums) {
        int n=nums.length;
        int prev,sum,j,ans=0;

        for(int i=0;i<n;i++){
            prev=nums[i];
            sum=prev;
            j=i+1;
            while(j<n && prev<nums[j]){
                sum+=nums[j];
                prev=nums[j];
                j++;
            }
            if(sum>ans)ans=sum;
        }
        return ans;
    }
}