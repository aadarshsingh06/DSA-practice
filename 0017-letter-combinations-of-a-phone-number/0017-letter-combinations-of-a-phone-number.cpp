class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        backtrack(digits, 0, "", mp, result);
        return result;
    }

private:
    void backtrack(string &digits, int index, string curr,
                   vector<string> &mp, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(curr);
            return;
        }

        string letters = mp[digits[index] - '0'];
        for (char c : letters) {
            backtrack(digits, index + 1, curr + c, mp, result);
        }
        
    }
};