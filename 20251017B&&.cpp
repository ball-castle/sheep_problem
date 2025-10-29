#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	
	vector<vector<ll>> grid(n, vector<ll>(n));
	for(auto &x : grid) 
		for(auto &y : x) cin >> y;
	
	vector<vector<ll>> u = grid, d = grid, l = grid, r = grid;
	for(ll i = 1; i < n; i++) 
		for(ll j = 0; j < n; j++) if(u[i][j]) u[i][j] = u[i - 1][j] + 1;
	
	for(ll i = n - 2; i >= 0; i--) 
		for(ll j = 0; j < n; j++) if(d[i][j]) d[i][j] = d[i + 1][j] + 1;
		
	for(ll i = 0; i < n; i++) 
		for(ll j = 0; j < n; j++) if(l[i][j]) l[i][j] = l[i][j - 1] + 1;

	for(ll i = 0; i < n; i++) 
		for(ll j = n - 2; j >= 0; j--) if(r[i][j]) r[i][j] = r[i][j + 1] + 1;
	
	auto solve = [&] (ll x, ll y) -> ll {
		vector<ll> v1, v2;
		while(x < n && y < n) {
			v1.push_back(min(d[x][y], r[x][y]) - 1);
			v2.push_back(min(u[x][y], l[x][y]) - 1);
			x++, y++;
		}
	int k = v1.size(), ans = 0;

	atcoder::fenwick_tree<int> fen(k + 1);
	vector<vector<int>> tmp(k + 1);

	for(ll i = 0; i < k; i ++)
		tmp[i - v2[i]].emplace_back(i);
		
	for(int i = 0; i < k; i ++) {
		for (auto &j: tmp[i]) fen.add(j, 1);
		ans += fen.sum(0, i + v1[i] + 1);
	}	
	return ans - k * (k - 1) / 2;

	};
	
	ll res = solve(0, 0);
	for(ll i = 1; i < n; i++) res += solve(0, i) + solve(i, 0);
	cout << res;
	return 0

	
};
