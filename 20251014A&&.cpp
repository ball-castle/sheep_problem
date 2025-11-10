#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, M = 1e6;
	
}
	vector<ll> xs(n), ys(n), vs(n);
	for(ll i = 0; i < n; i++) cin >> xs[i] >> ys[i] >> vs[i];
	auto solve = [&] () -> ll {
		vector<ll> cnt(M + 1, 0);
		for(ll i = 0; i < n; i++) cnt[ys[i]] += vs[i];  // some line
		vector<ll> order(M + 1);
		for(ll i = 0; i < M + 1; i++) order[i] = i;
		sort(order.begin(), order.end(), [&] (ll i, ll j) {return cnt[i] > cnt[j];}); 
		ll ans = cnt[order[0]] + cnt[order[1]] + cnt[order[2]];
		map<ll, vector<ll>> mp;
		for(ll i = 0; i < n; i++) mp[xs[i]].push_back(i);
		for(auto &[k, v] : mp) {
			ll cur = 0; 
			for(auto &idx : v) cur += vs[idx];
			cnt[ys[idx]] -= vs[idx];
		}
		
		ll 
	}
