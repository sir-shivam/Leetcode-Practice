
class SegTree{
    public:




    struct Node{
        char leftChar , rightChar;
        int prefix , suffix , len , best ;

        Node(){
            leftChar = rightChar = '#';
            prefix = suffix = len = best = 0 ;
        }

        Node(char ch ){
            leftChar = rightChar = ch ;
            prefix = suffix = len = best = 1;
        }
    };

    string s ;
    vector<Node * > tree;


    SegTree(int n , string s ){
        tree.resize( 4*n +1 );
        this -> s = s ;

        build(1 , 0 , n-1);
    }   

    Node * merge( Node* L , Node* R ){

        if(L -> len == 0 ){
            return R ;
        }
        if(R -> len == 0 ){
            return L ;
        }

        Node* res = new Node();

        res -> len = L -> len + R -> len ;

        res -> leftChar = L -> leftChar ;
        res -> rightChar = R -> rightChar ;

        res -> suffix = R  -> suffix ;
        res -> prefix = L -> prefix ;

        res -> best = max(L -> best , R -> best);

        if(L-> rightChar == R -> leftChar ){
            res -> best = max( res -> best , L -> suffix + R -> prefix );

            if( L -> prefix == L -> len ){
                res -> prefix = L -> len + R -> prefix ;
            }

            if( R -> suffix == R -> len ){
                res -> suffix = R -> len + L -> suffix;
            }
        }

        return res;

    }

    void build( int node , int l , int r  ){

        if( l == r ){
            tree[node] =new  Node(s[l]);
            return ;
        }

        int mid = ( l + r ) / 2;

        build( 2* node , l , mid);

        build( 2* node +1 , mid +1 , r );

        tree[node] = merge(tree[2* node] , tree[2*node +1] );

    }

    void update(int node , int l , int r , int idx , char ch){
        if(l == r ){
            tree[node] = new Node(ch);
            return ;
        }

        int mid = ( l + r) / 2;

        if( idx <= mid ){
        update(2 * node , l , mid , idx , ch );
        }else{
            update( 2 * node + 1 , mid +1 , r , idx , ch );
        }

        tree[node] = merge( tree[2* node] , tree[2  * node +1 ]);

    }

};

class Solution {
public:
    vector<int> longestRepeating(string s, string query, vector<int>& qIdx) {
        

        int n = s.size();

        SegTree seg( n , s );

        int m = query.size();
        vector<int> ans;


        for(int i = 0 ;i < m ; i++){

            int idx = qIdx[i];
            char ch = query[i];

            seg.update(1 , 0 , n-1 , idx , ch );

            ans.push_back(seg.tree[1] -> best);
        }

        return ans;

    }
};