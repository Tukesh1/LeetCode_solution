class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int product=1;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
                product*=nums[i];
            else
                count++;
        }
        if(count==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0)
                    ans[i]=product;
            }
        }else if(count>=2)
        {
            return ans;
        }
        else{
            for(int i=0;i<n;i++){
                ans[i]=product/nums[i];
            }
        }
        
        return ans;
    }
};