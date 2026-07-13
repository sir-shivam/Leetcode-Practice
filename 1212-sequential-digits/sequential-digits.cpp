class Solution {

    int adder;
    long long  create(int n){
        long long  num = 0  ;
        adder = 0 ;
        int dig = 1;
        while(n){
            num = num * 10 + dig;
            dig ++;
            adder = adder * 10 + 1;
            n--;
        }

        return num;

    }
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        int n = to_string(low).size();
        int m = to_string(high).size();

        int len = n ;
        while(len <= m  ){
            long long  num = create(len);
            if(num >= low && num <= high){
                ans.push_back(num);
            }

            while(num % 10 != 9 ){
                num  += adder;

                if( num >= low && num <= high){
                    ans.push_back(num);
                }
            }

            len ++;
        }

        return ans;
    }
};