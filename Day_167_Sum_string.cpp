

class Solution {
public:
    bool isSumString(string s) {
        int n = s.length();

        // Try all combinations for the first two numbers
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i, j - i);

                // Skip if numbers have leading zeros (but allow "0")
                if ((s1.length() > 1 && s1[0] == '0') ||
                    (s2.length() > 1 && s2[0] == '0')) continue;

                if (isValid(s1, s2, s.substr(j))) return true;
            }
        }
        return false;
    }

private:
    bool isValid(string num1, string num2, string remaining) {
        if (remaining.empty()) return true;

        string sum = addStrings(num1, num2);
        if (remaining.find(sum) != 0) return false; // not prefix

        return isValid(num2, sum, remaining.substr(sum.length()));
    }

    // Helper to add two numbers represented as strings
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0, i = num1.length() - 1, j = num2.length() - 1;

        while (i >= 0 || j >= 0 || carry > 0) {
            int d1 = (i >= 0) ? num1[i--] - '0' : 0;
            int d2 = (j >= 0) ? num2[j--] - '0' : 0;
            int sum = d1 + d2 + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
