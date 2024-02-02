class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int len = log10(low) + 1, k = 1;
        long long num = 0, adder = 0;
        
        for(int i=len-1; i>=0; i--){
            num += k*pow(10, i);
            adder += pow(10, i);
            k++;
            if(k == 10) return {};
        }
        
        long long temp = num;
        while(temp < low){
            temp += adder;
            if(temp < low && temp%10 == 9){
                if(k == 10) return {};
                num *= 10;
                num += k;
                adder *= 10;
                adder ++;
                k++;
                temp = num;
            }
        }
        
        vector<int> ans;
        while(temp <= high){
            if(temp%10 == 9){
                if(temp <= high) ans.push_back(temp);
                if(k == 10) return ans;
                num *= 10;
                num += k;
                adder *= 10;
                adder ++;
                k++;
                temp = num;
            }
            else{
                ans.push_back(temp);
                temp += adder;
            }
        }
        
        return ans;
    }
};