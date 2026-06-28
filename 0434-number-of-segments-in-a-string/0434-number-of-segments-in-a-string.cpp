class Solution {
public:
    int countSegments(string s) {

        if(s.size() == 0) return 0;

        int words = 0;

          for(int i = 1; i < s.size(); i++) {
            if(s[i] == ' ' && s[i-1] != ' ') {
                words++;
            }
        }
        if(s.back() != ' ') {
            words++;
        }

        return words;
    }
};