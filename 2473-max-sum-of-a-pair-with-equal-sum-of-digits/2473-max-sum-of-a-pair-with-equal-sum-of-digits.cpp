class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n=n/10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int ans=-1,sum=-1,key;
        int n=nums.size();
        map<int,vector<int>>mp;
        sort(nums.begin(),nums.end(),greater<int>());

        for(int &num:nums){
            key=sumOfDigits(num);

            if(mp[key].size()<2){
                mp[key].push_back(num);
            }
        }

        for(auto pair:mp){
            if(pair.second.size()==2){
                sum=pair.second[0]+pair.second[1];
            }
            ans=max(ans,sum);
        }

        return ans;
    }
};