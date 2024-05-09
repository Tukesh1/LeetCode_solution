class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        // happiness is sorted
        // select nth element add it in ans and -1 from all other element
        // remove
        sort(begin(happiness), end(happiness), greater<int>());
        int i =0;
        int lastidx = happiness.size() - 1;
            while(k--) {
            happiness[i] = max(happiness[i] - i, 0);
            ans += happiness[i++];
        }
        return ans;
    }
};