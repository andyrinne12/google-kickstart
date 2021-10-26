#include <bits/stdc++.h>

using namespace std;

int compute(int val, vector<int> levels) {
    int ans = 0;
    for (auto& level : levels) {
        float lvl = level;
        lvl /= val;
        int k = ceil(lvl) - 1;
        ans += k;
    }
    return ans;
}

int bs(int K, int left, int right, vector<int> levels) {
    if (left < right) {
        int mid = (left + right) >> 1;
        int ksum = compute(mid, levels);
        if (ksum > K) {
            return bs(K, mid + 1, right, levels);
        } else {
            return bs(K, left, mid, levels);
        }
    }
    return left;
}

void solve() {
    int ans = 0;
    int N, K;

    cin >> N >> K;
    vector<int> levels;

    int x, y;
    cin >> x;
    for (int i = 1; i < N; i++) {
        cin >> y;
        levels.push_back(y - x);
        x = y;
    }

    if (N == 2 && K == 1) {
        levels.push_back(0);
    }

    sort(levels.begin(), levels.end(), greater<int>());

    if (K == 1) {
        cout << max(levels[1], (levels[0] + 1) / 2) << '\n';
        return;
    }

    ans = bs(K, 1, levels[0], levels);

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