#include <bits/stdc++.h>

using namespace std;

void solve() {
    int ans = 0, N;

    cin >> N;

    int v[N];

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, i = 1;
    cin >> t;

    while (t--) {
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
    return 0;
}