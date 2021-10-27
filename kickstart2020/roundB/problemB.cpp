#include <bits/stdc++.h>

using namespace std;

void solve() {
    long N, D;

    cin >> N >> D;

    long ans = D;
    long v[N];

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        long mult = (ans / v[i]) * v[i];
        ans = min(ans, mult);
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
#include <bits/stdc++.h>

using namespace std;

void solve() {
    long N, D;

    cin >> N >> D;

    long ans = D;
    long v[N];

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        long mult = (ans / v[i]) * v[i];
        ans = min(ans, mult);
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