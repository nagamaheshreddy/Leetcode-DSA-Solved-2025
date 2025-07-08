class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                int next = binarySearch(events, i + 1, events[i][1]);
                dp[i][j] = max(dp[i + 1][j], events[i][2] + (next < n ?
                dp[next][j - 1] : 0));
            }
        }
        return dp[0][k];
    }

    int binarySearch(vector<vector<int>>& events, int left, int end) {
        int right = events.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] > end) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};