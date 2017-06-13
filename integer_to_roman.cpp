string digitToRoman(int aDigit, const string& aAtoms) {
    // aAtoms: [1, 5, 10];
    string atom1(1, aAtoms[0]);
    string atom5(1, aAtoms[1]);
    string atom10(1, aAtoms[2]);
    switch (aDigit) {
        case 0: return "";
        case 1: return atom1;
        case 2: return atom1 + atom1;
        case 3: return atom1 + atom1 + atom1;
        case 4: return atom1 + atom5;
        case 5: return atom5;
        case 6: return atom5 + atom1;
        case 7: return atom5 + atom1 + atom1;
        case 8: return atom5 + atom1 + atom1 + atom1;
        case 9: return atom1 + atom10;
    }
}

string Solution::intToRoman(int A) {
    // 1: I
    // 5: V
    // 10: X
    // 50: L
    // 100: C
    // 500: D
    // 1000: M

    vector<string> atoms = { "IVX", "XLC", "CDM", "M??" };

    vector<string> reversedAns;
    int pos = 0;
    while (A > 0) {
        reversedAns.push_back(digitToRoman(A % 10, atoms[pos]));
        A /= 10;
        pos++;
    }

    string ans;
    for (int i = reversedAns.size() - 1; i >= 0; i--) {
        ans += reversedAns[i];
    }
    return ans;
}

///////////////////////////////////////////////////////////////

int Solution::romanToInt(string A) {
    // 1: I
    // 5: V
    // 10: X
    // 50: L
    // 100: C
    // 500: D
    // 1000: M
    map<char, int> romanToNum = { {'I', 1},
                                  {'V', 5},
                                  {'X', 10},
                                  {'L', 50},
                                  {'C', 100},
                                  {'D', 500},
                                  {'M', 1000} };

    int num = romanToNum[A[0]];
    for (int i = 1; i < A.size(); i++) {
        num += romanToNum[A[i]];
        // IV => 1 + 5 - 2*1
        if (romanToNum[A[i - 1]] < romanToNum[A[i]]) {
            num -= 2 * romanToNum[A[i - 1]];
        }
    }

    return num;
}
