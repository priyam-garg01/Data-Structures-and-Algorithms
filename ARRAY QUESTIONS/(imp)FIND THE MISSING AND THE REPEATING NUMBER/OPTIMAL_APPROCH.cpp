/*Find the sum od first n and numbers along with its square
2.Find sum aray elements along with sum of squares 
subtract both and solve on paper that it reults to what
3.You will find what x-y and x+y by certain operations
after that add them and subtract them to find x and y(missing and dual elem)



*/

class Solution {
public:
// T.C. = O(N); S.C. = O(1);
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        long long dualElem;
        long long missingElem;
        vector<int> vec;
        long long suma = 0;
        long long sumsqa = 0;

        long long sum = 1LL * n*(n+1)/2;
        long long sumsq = 1LL * n*(n+1)*(2*n+1)/6;

        for(int i = 0; i <n; i++){
            suma += nums[i];
            sumsqa += 1LL * nums[i]*nums[i];
        }

        long long diff1 = sum - suma;//missing - dualElem

        long long diff2 = sumsq - sumsqa;//missing^2 - dual^2

        long long summa = diff2/diff1;//missing + dual
        long long diff = diff1;

        missingElem = (summa+diff)/2;

        dualElem = (summa - diff)/2;

        vec.push_back(dualElem);
        vec.push_back(missingElem);
        return vec;
    }
};