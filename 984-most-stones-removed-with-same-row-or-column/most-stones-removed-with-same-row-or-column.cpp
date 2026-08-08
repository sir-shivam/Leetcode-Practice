class DisJointSet{
    public:

    int n ;
    vector<int> par , sz ;

    DisJointSet(int n ){
        this -> n = n ;

        par.resize( n +1 );

        sz.resize(n+1 , 1);

        for( int i = 0 ; i < n ;i ++){
            par[i] = i ;
        }
    }


    int find( int x ){
        if( par[x] == x ) return x ;
        return par[x] = find(par[x]);
    }

    void unite(int x , int y ){
        int u = find( x );
        int v = find( y);

        if( u == v ) return ;

        if(sz[u] >= sz[v]){
            par[v] = u ;
            sz[u] += sz[v];
        }else{
            par[u] = v ;
            sz[v] += sz[u];
        }
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = 0 ;
        int m = 0 ;

        for(auto & st : stones){
            n = max( n, st[0] +1 );
            m = max(m , st[1] +1 );
        }

        DisJointSet dsu( n +  m + 20 );
         unordered_set<int> used;

        for( auto & st : stones){
            int row = st[0];
            int col = st[1] + n  ;

            dsu.unite(row , col);
            used.insert(row);
            used.insert(col);
        }

        int cnt = 0 ;


        for(auto & a : used){
            if(dsu.find(a) == a) cnt++;
        }

        return stones.size() - cnt ;



    }
};