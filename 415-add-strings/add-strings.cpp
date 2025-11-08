#include <algorithm>

class Solution {
public:
    string addStrings(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string result = "";
        int carry = 0;

        while (i >= 0 || j >= 0) {
            int da = 0;
            int db = 0;
            if (i >= 0) da = a[i] - '0';
            if (j >= 0) db = b[j] - '0';

            int sum = da + db + carry;
            int digit = sum % 10;
            carry = sum / 10;

    
            result.push_back('0' + digit);

            i--;
            j--;
        }

        // if an extra carry remains, append it
        if (carry > 0) result.push_back('0' + carry);

        // reverse to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};
