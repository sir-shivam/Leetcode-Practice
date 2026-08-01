class Solution {
public:
    int countValidPrefixes(string s) {

        int cnt1 = 0 ;
        int cnt2 = 0 ;

        int n = s.size();

        int ans = 0 ;

        for( int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                cnt1 ++;
            }else{
                cnt2 ++;
            }

            if(cnt1 == cnt2 || (cnt1 +1 == cnt2 ) || ( cnt2 + 1 == cnt1)){
                ans ++;
            }
        }

        return ans;
    }
};