class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.size();
        int m = goal.size();

        if( n != m ) return false;

        if(s == goal ) return true;

        s = s + s ;

        int j = 0 ;
        for(int i = 0 ; i < n* 2 ; i ++){
            int l = i ;
            while( l < 2* n && j < m &&  s[l] == goal[j]){
                j++;
                l ++;
            }
            if( j == m ) return true;
            else j = 0 ;
        }

        return false;

    }
};