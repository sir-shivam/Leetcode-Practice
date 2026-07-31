class Solution {

     bool isPall(int i , int j , string & s){
        while(i < j ){
            if(s[i++] != s[j--]){
                return false;
            }
        }
            return true;
    }


    int help( int i , int j , string& s , vector<vector<int>> &  dp){

        if( i >= j || isPall( i , j , s)   ){
            return 0 ;
        }
        if( dp[i][j] != -1) return dp[i][j];
        
        int tot = 1e9 ;
        for( int k = i ; k < j ; k ++){

            // cut here 
            if(isPall(i , k  , s )){
               int  cut = 1 + help( k+1 , j , s , dp);
                tot = min( cut , tot );
            }
        }

        return dp[i][j] =  tot;
    }
public:
    int minCut(string s) {
        
        int n = s.size();

        vector<vector<int>> dp( n , vector<int> ( n , -1 ));

        return help( 0 , n-1 , s , dp);

    }
};