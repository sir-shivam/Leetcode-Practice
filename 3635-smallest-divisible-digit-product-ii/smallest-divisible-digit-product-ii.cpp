class Solution {
public:

    using ll = long long;

    string fill(ll req, int len) {

        string s;

        for (int d = 9; d >= 2; d--) {

            while (req % d == 0) {
                s.push_back(char('0' + d));
                req /= d;
            }
        }

        while ((int)s.size() < len) {
            s.push_back('1');
        }

        reverse(s.begin(), s.end());

        return s;
    }

    string smallestNumber(string num, long long t) {

        int n = num.size();

        ll x = t;

        for (int p : {2, 3, 5, 7}) {

            while (x % p == 0) {
                x /= p;
            }
        }

        if (x != 1) {
            return "-1";
        }

        vector<ll> rem(n + 1, t);

        for (int i = 0; i < n; i++) {

            int d = num[i] - '0';

            if (d == 0) {
                break;
            }

            rem[i + 1] = rem[i] / gcd(rem[i], (ll)d);
        }

        if (rem[n] == 1) {
            return num;
        }

        int zero = num.find('0');

        int last = n - 1;

        if (zero != string::npos) {
            last = zero;
        }

        for (int i = last; i >= 0; i--) {

            ll req = rem[i];

            int slots = n - i - 1;

            for (int d = (num[i] - '0') + 1; d <= 9; d++) {

                ll need = req / gcd(req, (ll)d);

                string suffix = fill(need, slots);

                if ((int)suffix.size() == slots) {

                    return num.substr(0, i)
                         + char('0' + d)
                         + suffix;
                }
            }
        }

        return fill(t, n + 1);
    }
};