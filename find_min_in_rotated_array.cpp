int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int left = 0; // inclusive
    int right = A.size() - 1; // inclusive
    int curMin = INT_MAX;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[left] <= A[mid] && A[mid] <= A[right]) {
            // 1, 2, 3, 4, 5
            // 2, 3, 4, 5, 1
            curMin = min(curMin, A[left]);
            return curMin;
        } else if (A[left] <= A[mid]) {
            curMin = min(curMin, A[left]);
            left = mid + 1;
        } else if (A[mid] <= A[right]) {
            curMin = min(curMin, A[mid]);
            right = mid - 1;
        } else {
            // A[left] >= A[mid] >= A[right] would never happen.

            // 1, 2, 3, 4, 5
            // 2, 3, 4, 5, 1
            // 3, 4, 5, 1, 2
            // 4, 5, 1, 2, 3
            // 5, 1, 2, 3, 4
        }
    }
    return -1;
}
