class DisJointset{

    public:

    vector<int> sz;
    vector<int> par;

    DisJointset(int n ){
        sz.resize(n+ 1 , 1  );

        par.resize(n+1 );

        for( int i = 0 ; i < n ; i++){
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
            par[v] = u ;
            sz[v] += sz[u];
        }

    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = 0 ;
        int m = 0 ;

        for( auto & st : stones){
            n = max( n , st[0]);
            m = max( m , st[1]);
        }

        DisJointset dsu(n + m + 2 );
        map<int , int> mpp;


        for( auto & st : stones){
            int u = st[0];
            int v = st[1];

            int row = u ;
            int col = v + n + 1;

            dsu.connect( row , col);

            mpp[row] = 1;
            mpp[col] = 1;
        }

        int cnt = 0 ;
        for(auto & [a , b ] : mpp){
            if(dsu.find(a) == a){
                cnt ++;
            }
        }

        int st = stones.size();

        return st - cnt ;



    }
};