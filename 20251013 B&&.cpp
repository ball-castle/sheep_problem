#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n;
// simplify the fomula
// i - 1 - (n - i)     // i - (n - 1 - i)


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<ll> p(n), q(n);
	for(auto &x : p) cin >> x;
	for(auto &x : q) cin >> x;
	auto solve = [&](vector<ll> nums) -> ll {
		ll mi = *min_element(nums.begin(), nums.end());
		ll ma = *max_element(nums.begin(), nums.end());
		vector<ll> cnt(ma - mi + 1);
		for(auto x : nums) cnt[x - mi]++;
		vector<ll> tmp;
		for(ll i = 0; i <= ma - mi; i++) 
			while(cnt[i]--) tmp.push_back(i);
		ll ans = 0;
		for(ll i = 0; i < n; i++) ans += 2 * (2 * i - n + 1) * tmp[i];
		return ans;
	};
	ll ans = solve(p) + solve(q); 
	vector<ll> a(n);
	for(ll i = 0; i < n; i++) a[i] = p[i] - q[i];
	ans -= solve(a) / 2;
	for(ll i = 0; i < n; i++) a[i] = p[i] + q[i];
	ans -= solve(a) / 2;
	cout << ans << '\n';
	return 0;
}
