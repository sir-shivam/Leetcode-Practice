class Solution {
public:
    int numberOfSubstrings(string s) {
        

        int n = s.size();

        map< char , int> mpp;

        int ans = 0 ;

        int j = 0 ;

        for( int i = 0 ; i < n ; i++){
            mpp[s[i]] ++;

            while( j <= i && mpp.size() == 3 ){
                ans += n - i ;
                mpp[s[j]] --;
                if( mpp[s[j]] == 0 ){
                    mpp.erase(s[j]);
                }
                j++;
            }
        }

        return ans;
    }
};