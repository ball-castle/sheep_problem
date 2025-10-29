#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> ans(n);

    if(n == 1) {
        cout << "? 1 1" << endl;
        ll k;
        cin >> k;
        ans[0].resize(k);
        for(auto &x : ans[0]) cin >> x;
    }
    else{
        for(ll i = 0; i < n; i += n / 2) { // address odd and even
            vector<ll> idx;
            for(ll j = i; j < i + n / 2 && j < n; j++) {
                idx.push_back(j + 1);
                idx.push_back(j + 1);
            }  
            ll k = idx.size() / 2;
            cout << "?" << " " << idx.size();
            for(auto &x : idx) cout << " " << x;
            cout << endl;
            
            ll m;
            cin >> m;
            vector<ll> res(m);
            for(auto &x : res) cin >> x;

            ll pt = 0;
            for(ll j = i; j < i + k; j++) {
                ll npt = pt + 1;
                while(res[npt] != res[pt]) npt++;
                for(ll k = pt; k < npt; k++) ans[j].push_back(res[k]);
                pt = 2 * npt - pt;
            }
        }
    }

    cout << "!";
    for(auto &x : ans) {
        cout << " " << x.size();
        for(auto &y : x) cout << " " << y;
    }

    return 0;
}