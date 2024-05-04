class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        // 3 2 2 1 => 1 2 2 3
        int cnt =0 ;
        int j = people.size()-1;
        int i =0 ;     
        while(i<= j){
            if((people[i] + people[j]) <= limit ){
                i++;
            }
            j--;
            cnt++;
        }
        return cnt;
    }
};