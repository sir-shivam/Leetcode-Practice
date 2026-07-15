class Solution {

    long long gcd(long long a , long long b ){
        while( a > 0 &&  b > 0 ){
            if(b > a ){
                swap( a, b );

            }
                a %= b ;

        }
            return a >0 ? a : b ;
    }
public:
    int gcdOfOddEvenSums(int n) {
        

        long long sumOdd = (( 2 + (n -1 ) * 2 ) / 2 ) * n ;

        long long sumEven = (( 2 * 2 + (n -1 ) * 2 ) / 2 ) * n ;

        return gcd( sumOdd , sumEven);
    }
};