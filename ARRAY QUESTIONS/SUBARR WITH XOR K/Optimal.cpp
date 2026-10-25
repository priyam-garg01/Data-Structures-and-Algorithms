class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        map<int,int> mpp;
        int count = 0;
        int x;
        int Xor = 0;
        mpp[Xor] = 1;
        for(int i = 0 ; i < n; i++){
            Xor ^= nums[i];
            //pehle ke kuch elements ka xor  x^k = Xor--> x^k^k = Xor^k
            // just like preSum in count subarraysWithsumk
            x = Xor^k;
            count += mpp[x];
            mpp[Xor]++;
        }
        return count;
        }
};