class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n = seats.size();
        vector<int> dis1( n , 0 ) , dis2( n , 0 );

        int prev = -1 ;

        for( int i = 0 ; i < n ; i ++){
            if(seats[i]){
                prev = i ;
            }else{
                dis1[i] = prev ;
            }
        } 
        
        prev = n ;
        for( int i = n-1 ; i >= 0 ; i--){
            if(seats[i]){
                prev = i ;
            }else{
                dis2[i] = prev ;
            }
        }

        int ans = 0 ;

        for(int i = 0 ; i < n ;i ++){
            if( seats[i]) continue;
            int t = n;
            if(dis1[i] != -1){
                t = min( t , i - dis1[i]);
            }
            if(dis2[i] != n){
                t = min( t , dis2[i] -  i );
            }

            ans = max( t , ans);
        }

        return ans ;
    }
};