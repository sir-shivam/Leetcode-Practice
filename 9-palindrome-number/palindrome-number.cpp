class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 ) return false;

        int x1 = x;
        long long rev = 0 ;

        while(x > 0 ){
            rev = ( rev * 10 ) + ( x % 10 );

            x /= 10 ;
        }

        cout << rev ;

        return (int)rev == x1; 
    }
};