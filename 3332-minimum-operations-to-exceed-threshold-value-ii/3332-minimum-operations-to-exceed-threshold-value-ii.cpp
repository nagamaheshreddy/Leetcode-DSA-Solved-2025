class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       priority_queue<long long,vector<long long>,greater<long long>>pq;

        for(int &num:nums){
            pq.push(num);
        }
        int operations=0;

        while(pq.size()>=2){
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();

            if(x>=k)break;

            long long newNum=min(x,y)*1LL*2 + max(x,y);
            pq.push(newNum);
            operations++;
        }

        return operations;
    }
};