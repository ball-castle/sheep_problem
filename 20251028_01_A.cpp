#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << -1 << ' ' << 2 << '\n';
	cout << 0 << ' ' << 2 << '\n';
	cout << n - 1 << ' ' << 1 << '\n';
	cout << n << ' ' << 0 << '\n';
	cout << n - 1 << ' ' << 0 << '\n';
	cout << 0 << ' ' << 1 << '\n';

	return 0;
}