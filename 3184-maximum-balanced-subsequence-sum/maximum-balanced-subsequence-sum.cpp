
class FenWick{

    public:

    int n ;
    vector<long long > bit;

    FenWick( int n ){
        this -> n = n ;

        bit.resize(n +1 , LLONG_MIN);
    }

    void add(int idx , long long  val){

        while(idx <= n ){
            bit[idx] = max( bit[idx] , val );

            idx += idx & -idx;
        }
    }

    long long  query( int idx ){
        long long ans = LLONG_MIN ;

        while( idx > 0 ){
            ans =  max(ans ,  bit[idx] );

            idx -= ( idx & -idx);
        }

        return ans;
    }
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {

        
        int n = nums.size();
        vector<long long > key( n );

        for( int i = 0 ; i < n ; i++){
            key[i] = 1LL * nums[i] - i ;
        }


        vector<int> arr(n);

        vector<long long> nums1 = key;

        sort(nums1.begin() , nums1.end());

        nums1.erase(unique(nums1.begin() , nums1.end()) , nums1.end());

        int m = nums1.size();

        FenWick fenTree( m );
        long long ans = LLONG_MIN;

        for( int i = 0 ; i < n ; i++){
            int idx = lower_bound( nums1.begin() , nums1.end() , key[i]) - nums1.begin() +1;

            long long best = fenTree.query( idx);

            long long dp = nums[i];

            if( best != LLONG_MIN){
                dp = max( dp , nums[i] + best);
            }

            ans = max( ans , dp );

            fenTree.add(idx , dp);
        }

        return ans;

    }
};