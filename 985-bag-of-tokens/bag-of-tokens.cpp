class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int n = tokens.size();
        int j = n - 1;
        int score = 0;
        int maxScore = 0;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score++;
                maxScore = max(maxScore, score);
                i++;
            } else if (score >= 1) {
                power += tokens[j];
                score--;
                j--;
            } else {
                return maxScore;
            }
        }
        return maxScore;
    }
};