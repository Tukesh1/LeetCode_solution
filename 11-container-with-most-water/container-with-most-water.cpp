class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointer 
        int start =0 ;
        int area =0;
        int end = height.size()-1;
        while(start <= end){
            int h= min(height[start], height[end]);
            int width = end - start;
            int ar =h* width;
            area = max(ar,area);
            if(height[start] < height[end]){
               start++;
            }
            else{
                end--;
            }
        }
        return area;
    }
};