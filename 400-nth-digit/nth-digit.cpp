class Solution {
public:
    int findNthDigit(int n) {

        long long dig = 1;
        long long start = 1 ;
        long long count = 9;

        while( n > dig * count){
            n -= dig * count ;
            dig ++;

            start *= 10 ;
            count *= 10 ;
        } 

        long long num = start + ( n-1 ) / dig;

        int idx = ( n-1 ) % dig ;

        string s = to_string(num);

        return s[idx] - '0';

        return 0 ;
        
    }
};