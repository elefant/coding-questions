int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int closest = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        int hardLeft = i;
        int left = i + 1; // soft left bound
        int right = A.size() - 1; // soft right bound
        while (left < right) {
            int sum = A[hardLeft] + A[left] + A[right];
            if (sum == B) {
                return sum;
            }
            if (abs(B - sum) < abs(B - closest)) {
                closest = sum;
            }

            if (sum < B) {
                left++;
            } else {
                right--;
            }
        }
    }
    return closest;
}

////////////////////////////////////////////////////////////

vector<vector<int> > Solution::threeSumDup(vector<int> &A) {
    sort(A.begin(), A.end());
    /*
    int cnt = 0;
    for (auto num: A) {
        if (cnt == 0 || num != A[cnt - 1]) {
            A[cnt++] = num;
        }
    }
    A.resize(cnt);
    */
    vector<vector<int>> sol;
    for (int i = 0; i < A.size(); i++) {
        int hardLeft = i;
        int left = i + 1;
        int right = A.size() - 1;
        while (left < right) {
            int sum = A[hardLeft] + A[left] + A[right];
            if (sum == 0) {
                sol.push_back({A[hardLeft], A[left], A[right]});
                while (++left < A.size() && A[left - 1] == A[left]);
                while (--right >= 0 && A[right + 1] == A[right]);
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
        while (i + 1 < A.size() && A[i + 1] == A[i]) {
            i++;
        }
    }
    return sol;
}
