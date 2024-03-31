class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // lest_then pivot  ........... pivot ............greater then pivot ......

        vector<int>left_pivot;
        int i =0,count =0 ;
        int size= nums.size();
        while(i <size){
            if(nums[i] < pivot){
                left_pivot.push_back(nums[i]);
            }
            if(nums[i] == pivot) count++;
            i++;
        }

        vector<int>right_pivot;
        int k=0;
          while(k <size){
            if(nums[k] > pivot){
                right_pivot.push_back(nums[k]);
            }
            k++;
        }
        while(count--){
            left_pivot.push_back(pivot);
        }
        int rs= right_pivot.size();
        int j =0 ;
        while(j<rs){
            left_pivot.push_back(right_pivot[j]);
            j++;
        }

        return left_pivot;

    }
};