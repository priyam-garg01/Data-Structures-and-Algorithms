class Solution {
public:


    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;//store the (n-1)! to divide it from k to know the index of first char
        for(int i = 1; i < n; i++){
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(n);//complete the nums vec to store all int
        k = k - 1;//as the solution is based on zero indexing we need to decrement 1 to get the correct index of chars after dividing fact
        string ans;
        while(true){
            ans.push_back(nums[k/fact] + '0');//this + '0' converts the int to char
            //character pushed who's permutations contain that kth seq or permutation
            nums.erase(nums.begin() + k/fact);
            // {entering the index adding to the initial index removes that index char[in short the element at index[k/fact] gets removed]}//by putting the char in list we shorten the list to arrange othere chars
        if(nums.size() == 0){//the vec is empty means we have got our reqd permut
            break;
        }
            k = k % fact;//same doing for next char we need to observe the seq index ocurring in changed nums

            fact = fact/nums.size();//since the size of nums is dcreased to n-1 we need to change our fact to n-2
        }
        return ans;
        
    }
};/*OPTIMAL APPROACH:
Mathematical sol 
T.C. = O(N) + O(N), S.C. = O(N)*/