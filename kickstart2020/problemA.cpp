#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int ans = 0;
    int N, B;
    vector<int> prices;

    cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        prices.push_back(p);
    }

    sort(prices.begin(), prices.end());

    int i = 0;

    while (B && i < prices.size())
    {
        if (B < prices[i])
        {
            break;
        }
        B -= prices[i];
        ans++;
        i++;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, i = 1;
    cin >> t;

    while (t--)
    {
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
    return 0;
}