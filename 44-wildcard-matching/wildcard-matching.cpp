class Solution {

    bool help( int i , int j ,  string & s, string &  p , vector<vector<int>> &  dp){

        if( i == s.size() &&  j == p.size()){
            return  true;

        }

        if(i == s.size()){
            while(j < p.size() && p[j] == '*') j ++;
            if( j == p.size()){
                return true;
            }
            return false;
        }

        if( j == p.size() ){
            return false;
        }
        if( dp[i][j] != -1) return dp[i][j];

        if(p[j] == s[i]){
            return dp[i][j] =  help( i +1 , j+1 , s , p , dp );
        }else{
            if( p[j] == '?'){
                return dp[i][j] =  help( i +1 , j+1 , s , p , dp );
            }else if(p[j] == '*') {
                return dp[i][j] =  help( i+1 , j , s , p , dp) || help( i  , j+1 , s , p , dp );
            }
        }

        return false;

    }
public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp( n , vector<int> ( m , -1));
        return help( 0 , 0 , s , p , dp );
    }
};