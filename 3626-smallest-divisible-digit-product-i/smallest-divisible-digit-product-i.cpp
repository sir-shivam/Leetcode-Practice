class Solution {

    int dig( int n ){

        int mul = 1;

        while( n ){
            int t = n % 10 ;
            mul *= t ;
            n /= 10;
        }

        return mul;
    }
public:
    int smallestNumber(int n, int t) {
        
        for( int i = n ; i <= 100 ; i++){
            if(dig(i) % t == 0 ){
                return i ;
            }
        }

        return n;
    }
};