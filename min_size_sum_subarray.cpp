class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int left = 0;
        int right = 1; // exclusive
        int minSize = 0;
        int curSum = nums[left];
        while (left < right) {
            while (curSum < s && right < nums.size()) {
                curSum += nums[right++];
            }
            while (curSum >= s && left < right) {
                minSize = min(minSize, right - left);
                curSum -= nums[left];
                left++;
            }
        }

        return minSize;
    }
};