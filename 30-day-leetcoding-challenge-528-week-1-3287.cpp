#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void print (vi);
int maxProfit (vi&);
void customAlgo(vi &, std::size_t, vi &);

int main()
{
    ios_base::sync_with_stdio(0);

    size_t len;
    vi prices;
    int val;
    cin >> len;
    for (size_t i = 0; i < len; i++)
        cin >> val, prices.push_back(val);
    cout << maxProfit(prices);
    return 0;
}

void print (vi ara) {
    for (size_t i = 0; i < ara.size(); i++)
        cout << ara[i], (i != ara.size() - 1) ? cout << " " : cout << "";
    cout << "\n";
}

int maxProfit (vi & prices) {
    if (prices.size() <= 1) return 0;
    vector<int> trace;
	trace.assign(prices.size(), -1);
    trace[trace.size() - 1] = 0;
    customAlgo(prices, prices.size() - 2, trace);
    return *max_element(trace.begin(), trace.end());
}

void customAlgo(vi &prices, std::size_t currPos, vi &traceVector) {
    if (currPos == -1) return;
	int old_price = 0;
	for (std::size_t i = currPos + 1; i < prices.size(); i++) {
		if (prices[currPos] > prices[i]) {
			continue;
		}
		int new_price = prices[i] - prices[currPos] + *max_element(traceVector.begin() + i, traceVector.end());
		if (old_price < new_price) swap(old_price, new_price);
	}
	if (traceVector[currPos] == -1) traceVector[currPos] = old_price;
	customAlgo(prices, currPos - 1, traceVector);
}
