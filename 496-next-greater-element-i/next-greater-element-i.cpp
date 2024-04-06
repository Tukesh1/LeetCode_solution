class Solution {
public:
    int checkNextGreater(int num,int start,vector<int>arr){
      for(int i = start ;i< arr.size();i++){
        if(arr[i] > num){
            return arr[i];
        }
      }
      return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        vector<int>ans;
        for(int i =0 ;i< nums1.size();i++){
            for(int j = 0 ;j< nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    int it = checkNextGreater(nums1[i] , j ,nums2);
                   ans.push_back(it); 
                }
            }
        }
        return ans;
    }
};