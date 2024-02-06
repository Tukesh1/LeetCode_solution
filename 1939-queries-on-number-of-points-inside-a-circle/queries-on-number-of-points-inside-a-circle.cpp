class Solution {
public:
bool point_inside(int x1 ,int x2 ,int y1,int y2,int r){
    int dis= pow(x2 - x1 ,2)+ pow(y2-y1,2);
    if(dis > r*r) return false;
    return true;
}
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>total_point ;
        // using the formula 
        // (x-x1)2 + (y-y1)2 = r2
        for(int i =0 ;i<queries.size();i++){
           int count = 0;
            for (int j = 0; j < points.size(); j++)
            {
                if (point_inside(points[j][0], queries[i][0], points[j][1], queries[i][1], queries[i][2])) count++;
            }
            total_point.push_back(count); 
        }
        return total_point;
    }
};