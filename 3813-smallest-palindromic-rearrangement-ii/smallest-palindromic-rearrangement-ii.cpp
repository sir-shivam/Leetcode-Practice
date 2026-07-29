using ll = long long;

class Solution {

    vector<ll> fact;


    static const int LIM = 1000000;

    ll C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        ll ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIM) return LIM + 1;
        }

        return ans;
    }

    ll ways(vector<int>& cnt) {
        ll ans = 1;
        int rem = 0;

        for (int x : cnt) {
            if (x == 0) continue;

            ans *= C(rem + x, x);

            if (ans > LIM) ans = LIM + 1;

            rem += x;
        }

        return ans;
    }

public:
    string smallestPalindrome(string s, int k) {
        
        fact.resize(41);

        fact[0] = 1;

        for (int i = 1; i <= 20; i++)
            fact[i] = fact[i - 1] * i;

        
        vector<int> freq( 26 , 0 );

        for( auto & ch : s){
            freq[ch-'a'] ++;
        }

        vector<int> half(26 , 0 );

        int cnt = 0 ;
        string ans = "";
        string mid = "";

        int len = 0 ;
        for( int i = 0 ; i < 26 ; i++){
            half[i] = freq[i] / 2;

            len += half[i];

            if(freq[i] & 1 ){
                mid += ( i + 'a');
            }

        }


        if(ways(half) < k ) return "";

        string first = "";

        for( int pos = 0 ; pos < len ; pos++){
            for( int c = 0 ;c < 26 ; c++){
                if( half[c] == 0 ) continue;

                half[c] --;

                ll cnt = ways(half);

                if( cnt >= k ){
                    first += c + 'a';
                    break;
                }

                k -= cnt ;
                half[c] ++;
            }
        }


        string second = first ;


        reverse(second.begin() , second.end());

        return first + mid + second;
        // return ans;
    }
};