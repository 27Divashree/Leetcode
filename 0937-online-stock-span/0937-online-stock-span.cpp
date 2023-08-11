class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int curPrice = price;
        int curSpan = 1;

        while(stack.size() && stack.back().first<=price)
        {
            auto[prevPrice,prevSpan] = stack.back();
            stack.pop_back();
            curSpan += prevSpan;
        }

        stack.push_back(pair<int,int>{curPrice,curSpan});

        return curSpan;
    }

    private:
    vector<pair<int,int>> stack;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */