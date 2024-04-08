class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cirular_cd = 0;
        int square_cd =0 ;
        for(int choice : students){
            if(choice == 0){
               cirular_cd++; 
            }
            if(choice == 1){
              square_cd++;  
            }
        }
        for(int sandwich :sandwiches){
            if(sandwich == 0 && cirular_cd == 0 ){
                return square_cd;
            }
            if(sandwich == 1 && square_cd == 0 ){
                return cirular_cd;
            }
            if(sandwich == 0 ){
                cirular_cd--;
            }
            else{
                square_cd--;
            }
        }
        return 0;

    }
};