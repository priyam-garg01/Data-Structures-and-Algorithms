/*
1. take xor of both 1 to n and elements of array
2. value will give us something that you will calc
3.We will then check the bit which is set in the value
and initiate the place to bitnum
4. Then we take two parts o club and 1 club
where we will store(by xoring)elements whose bit at bitnum
is one or zero at the found but number
5.We will also xor with i = 1 to n so that after xoring of doubles
get zero we get our required elements
6.To further check we will run a loop to check count of zero in it
if it is zero then zero is missing and one is dual element
if cnt= 2 then one is misiing and one is dual element

T.C. = O(N) + O(N)*3
BUT THE SECOND LAST AND THIRD LAST LOOP CAN BE COMBINED BY CHECKING IF(i+1
 & (1<<bitnum) == 0 then zero club else one
 T.C. = O(3N)
 S.C. = O(1)
*/





class Solution {
public:
// T.C. = O(N); S.C. = O(1);
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        int dualElem;
        int missingElem;
        vector<int> vec;
        int value = 0;
        int Xora = 0;
        int Xor = 0;
        for(int i = 1; i <= n; i++){
            Xor ^= i
        }
        for(int i = 0; i < n; i++){
            Xora ^= nums[i]; 
        }

        value = Xora^Xor;//missing element ^ dualElem

        //bit manipulation: to find which bit is set or is 1 in val
        //Also found by   : bitnum = [value & ~(value-1)]

        int bitnum = 0;

        while(1){
            if(value & (1<<bitnum) != 0){
                break;
            }
            bitnum++;
        }

        //sieving the elements of array into oth part and 1 part i.e. which parts have 1 or 0 at their respective bitnum

        int zero = 0;
        int one = 0;
        for(int i = 0; i < n; i++){
            //part of 1 club
            if(nums[i] & (1 << bitnum) != 0){
                one = one ^ a[i];
            }
            //part of 0 club
            else//(nums[i] & (1 << bitnum) == 0)
            {
                zero = zero ^ a[i];
            }
        }
//to xor with number 1 to n
        for(int i = 1; i < n; i++){
            //part of 1 club
            if(i & (1 << bitnum) != 0){
                one ^= i;
            }
            else
                zero ^= i;
        }
//here one and zero are missing and dual numbers

//to check which is dual and which is missing check count of dual
int count = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == zero)count++
    }
    if(count == 2)return{zero, one};
    else return{one, zero};


        missingElem = value

        vec.push_back(dualElem);
        vec.push_back(missingElem);
        return vec;
    }
};