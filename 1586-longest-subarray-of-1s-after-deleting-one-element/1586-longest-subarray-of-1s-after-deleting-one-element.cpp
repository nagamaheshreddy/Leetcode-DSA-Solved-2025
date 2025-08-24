class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros=0;
        int i=0,j=0,largest=0;

        while(j<nums.size()){
            if(nums[j]==0)zeros++;

            while(zeros>1){
                if(nums[i]==0)zeros--;
                i++;
            }
            largest=max(largest,j-i);
            j++;
        }
        return largest;
    }
};