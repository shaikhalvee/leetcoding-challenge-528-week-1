#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void print (vi);
int maxProfit (vi&);

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
    vi trace;
    trace.assign(prices.size(), -1);
    trace[trace.size()-1] = 0;



    return 0;
}
