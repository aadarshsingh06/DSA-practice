class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
    int n = words.size();
    int i = 0;

    while (i < n) {
        int j = i, len = 0;

        // find words for this line
        while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
            len += words[j].size();
            j++;
        }

        int gaps = j - i - 1;
        string line = "";

        // last line or single word
        if (j == n || gaps == 0) {
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) line += " ";
            }
            line += string(maxWidth - line.size(), ' ');
        } 
        else {
            int totalSpaces = maxWidth - len;
            int space = totalSpaces / gaps;
            int extra = totalSpaces % gaps;

            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) {
                    line += string(space + (extra-- > 0 ? 1 : 0), ' ');
                }
            }
        }

        result.push_back(line);
        i = j;
    }

    return result;
    }
};

                