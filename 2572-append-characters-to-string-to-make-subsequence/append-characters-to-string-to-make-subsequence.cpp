class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int s_length = s.length(), t_length = t.length();
    
        while (i < s_length && j < t_length) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }
    
        return t_length - j;
    }
};