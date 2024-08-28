class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*
         2 3 4 7 11
         1 5 6 8 9 10 12...
        */
      for(int i=0 ;i<arr.size();i++){
        if(arr[i]<=k)k++;
        else break;
      }
      return k;


    }
};