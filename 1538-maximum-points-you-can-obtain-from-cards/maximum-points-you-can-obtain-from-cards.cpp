class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();

        vector<long long > pref( n , 0 );

        pref[0] = cardPoints[0];
        long long ans  = 0 ;


        for( int i = 1 ; i < n ; i++){
            pref[i] = pref[i-1] + cardPoints[i];
        }
        if( k == n ) return pref[n-1];

        long long total = pref[n-1];

        int m = n - k ;

        int i = m-1 ,  j = 0 ;
        
        while( i < n   ){
            
            ans = max( ans , total - ( pref[i] - (j == 0 ? 0 :  pref[j-1])));
            
            i++;
            j ++;
        }


        return ans;



    }
};