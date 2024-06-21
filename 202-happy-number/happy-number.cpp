class Solution {
private:
   // Function to find the sum of squares of digits of a number
   int sqsum(int num) {
       int sum = 0;
       while (num) {
           int digit = num % 10;
           sum += digit * digit;
           num /= 10;
       }
       return sum;
   }

public:
   bool isHappy(int n) {
       int num = n;
       unordered_set<int> map;
       
       // Loop to check if the number is happy or not
       while (num != 1) {
           if (map.count(num) && !map.empty()) {  // Check if number is already in the set
               return false;  // Cycle detected, not a happy number
           }
           map.insert(num);  // Insert the number into the set
           num = sqsum(num); // Calculate the sum of squares of digits
       }
       
       return true;  // Number is happy (converged to 1)
   }
};