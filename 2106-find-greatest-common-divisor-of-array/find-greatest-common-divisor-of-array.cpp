class Solution {

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
public:
    int findGCD(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());

        
        return gcd(nums[0] , nums.back());
    }
};