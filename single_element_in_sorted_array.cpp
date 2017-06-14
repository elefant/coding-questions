class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (right - left + 1 > 1) {
            int mid = (left + right) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            if (((right - left + 1 - 1) / 2) % 2 == 0) {
                // even number of pairs.
                if (nums[mid] == nums[mid - 1]) {
                    // x a a b b
                    //     ^
                    right = mid;
                } else {
                    //  a a b b x
                    //      ^
                    left = mid;
                }
            } else {
                // odd number of pairs.
                // a a b | b c c
                if (nums[mid] == nums[mid - 1]) {
                    // a a b b x c c
                    //       ^
                    left = mid + 1;
                } else {
                    // a a x b b c c
                    //       ^
                    right = mid - 1;
                }
            }
        }
        // Only one candidiate left.
        return nums[left];
    }
};