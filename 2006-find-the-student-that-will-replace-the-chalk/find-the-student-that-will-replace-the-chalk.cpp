class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // replace chal pice
        int len = chalk.size();
        long long int sum =0 ;
        for(int i: chalk){
            sum +=i;
        }
        cout<<sum;
        k = k%sum ;
        for(int i =0;i<len;i++){
            if(k < chalk[i]){
               return i;
            }
            else  k -=chalk[i];
        }
        return 0;
    }
};