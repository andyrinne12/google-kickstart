#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K, P;
    int d[50][1501];
    memset(d, 0xc0, sizeof(d));

    int sums[30][50];

    cin >> N >> K >> P;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            if (j == 0) {
                sums[i][j] = x;
            } else {
                sums[i][j] = sums[i][j - 1] + x;
            }
        }
    }

    for (int j = 0; j < N; j++) {
        for (int k = K; k >= 1; k--) {
            for (int i = P; i >= 1; i--) {
                if (k > i) {
                    break;
                }
                if (j == 0) {
                    d[j][i] = max(d[j][i], sums[j][k - 1]);
                    continue;
                }
                d[j][i] = max(d[j][i], max(d[j - 1][i - k] + sums[j][k - 1], d[j - 1][i]));
            }
        }
    }

    cout << d[N - 1][P] << '\n';
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