class StockSpanner {
    vector<int> prices;

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        for (int i = (int)prices.size() - 1; i >= 0; i--) {
            if (prices[i] <= price) {
                span++;
            } else {
                break;
            }
        }

        prices.push_back(price);
        return span;
    }
};