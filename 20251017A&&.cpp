#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	set<ll> vis;
	vis.insert(0);
	
	ll bound = 1e9;
	auto dfs = [&] (auto &self, ll x, ll y, ll cur) -> void {
		if(cur > bound) return;
		vis.insert(cur);
		self(self, x, y, 10 * cur + x);
		self(self, x, y, 10 * cur + y);
	};   // dfs out condition  call itself
	for(ll i = 1; i < 10; i++) 
		for(ll j = 0; j < 10; j++) dfs(dfs, i, j, i);
	ll n;
	cin >> n;
	ll ans = 0;
	for(auto &x : vis) if(vis.count(n - x)) ans++; // hash 
	cout << (ans + 1) / 2;
	return 0;
	
	
	
} 
