class Solution {

    // let build segment tree

    const int MOD = 1e9 + 7;

    struct Node {
        long long val;
        int cnt ;
        long long sum;

        Node(){
            val = 0;
            cnt = 0;
            sum = 0;
        }
    };

    vector<Node> seg;
    vector<long long> pow10;
    int n ;

    Node merge(Node & a , Node & b){
        Node res;
        res.cnt = a.cnt + b.cnt;
        res.sum = ( a.sum + b.sum) % MOD;
        res.val = (a.val * pow10[b.cnt] % MOD + b.val)% MOD;
        return res;
    }

    void build(int idx , int l , int r , string const &s){
        if( l== r){
            if( s[l] != '0'){
                seg[idx].val = s[l] - '0';
                seg[idx].cnt = 1;
                seg[idx].sum = s[l] - '0';
            }
            return ;
        }

        int mid = ( l + r ) / 2;

        build(idx*2 , l , mid , s );
        build(idx * 2 +1 , mid +1 , r , s );
        seg[idx] = merge(seg[idx*2] , seg[idx*2 +1]);

    }

     Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return Node();
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) / 2;
        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
    

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        n = s.size();
        seg.assign(4 * n, Node());

        // precompute powers of 10
        pow10.resize(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        build(1, 0, n - 1, s);

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            Node res = query(1, 0, n - 1, l, r);
            long long cur = (res.val * res.sum) % MOD;
            ans.push_back((int)cur);
        }
        return ans;
    }
};