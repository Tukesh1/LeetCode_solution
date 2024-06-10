class Solution {
public:
    int heightChecker(vector<int>& heights) {

       int cnt =0;
       vector<int>temp = heights;
       sort(temp.begin(), temp.end());

      //sort and compare 
       for(int i =0 ;i<heights.size();i++){
        if(temp[i]!= heights[i])cnt++;
       }
       return cnt;
    }
};