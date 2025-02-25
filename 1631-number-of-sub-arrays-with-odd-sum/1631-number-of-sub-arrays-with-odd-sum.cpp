class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long sum=0,count=0;;
        long long evenCount=0,oddCount=0;
        long long MOD=1e9+7;

        for(int i=0;i<n;i++){
            sum+=arr[i];

            if(sum%2==0){
                evenCount++;
                count+=oddCount;
            }else{
                oddCount++;
                count+=evenCount+1;
            }
        }
        
        return count%MOD;
    }
};