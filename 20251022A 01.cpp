#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> pts;

    if(n & 1) {
        pts.push_back({0, 0});

        ll x = 0, y = 0;

        for(ll i = 0; i < n / 2 - 1; i++) {
            y += 25;
            pts.push_back({x, y});
            x += 25;
            pts.push_back({x, y});
        }

        x = max(x, 25ll);
        pts.push_back({x, 0});
        pts.push_back({x / 25 * 9, -x / 25 * 12});
    }
    else {
        pts.push_back({0, 0});

        ll x = 0, y = 0;
        for(ll i = 0; i < n / 2 - 1; i++) {
            y += 25;
            pts.push_back({x, y});
            x += 25;
            pts.push_back({x, y});
        }

        pts.push_back({x, 0});
    }

    ll dx = 5, dy = 12;

    for(auto &[x, y] : pts) {
        cout << x * dx + y * dy << " " << x * (-dy) + y * dx << "\n";
    }
    return 0;
}