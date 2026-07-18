class Solution {
public:
    int mySqrt(int x) {
        
        int l = 0 ;
        int r = x;

        int ans = 1;

        while( l <= r ){
            int mid = l + ( r - l ) / 2;

            long long  q = 1LL * mid * mid;

            if( q < x){
                ans = mid ;

                l = mid +1;
            }else if(q > x) {
                r =  mid - 1;
            }else{

                return mid;
            }

            
        }

        return ans;
    }
};