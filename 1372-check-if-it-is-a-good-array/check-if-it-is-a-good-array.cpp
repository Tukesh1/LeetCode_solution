class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
         int g = nums[0];
        for(auto i:nums){
            g = __gcd(g,i);
        }
        if(g==1) return true;
        else return false;
    }
};