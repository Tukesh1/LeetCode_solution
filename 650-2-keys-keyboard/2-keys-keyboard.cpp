class Solution {
public:
    int minSteps(int n) {
        // n times 'A'
        if (n <= 1) return 0;
        if (n == 2) return 2;
        vector<int> dp(n + 1, 0);
        dp[0] = 0; dp[1] = 0; dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            int factor = i / 2;
            while (factor >= 1) {
                if(i % factor == 0){
                    int steps_to_ptint_A =dp[factor];
                    int paste = (i/factor) -1;
                    dp[i]=  steps_to_ptint_A+paste+1;
                    break;

                }
                else{
                    factor--;
                }
            }
        }
        return dp[n];
    }
};