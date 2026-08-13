class Solution {
public:
    int nthUglyNumber(int n) {

        priority_queue<long long,
                       vector<long long>,
                       greater<long long>> pq;

        set<long long> st;

        pq.push(1);
        st.insert(1);

        int cnt = 0;
        long long node = 1;

        while (cnt < n) {

             node = pq.top();
            pq.pop();

            cnt++;

            long long a = node * 2;
            long long b = node * 3;
            long long c = node * 5;

            if (!st.count(a)) {
                st.insert(a);
                pq.push(a);
            }

            if (!st.count(b)) {
                st.insert(b);
                pq.push(b);
            }

            if (!st.count(c)) {
                st.insert(c);
                pq.push(c);
            }
        }

        return node;
    }
};