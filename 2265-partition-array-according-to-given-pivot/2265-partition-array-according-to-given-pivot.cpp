class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());

        int pivotIndex=find(arr.begin(),arr.end(),pivot)-arr.begin();

        int i=0,j=pivotIndex;
        for(int k=0;k<nums.size();k++){
            if(nums[k]<pivot){
                arr[i]=nums[k];
                i++;
            }else if(nums[k]==pivot){
                arr[j]=nums[k];
                j++;
            }
        }

        for(int k=0;k<nums.size();k++){
            if(nums[k]>pivot){
                arr[j]=nums[k];
                j++;
            }
        }

        return arr;
    }
};