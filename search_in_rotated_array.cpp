int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int left = 0;
    int right = A.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] == B) {
            return mid;
        }
        if (A[mid] < B) {
            // check right but...
            if (A[right] < B && A[mid] <= A[right]) {
                right = mid - 1; // check left
            } else {
                left = mid + 1; // check right
            }
        } else { // A[mid] > B. Check left but...
            if (A[left] > B && A[left] <= A[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

// 1, 1, 1, 2, 1, 1,