class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        long long count = 0 ;

        map<int , int> mpp;

        mpp[0] = 1;

        long long sum = 0 ;


        for( int i = 0 ; i < n ; i++){
            sum += nums[i];

            int rem =  sum - k ;

            if( mpp.count(rem)){
                count += mpp[rem];
            }


            mpp[sum] ++;
        }

        return count ;
    }
};