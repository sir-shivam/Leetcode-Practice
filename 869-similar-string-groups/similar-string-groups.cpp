class Solution {

        vector<int> par;
    int find( int x  ){
            if( par[x] == x){
                return x;
            }
            return par[x] = find(par[x]);
        }

    bool check( string & s , string & t ){

        if(s == t ) return true;

        int n = s.size();

        int cnt = 0 ;
        for( int i = 0 ; i < n ; i++){
            if(s[i] != t[i]){
                cnt ++;
            }
        }

        return cnt == 2 ;
    }


public:
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        par.resize(n );

        for( int i = 0 ; i < n ; i++){
            par[i] = i ;
        }

        

        for( int i = 0 ; i < n ; i++){
            for( int j = i+1 ; j < n ; j++){
                if(check( strs[i] , strs[j])){
                    par[find(j)] = find(i);
                }
            }
        }


        int cnt = 0 ;
        for( int i = 0 ; i < n ; i ++){
            
            if(  i == find(par[i])){
                cnt ++;
            }
        }

        return cnt ;
    }
};