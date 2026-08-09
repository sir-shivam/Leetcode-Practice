class DisJoinSet{

    public:

    vector<int> par , sz;
    int n ;
    DisJoinSet(int n ){
        this -> n = n ;

        par.resize( n +1 );

        for( int i= 0 ; i <= n ; i++){
            par[i] = i ;
        }

        sz.resize(n+1 , 1);

    }

    int find( int x ){
        if( par[x] == x ) return x;

        return par[x] = find(par[x]);
    }

    void unite(int x , int y ){
        int u = find( x);
        int v = find(y );
        if(  v < u ){
            swap( u , v );
        }

        if( u == v ) return ;

        par[v] = u ;
    }



};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        DisJoinSet dsu(26 );

        int n = s1.size();
        int m = baseStr.size();
        for(int i = 0 ;i < n ; i++ ){
            dsu.unite(s1[i] - 'a' , s2[i] -'a');
        }

        string ans = "";
        for( int i = 0 ; i < m ; i++){
            ans += dsu.find(baseStr[i] - 'a') + 'a';
        }

        return ans;
    }
};