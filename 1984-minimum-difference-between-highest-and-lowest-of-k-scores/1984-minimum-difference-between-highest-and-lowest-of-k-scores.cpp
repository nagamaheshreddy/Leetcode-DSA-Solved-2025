class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int i=0,j=0,n=nums.size(),diff=0,minDiff=INT_MAX;
        while(j<n){

            if(j-i+1==k){
                int a=nums[i];
                int b=nums[j];
                diff=b-a;
                minDiff=min(minDiff,diff);
                i++;
            }
            j++;
        }
        return minDiff;
    }
};