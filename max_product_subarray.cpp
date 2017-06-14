class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = nums[0];
        int curMax = nums[0];
        int globalMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            auto n = nums[i];
            // curMax = max(curMax * n, n, curMin * n)
            auto temp = curMax;
            curMax = max(curMax * n, max(n, curMin * n));
            // curMin = min(curMin * n, n, curMax * n)
            curMin = min(curMin * n, min(n, temp * n));
            globalMax = max(globalMax, curMax);
        }
        return globalMax;
    }
};