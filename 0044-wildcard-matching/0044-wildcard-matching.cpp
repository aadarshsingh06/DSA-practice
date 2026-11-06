class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIndex = -1, match = 0;

        while (i < s.size()) {

            // If characters match or pattern has '?'
            if (j < p.size() && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }

            // If pattern has '*'
            else if (j < p.size() && p[j] == '*') {
                starIndex = j;
                match = i;
                j++;
            }

            // If mismatch but we had a previous '*'
            else if (starIndex != -1) {
                j = starIndex + 1;
                match++;
                i = match;
            }

            else {
                return false;
            }
        }

        // Check remaining characters in pattern
        while (j < p.size() && p[j] == '*')
            j++;

        return j == p.size();
    
    }
};