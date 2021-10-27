#include <bits/stdc++.h>

using namespace std;

void precalc(int facts[], int N) {
    facts[0] = 0;
    facts[1] = 0;
    facts[2] = 1;
    for (int i = 3; i <= N; i++) {
        facts[i] = facts[i - 1] + log2(i);
    }
}

void solve(int facts[]) {
    int W, H, L, U, R, D;

    cin >> W >> H;

    cin >> L >> U >> R >> D;
    L--;
    U--;
    R--;
    D--;

    int lb[] = {L, D};
    int rt[] = {R, U};

    double ans = 0;

    if (D < H - 1 && L > 0) {
        int n = L + D;
        int k = L - 1;
        int expp = facts[n] - facts[k] - facts[n - k] - n;
        double prob = pow(2, expp);
        int greens = min(L - 1, H - D - 1) + 1;
        if (L - 1 > H - D - 1) {
            greens--;
            // ans += pow(2, -(H - 1));
            // int expp2 = facts[n - 1] - facts[k - 1] - facts[n - k - 2] - n;
            // ans += pow(2, expp2);
        }
        for (int i = 0; i < greens; i++) {
            ans += prob;
            cout << ans << '\n';
        }
        cout << "LB\n";
    }

    if (R < W - 1 && U > 0) {
        int n = R + U;
        int k = U - 1;
        int expp = facts[n] - facts[k] - facts[n - k] - n;
        double prob = pow(2, expp);

        int greens = min(U - 1, W - R - 1) + 1;
        cout << n << ' ' << k << ' ' << expp << ' ' << prob << ' ' << greens << '\n';

        if (U - 1 > W - R - 1) {
            greens--;
            ans += pow(2, -(W - 1));
            int expp2 = facts[n - 1] - facts[k - 1] - facts[n - k - 2] - n;
            ans += pow(2, expp2);
        }
        for (int i = 0; i < greens; i++) {
            ans += prob;
        }
        cout << "TR\n";
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int facts[200002];
    precalc(facts, 200000);

    int t, i = 1;
    cin >> t;

    while (t--) {
        cout << "Case #" << i << ": ";
        solve(facts);
        i++;
    }
    return 0;
}