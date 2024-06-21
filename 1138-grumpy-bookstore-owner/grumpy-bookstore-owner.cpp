class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // using sliding window
        int n = customers.size();
        int CurrUnsatCus = 0;
        int MaxUnsatCus = 0;
        for (int i = 0; i < minutes; i++) {
            CurrUnsatCus += customers[i] * grumpy[i];
        }
        MaxUnsatCus = CurrUnsatCus;
        int j = minutes;
        int i = 0;
        while (j < n) {
            CurrUnsatCus += customers[j] * grumpy[j];
            CurrUnsatCus -= customers[i] * grumpy[i];
            MaxUnsatCus = max(MaxUnsatCus, CurrUnsatCus);
            i++;
            j++;
        }
        int totalSatCust = MaxUnsatCus;
        for (int i = 0; i < n; i++) {
            if(grumpy[i]==0){
            totalSatCust  += customers[i] ;
            }
        }
        return totalSatCust ;
    }
};