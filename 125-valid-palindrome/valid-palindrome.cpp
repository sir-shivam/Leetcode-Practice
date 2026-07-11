class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();


        string t = "";

        for( int i = 0 ; i < n ; i++){
            if((s[i] >= 'a' && s[i] <= 'z')  || ( s[i] >= '0' && s[i] <= '9')){
                t += s[i];
            }else if(s[i] >= 'A' && s[i] <= 'Z' ){
                t += ( (s[i] - 'A' )+ 'a');
            }
        }

        // cout << t << endl;
        int m = t.size();
        int i = 0 ; int j = m-1;

        while( i < j ){
            if( t[i] != t[j]){
                return false;
            }
            i ++;
            j--;
        }

        return true;
    }
};