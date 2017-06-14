class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSumIndexMap;
        prefixSumIndexMap[0] = -1;
        int sum = 0;
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            auto itr = prefixSumIndexMap.find(sum);
            if (itr != prefixSumIndexMap.end()) {
                int idx = itr->second;
                // nums[idx + 1] ... nums[i]
                maxLength = max(maxLength, i - idx);
            }
            if (!prefixSumIndexMap.count(sum)) {
                prefixSumIndexMap[sum] = i;
            }
        }
        return maxLength;
    }
};