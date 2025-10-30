#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

// easy construction  sort 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> idx1, idx2;



    for(ll i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        if(a < b) idx1.push_back(i);
        else idx2.push_back(i);          
    }

    cout << "YES\n";

    if(idx1.size() > idx2.size()) {
        cout << idx1.size() << "\n";
        for(auto &x : idx1) cout << x << " ";
    } 
    else {
        cout << idx2.size() << "\n";
        for(auto &x : idx2) cout << x << " ";
    }

    return 0;
}