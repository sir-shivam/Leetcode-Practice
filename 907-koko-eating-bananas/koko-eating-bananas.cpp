class Solution {

    long long  check( int mid , vector<int> & piles){
        
        long long  ans = 0 ;
        for( auto & x : piles ){
            ans += ( (long long )x + mid -1) / mid;
        }

        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort( piles.begin() , piles.end());

        int l = 1;
        int r = *max_element(piles.begin() , piles.end());

        int ans = r ;

        while( l <= r){
            int mid = l + ( r - l) / 2;


            if( check(mid , piles) <= h){
                ans = mid ;
                r = mid - 1;
            }else{
                l = mid +1 ;
            }
        }

        return ans;
    }
};