class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> sol(n);
        for(int i=0;i<n;i++){
            int sum =0;
            for(int j=0;j<n;j++){
                if(boxes[j]=='1'){
                    //2, 4,5 
                    sum+= abs(i-j);
                }
            }
            sol[i]= sum;
        }
        return sol;
    }
};