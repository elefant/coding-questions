class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> minHeap;
        for (int n: nums) {
            minHeap.insert(n);
            if (minHeap.size() > k) {
                minHeap.erase(minHeap.begin());
            }
        }
        return *minHeap.begin();
    }
};