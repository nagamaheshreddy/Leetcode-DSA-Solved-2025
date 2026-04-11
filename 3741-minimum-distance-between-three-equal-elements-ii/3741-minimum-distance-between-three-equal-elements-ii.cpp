class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        
        // Store indices of each number
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        bool found = false;
        
        // For each value, check all groups of 3 indices
        for (auto &p : indices) {
            vector<int> &v = p.second;
            if (v.size() < 3) continue; // Need at least 3 same numbers
            
            // For consecutive triples in sorted indices
            for (int i = 0; i + 2 < v.size(); i++) {
                int i1 = v[i], i2 = v[i+1], i3 = v[i+2];
                int dist = abs(i1 - i2) + abs(i2 - i3) + abs(i3 - i1);
                ans = min(ans, dist);
                found = true;
            }
        }
        
        return found ? ans : -1;
    }
};
