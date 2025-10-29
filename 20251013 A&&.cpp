#include <bits/stdc++.h>
#define ll long long 
using namespace std;
// think from the last
ll n;
ll a[500010];
const int mod = 1e9 + 7;



void solve() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
	ll pos = 1, mx = 0, ans = 1;
	for(ll i = 1; i <= n; i++) {
		if(mx < a[i]) {
			mx = a[i];
			ans += (ans * (i - pos)) % mod;
			pos = i;
			ans %= mod;
		}
	}
	printf("%lld\n", ans);
}






int main() {
	ll t = 1;
//	scanf("%lld", &t);
	while(t--) {
		solve();
	}
	return 0;
}
