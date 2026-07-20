class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        long long  Xor = 0 ;
        for( int i = 0 ; i < n ; i ++){
            Xor ^= nums[i];
        }

        // find first set bit 
        int first = ( Xor & (- Xor));
        int val1 = 0 ;
        int val2= 0;

        for(int i = 0 ; i < n ; i++){
            if( nums[i] & first){
                val1 ^= nums[i];
            }else{
                val2 ^= nums[i];
            }
        }

        return { val1 , val2};

    }
};