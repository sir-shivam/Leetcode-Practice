class Solution {
public:
    long long sumAndMultiply(int n) {

        long long sum = 0;
        long long x = 0;
        int i = 1;
        while(n){
            int t = n % 10;
            n /= 10;
            if( t == 0) continue;
            sum += t;
            x = t *i + x;
            i *= 10;

        }

        cout << x << " " << sum;

        return x * sum;
        
    }
};