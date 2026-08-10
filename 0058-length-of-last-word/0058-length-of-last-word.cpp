class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int count = 0;

        // 1. Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // 2. Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};