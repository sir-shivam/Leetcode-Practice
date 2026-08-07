class DisJointSet{

    public:

    vector<int> sz , par , sum;
    int n ;

    DisJointSet(int n ){
        this -> n = n ;

        sz.resize(n+1 , 1 );

        par.resize(n+1);

        sum.resize(n+1 , 0 );

        for( int i = 0 ; i <= n ; i++){
            par[i] = i ;
        }
    }

    int find( int x){
        if( par[x] == x ) return x;

        int p = par[x];
        par[x] = find(par[x]);
        sum[x] ^= sum[p];
        return par[x];
    }

    bool add(int a , int b , int w ){
        int t = ( sum[a] ^ sum[b]);
        return (t ^ w ) == 0 ;
    }

    bool unite(int a , int b  , int w ){
        int u = find(a);
        int v = find(b);

        if( u == v ) return true;

        int x = sum[a] ^ sum[b] ^ w ;

        if( sz[u] >= sz[v]){

            sum[v] = x;
            par[v] = u ;
            sz[u] += sz[v];
        }else{
        
            sum[u] = x;
            par[u] = v ;
            sz[v] += sz[u];
        }

        return false;
    }
};

class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        
        DisJointSet dsu( n +1 );

        int ans = 0 ;
        for(auto & ed: edges){
            int u = ed[0];
            int v = ed[1];
            int w = ed[2];

            if(dsu.unite( u , v  , w)){
                if(dsu.add(u , v  , w)){
                    ans ++;
                }
            }else{
                ans ++;
            }
        }

        return ans;
    }
};