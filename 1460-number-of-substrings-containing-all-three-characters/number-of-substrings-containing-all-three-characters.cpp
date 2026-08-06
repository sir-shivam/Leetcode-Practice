class Solution {
public:
    int numberOfSubstrings(string s) {
        

        int n = s.size();

        // map< char , int> mpp;
        vector<int> mpp( 3 , 0 );

        int ans = 0 ;

        int j = 0 ;

        for( int i = 0 ; i < n ; i++){
            mpp[s[i] - 'a'] ++;

            while( j <= i && ( mpp[0] > 0 && mpp[1] > 0 && mpp[2] >  0 ) ){
                ans += n - i ;
                mpp[s[j] -'a'] --;
                j++;
            }
        }

        return ans;
    }
};