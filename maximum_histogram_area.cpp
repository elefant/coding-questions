int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> nextRightSmaller(A.size(), A.size());
    {
        stack<int> nds; // non-decreasing stack
        for (int i = 0; i < A.size(); i++) {
            while (!nds.empty() && A[i] < A[nds.top()]) {
                nextRightSmaller[nds.top()] = i;
                nds.pop();
            }
            nds.push(i);
        }
    }

    vector<int> nextLeftSmaller(A.size(), -1);
    {
        stack<int> nds; // non-decreasing stack
        for (int i = A.size() - 1; i >= 0; i--) {
            while (!nds.empty() && A[i] < A[nds.top()]) {
                nextLeftSmaller[nds.top()] = i;
                nds.pop();
            }
            nds.push(i);
        }
    }


    int maxArea = 0;
    for (int i = 0; i < A.size(); i++) {
        int right = nextRightSmaller[i] - 1;
        int left = nextLeftSmaller[i] + 1;
        maxArea = max(maxArea, (right - left + 1) * A[i]);
    }

    return maxArea;
}
