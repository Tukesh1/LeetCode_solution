class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i <= sqrt(n) ;i++){
            if (n % i == 0 )
                return false;
        }

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        for (int i = left; i <= right; i++) {
            if (isPrime(i) == true) {
                prime.push_back(i);
                cout << i << " ";
            }
        }
        int size = prime.size();
        if (size <= 1) {
            return {-1, -1};
        }
        //prieme=  5,7,11,13,17,19
        vector<int>ans(2,0);
        int diff= INT_MAX;
        for(int i=0 ;i<size-1;i++){
            int curDiff = prime[i+1]-prime[i];
            if(curDiff < diff){
                diff = curDiff;
                ans[0]= prime[i];
                ans[1]=prime[i+1];
            }
        }
        return ans;
    }
};