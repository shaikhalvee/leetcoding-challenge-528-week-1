#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

void print (vi);
int maxProfit_2_pointer(int[], size_t);
int maxProfit_single_pass(vi &);

int main() {
    size_t input;
    vi prices;
    while (scanf("%u", &input) == 1) {
        prices.assign(input, -1);
        for (size_t i = 0; i < input; i++) {
            scanf("%d", &prices[i]);
        }
        printf("%d\n", maxProfit_single_pass(prices));
    }
    return 0;
}

void print (vi ara) {
    for (size_t i = 0; i < ara.size(); i++) {
        printf("%d", ara[i]);
        if (i != ara.size()) printf(" ");
    }
    printf("\n");
}

int maxProfit_2_pointer(int prices[], size_t pricesLen) {
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int maxprofit = 0;
    while (i < pricesLen - 1) {
        while (i < pricesLen - 1 && prices[i] >= prices[i + 1])
            i++;
        valley = prices[i];
        while (i < pricesLen - 1 && prices[i] <= prices[i + 1])
            i++;
        peak = prices[i];
        maxprofit += peak - valley;
    }
    return maxprofit;
}

int maxProfit_single_pass(vi &prices) {
    int max_profit = 0;
    for (size_t i = 0; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1])
            max_profit += prices[i] - prices[i - 1];
    }
    return max_profit;
}
