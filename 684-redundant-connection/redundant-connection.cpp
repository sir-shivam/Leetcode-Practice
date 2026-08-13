
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


    bool unite( int x , int y ){
        int u = find( x);
        int v = find( y );

        if( u == v ) return true;

        if( sz[u] >= sz[v]){
            par[v]  =  u  ;

            sz[u] += sz[v]; 
        }else{
            par[u] = v ;

            sz[v] += sz[u];
        }
        return false;
    }
    
};
class Solution {

    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        DisJoinSet dsu(n );

        for(auto & ed : edges){
            int u = ed[0];
            int v = ed[1];

            if(dsu.unite(u , v )){
                return {u , v };
            }


        }

        return {};

    }
};