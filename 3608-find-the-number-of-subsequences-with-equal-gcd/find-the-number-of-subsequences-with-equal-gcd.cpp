class Solution {


    int const MOD = 1e9 + 7 ;

    int gcd(int a , int b ){
        // if( a == -1 ) return b ;
        while( a > 0 && b > 0 ){
            if( a > b ){
                a %= b ;
            }else{
                b %= a; 
            }
        }

        return a == 0 ? b : a ;
    }

    int n ;

    vector<vector<vector<long long>>> dp;

    long long help( int i , int gcd1 , int gcd2  , vector<int>& nums  )
    {

        if( i == n ){
            if( gcd1 == 0 || gcd2 == 0) return 0;
            if(gcd1 == gcd2 ) return 1;
            return 0 ; 
        }

        if(  dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];
        // skip 
        long long skip = help( i+1 , gcd1 , gcd2 , nums);

        // put in 1 
    
        long long take1 =  help( i + 1 , gcd( gcd1 , nums[i]) , gcd2 , nums );

        long long take2 = help( i+1 , gcd1 , gcd(gcd2 , nums[i]) , nums);

        return dp[i][gcd1][gcd2] =  (((skip + take1 ) % MOD ) + take2 ) % MOD;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();

        dp.resize(n , vector<vector<long long>> ( 201 , vector<long long> ( 201 , -1)));
        return help( 0 , 0 , 0 , nums);
    }
};