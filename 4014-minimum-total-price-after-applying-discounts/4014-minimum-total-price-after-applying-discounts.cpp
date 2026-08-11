class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        double sum = 0;
        int m = min(prices.size(), discounts.size());

        for (int i = 0; i < m; i++) {
            sum += prices[i] * (100 - discounts[i]) / 100.0;
        }

        for (int i = m; i < prices.size(); i++) {
            sum += prices[i];
        }

        return sum;
    }
};