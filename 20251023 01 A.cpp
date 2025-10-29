#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;

    ll k1 = n / 2, k2 = n - k1;
    vector<ll> v1(k1), v2(k2);

    for(ll i = 0; i < k1; i++) {
        ll m, t;
        cin >> m >> t;
        m *= b;
        t *= b;
        v1[i] = m - t / b * a;
    }

    for(ll i = 0; i < k2; i++) {
        ll m, t;
        cin >> m >> t;
        m *= b;
        t *= b;
        v2[i] = m - t / b * a;
    }

    map<ll, ll> mp;

    auto dfs1 = [&] (auto &self, ll idx, ll val) -> void {
        if(idx == k1) {mp[val]++; return;}
        self(self, idx + 1, val + v1[idx]);
        self(self, idx + 1, val);
    };

    dfs1(dfs1, 0, 0);

    ll ans = 0;

    auto dfs2 = [&] (auto &self, ll idx, ll val) -> void {
        if(idx == k2) {
            if(mp.count(-val)) {
                ans += mp[-val];
            }
            return;
        }
        self(self, idx + 1, val + v2[idx]);
        self(self, idx + 1, val);
    };

    dfs2(dfs2, 0, 0);

    cout << ans << "\n";
    return 0;
}    