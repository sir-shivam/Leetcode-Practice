class DisJointSet{

    public:

    vector<int> sz;

    vector<int> par;



    int n ;

    DisJointSet(int n ){
        sz.resize(n +1 , 1 );
        par.resize( n +1);

        for( int i = 0 ; i < n ; i++){
            par[i] = i ;
        }
    }

    int find(int x){
        if( par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool unite(int x , int y ){
        int u = find(x);
        int v = find(y);

        if( u == v ) return true;

        if(sz[u] >= sz[v]){
            par[v] = u ;
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
    int makeConnected(int n, vector<vector<int>>& con) {
        

        int cnt = 0 ;

        vector<int> vis( n , 0 );
        DisJointSet disJoin( n );


        for(auto & ed : con){
            int u = ed[0];
            int v = ed[1];

            vis[u] = 1;
            vis[v] = 1;

            if(disJoin.unite(u , v )){
                cnt ++;
            }
        }

        int ans = 0 ;

        for( int i = 0 ; i  < n ; i++){
            if( (disJoin.find(i) == i) ){
                ans ++;
            }
        }

        if( cnt >= ans  -1   ) return  ans -1;

        return -1; 


    }
};