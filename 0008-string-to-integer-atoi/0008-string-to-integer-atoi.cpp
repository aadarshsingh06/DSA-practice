class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long long num = 0;
        int sign = 1;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4. Overflow check
            if (sign * num >= INT_MAX) return INT_MAX;
            if (sign * num <= INT_MIN) return INT_MIN;

            i++;
        }

        return sign * num;
        
    }
};