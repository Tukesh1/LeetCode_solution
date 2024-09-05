class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // heap sort have time complexity of O(nlog(n))
         // 1.heapyfy
          sort(nums.begin(), nums.end());
          return nums;
       
    }
};