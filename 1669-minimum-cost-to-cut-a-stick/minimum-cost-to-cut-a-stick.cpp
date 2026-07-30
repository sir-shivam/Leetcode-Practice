class Solution {

    int help( int i , int j , vector<int> & cuts , vector<vector<int>>  & dp){

        if( i + 1 == j  ){
            return 0 ;
        }

        // cut at k 
        int mini = INT_MAX;

        if( dp[i][j] != -1) return dp[i][j];

        for( int k = i+1 ; k < j ; k++){
            int price =  ( cuts[j] - cuts[i] ) +  help( i , k , cuts , dp ) + help( k , j , cuts , dp);

            mini = min( mini ,price);
        }

        return dp[i][j] =  mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort( cuts.begin() , cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp( m , vector<int> ( m , -1));

        return help( 0 , m-1 , cuts , dp);
        
    }
};