class Solution {
public:
    bool solve(int ind, int n, int sum, vector<int>& nums) {
        if (ind >= nums.size())
            return false;
        if (sum == n)
            return true;
        if (sum > n)
            return false;

        bool take = solve(ind + 1, n, sum + nums[ind], nums);
        bool notTake = solve(ind + 1, n, sum, nums);

        return take || notTake;
    }
    bool checkPowersOfThree(int n) {
        vector<int> nums;
        for (int i = 0; i <= 15; i++) {
            nums.push_back(pow(3, i));
        }

        int sum = 0;
        return solve(0, n, sum, nums);
    }
};