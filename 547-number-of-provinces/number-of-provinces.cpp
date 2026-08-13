
class DisJoinSet{

    public:
    vector<int> par;
    vector<int> sz;

    DisJoinSet(int n ){

        par.resize(n +1 );
        sz.resize( n+1 , 1 );

        for( int i = 0 ; i <= n ; i++){
            par[i] = i ;
        }
    }

    int find( int x ){

        if( par[x] == x ) return x;

        return par[x] = find(par[x]);
    }


    void unite( int x , int y ){
        int u = find( x);
        int v = find( y );

        if( u == v ) return;

        if( sz[u] >= sz[v]){
            par[v]  =  u  ;

            sz[u] += sz[v]; 
        }else{
            par[u] = v ;

            sz[v] += sz[u];
        }
    }
    
};

class Solution {



    // lets try with dsu
public:
    int findCircleNum(vector<vector<int>>& con) {
        
        int n = con.size();
        int m = con[0].size();

        DisJoinSet dsu( n );
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if(con[i][j] == 1 ){
                    dsu.unite(i , j );
                }
            }
        }

        int cnt = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(dsu.par[i] == i){
                cnt ++;
            }
        }

        return cnt ;
    }
};