class DisJointset{

    public:

    vector<int> sz;
    vector<int> par;

    DisJointset(int n ){
        sz.resize(n+ 1 , 1  );

        par.resize(n+1 );

        for( int i = 0 ; i <= n ; i++){
            par[i] =  i ;
        }
    }


    int find( int x ){
        if(par[x] == x) return x ;

        return par[x] = find( par[x]); 
    }

    void connect( int x , int y  ){
        
        int u = find( x );
        int v = find( y );

        if( u == v ) return ;

        if( sz[u] >= sz[v]){
            par[v] = u ;
            sz[u]+= sz[v];
        }else{
            par[u] = v ;
            sz[v] += sz[u];
        }

    }
};


class Solution {

    vector<pair<int , int>> dir = { { 0 , 1 } , { 1 , 0 } , { -1 , 0 } , { 0 , -1 }};
public:
    int largestIsland(vector<vector<int>>& grid) {

        int ans = 0 ;
        
        int n = grid.size();
        int m = grid[0].size();

        DisJointset dsu( n * m +1 );

        for( int i= 0 ; i < n ;i++){
            for( int j = 0 ; j < m ; j ++){
                if( grid[i][j] == 0 ) continue;
                

            for( auto & [x , y ]: dir ){
                int ix = i + x ;
                int jx = j + y ;

                if(ix >= 0 && ix < n && jx >= 0 && jx < m && grid[ix][jx]){
                    int curr = i * n + j ;
                    int nxt = ix * n + jx;

                    dsu.connect( curr , nxt );
                }
            }
                
            }
        }

        for( int i =0 ; i < n ; i++){
            for( int j = 0 ; j < m ;j ++){
                if( grid[i][j] ) continue;

                set<int> spp;

                for( auto & [ x , y ] : dir)
                {
                    int ix = i + x;
                    int jx = j + y ;

                    if( ix >= 0 && ix < n && jx >= 0 && jx < m  && grid[ix][jx]){
                        spp.insert(dsu.find(ix * n + jx));
                    }

                }

                int maxi = 1;

                for(auto & a : spp){
                    maxi += dsu.sz[a];
                }

                ans = max( ans , maxi );
            }
        }
        for(int cell = 0 ;cell < n*n ; cell++ ){
            ans  = max(ans , dsu.sz[dsu.find(cell)]);
        }

        return ans;
    }
};