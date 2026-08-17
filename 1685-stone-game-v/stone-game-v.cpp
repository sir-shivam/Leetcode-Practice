class Solution {


public:
    int stoneGameV(vector<int>& stone) {
        

        int n = stone.size();

        vector<long long > pref(n , 0LL );

        vector<vector<long long>> dp( n , vector<long long > ( n , -1) );


        auto  help = [&]( auto && help,   int i , int j , vector<long long> & pref) -> long long{

        if( i == j ) return 0 ;

        if(dp[i][j] != -1) return dp[i][j];

        long long ans = 0 ;

        for( int k = i ; k < j ; k++){
            
            // check for score and then decide of descarding 
            long long left = pref[k] - ( i == 0 ? 0 :  pref[i-1]);

            long long right = pref[j] - pref[k];

            if( left == right ){
                // left throw left 
                long long ch1 = right +  help(  help , k+1 , j , pref);
                // lets throw right 
                long long ch2 = left + help( help ,  i , k , pref);

                ans = max({ans , ch1 , ch2}); 
            }else if( left < right ){
                  
                   ans = max( ans ,  left +  help( help , i , k , pref));

            }else{
                ans = max(ans , right + help(help , k+1 , j , pref));
            }
                
            }

            return dp[i][j] =  ans;


        };
        pref[0] = stone[0];
        for( int i = 1 ; i < n ; i++){
            pref[i] += pref[i-1] + stone[i];
        }

        return help(help ,0 , n-1 , pref);

        
    }
};