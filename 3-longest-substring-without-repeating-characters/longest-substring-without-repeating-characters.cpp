class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int j = 0 ;
        map<int , int> mpp;

        int ans = 0 ;

        for( int i = 0 ; i < n; i ++){
            mpp[s[i]] ++;

            while( j <= i &&  mpp.size() < i - j + 1  ){
                mpp[s[j]] --;
                if( mpp[s[j]] == 0 ){
                    mpp.erase(s[j]);
                }
                j ++;
            }

            if( mpp.size() == i - j +1 ){
                ans = max( ans , i - j +1);
            }
        }

        return ans;
    }
};