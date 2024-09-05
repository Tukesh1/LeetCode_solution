class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n =height.size() ;
        int area = 0;
        int i=0, j=n-1;
        while(i<=j){
            int h=min(height[i],height[j]);
            int width = j-i;
            int ar = h* width;
            area = max(ar, area);
            if(height[i]> height[j]){ // shift j towards i
                  j--;
            }else{
                i++;
            }
        }
        return area;

    }
};