class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin() , prices.end() , greater<>());

        sort(discounts.begin() , discounts.end(), greater<>());

        int n = prices.size();

        double ans = 0 ;

        int m = discounts.size();
        int j = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            ans+= ((prices[i] * ( 100 - ( j >=  m ? 0 :discounts[j])))/100.0 );
            j++;
        }

        return ans;
    }
};