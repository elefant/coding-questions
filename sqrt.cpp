int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int left = 0; // inclusive
    int right = A / 2 + 1; // inclusive
    int ans = left;
    while (left <= right) {
        int64_t mid = (left + right) / 2;
        int64_t midSquare = mid * mid;
        if (midSquare == A) {
            return mid;
        }
        if (midSquare < A) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
