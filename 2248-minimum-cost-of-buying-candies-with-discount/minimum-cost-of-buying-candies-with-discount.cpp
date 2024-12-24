class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int min_cost =0;
        //  9 7 6 5 2 2 -> 
        int count =0;
        sort(cost.begin(), cost.end(), greater<>());
        for(int i=0;i<cost.size();i++){
            if(count ==2){
                count =0;
            }else{
            min_cost += cost[i];
            count++;
            }
        }
      
        return min_cost;
    }
};