class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i =0 ;i< nums.size();i++){
                mp[nums[i]]++ ;
        }
        int count =0 ;
        for(auto a:mp){
            int t = a.second;
            if(t==1) return -1; //If any number occurs only once in nums, it's impossible to achieve the desired pattern, so the function returns -1.


            count += t/3; //It calculates the number of moves needed to make all occurrences of each number a multiple of 3. If there are remaining occurrences (not divisible by 3), it adds one more move for each such occurrence.
            if(t%3) count++ ;
        }
        return count ;
    }
};