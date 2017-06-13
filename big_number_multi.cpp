class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return product of num1 and num2
     */
    string multiply(string& num1, string& num2) {
        string result = "0";
        for (int i = num2.length() - 1; i >= 0; i--) {
            char c = num2[i];
            string tmp = multiplyOneDigit(num1, c);
            result = add(result, tmp);
            num1 += '0';
        }

        // Remove leading zeros.
        int i = 0;
        for (i = 0; i < result.size(); i++) {
            if (result[i] != '0') {
                break;
            }
        }
        if (i == result.size()) {
            return "0";
        }

        return result.substr(i);
    }

    string add(string& a, string& b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string ret;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            sum %= 10;
            ret = string() + (char)('0' + sum) + ret;
        }
        if (carry) {
            ret = string() + '1' + ret;
        }
        return ret;
    }

    string multiplyOneDigit(string& a, char b) {
        if (b == '0') {
            return "0";
        }
        string ret;
        int carry = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            char c = a[i];
            int sum = carry + (c - '0') * (b - '0');
            carry = sum / 10;
            sum %= 10;
            ret = string() + (char)('0' + sum) + ret;
        }
        if (carry) {
            ret = string() + (char)('0' + carry) + ret;
        }
        return ret;
    }
};