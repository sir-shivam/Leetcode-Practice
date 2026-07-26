class Solution {
public:
    int largestInteger(int n, int s) {

        if( s > 9 * n ) return -1;

        int ans = 0 ;

        while(s >= 9   && n > 0  ){
            ans = ans * 10 + 9 ;
            s -= 9 ;
            n--;
        }


        if( s > 0 ){
            ans = ans * 10 + s;
            s = 0 ;
            n--;
        }

        while( n ){
            ans = ans * 10 ;
            n --;
        }

        return ans;

        
        
    }
};