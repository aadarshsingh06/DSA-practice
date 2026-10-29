class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 2; i <= n; i++) {
            string curr = "";
            for (int j = 0; j < result.length(); j++) {
                int count = 1;
                while (j + 1 < result.length() && result[j] == result[j + 1]) {
                    count++;
                    j++;
                }
                curr += to_string(count) + result[j];
            }
            result = curr;
        }
        return result;
    }
};