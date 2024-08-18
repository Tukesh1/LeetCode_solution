class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
         vector<int> res(nums.size()-k+1 , -1);
        int score =0 ;
        for(int i=0;i<nums.size();i++){
            if(i && nums[i-1]+1 == nums[i]){
                // both are cons
                score++;
            }
            else{
                score=0;
            }
            if(i>=k-1 && score >=k-1){
                res[i-k+1] = nums[i];
            }
        }
        return res;

    }
};