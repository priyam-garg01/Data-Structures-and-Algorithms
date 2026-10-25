/*We are given an array asteroids of integers representing asteroids in a row. The indices of the 
asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction 
(positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 destroys -1. Since 2 and 4 are both moving right, they never collide.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        //we can loop through the array and store the incoming positives in st1 and incoming negatives in st2;
        stack<int> st;        
        vector<int> ans;
        // for(int i = n-1; i >= 0; i--){This wont work as the positions are being changed by this which changes the collisions of asteroids}
       for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            st.push(arr[i]);
        }
        //Collision only occurs when st.top is positive and arr[i is negative]
        else {//if a negative element occurs
            while(!st.empty() && st.top() > 0 && st.top() < (-1)*arr[i]){
                    st.pop();

                }
                if(!st.empty() && st.top() == (-1)*arr[i]){
                    st.pop();
                }
//only in two cases the element enters stack if stack has a negative element and if st is empty after the prev condition
                else if(st.empty() || st.top() < 0){
                    st.push(arr[i]);
                }
            }
            
        }
       

        while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        for(int i = 0; i < ans.size()/2; i++){
            swap(ans[i], ans[ans.size()-i-1]);
        }   
    
        return ans;     
    }
};/*T.C. = O(N) + O(N) FOR STACK OPERATIONS + O(N/2) {We can use a list and use operations like st.back()  to access the back element like in stack and st.pop_back() as list is a last in first out type of DS
T.C. = O(5N/2), S.C = O(N)*/