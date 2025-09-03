class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),longest=0,zeros=0;

        while(j<n){
            if(nums[j]==0)zeros++;

            while(zeros>k){
                if(nums[i]==0)zeros--;
                i++;
            }
            longest=max(longest,j-i+1);
            j++;
        }
        return longest;
    }
};