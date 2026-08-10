class Solution {

    map<int , int> mpp;

    map<int , map<int , int>> dp;
    int n ;

    bool help( int i , long long  k ,  vector<int>& stones ){

        // k-1 steps 

        if( i == n-1 ) return 1;
        if(dp.count(i) && dp[i].count(k) ) return dp[i][k];
        for( long long m = -1 ; m <= 1 ; m++){
            if( k + m  == 0 ) continue;
            if(mpp.count(stones[i]+ k+m)){

                if(mpp[stones[i]+k+m] == n-1){
                    return dp[i][k] =  true;
                }

                if(help( mpp[stones[i]+k+m] , k+m , stones )){
                    return dp[i][k] =  true;
                };
            }
        }

        return  dp[i][k] =  false;;


    }
public:
    bool canCross(vector<int>& stones) {
        
        n = stones.size();
        if( stones[1] != 1) return false;

        // vector<vector<int>> dp( n , vector<int> ( stones[n-1] , -1));

        for( int i = 0 ;i < n ; i++){
            mpp[stones[i]] = i ;
        }

        return help( 1 , 1 , stones );
    }
};