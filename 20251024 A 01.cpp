#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (auto &s: grid) cin >> s;

	int total = 0;
	for (auto &s: grid) {
		for (auto &c: s) {
			total += (c == '#');
		}
	}

	vector<vector<int>> tmp(n, vector<int>(m, 0));
	for (int i = min(n, m); i > 0; i --) {
		if (total % (i * i) == 0) {

			for (int x = 0; x < n; x ++) {
				for (int y = 0; y < m; y ++) {
					if (grid[x][y] == '#') {
						tmp[x][y] = 1;
					}
				}
			}

			bool flg = true;
			for (int x = 0; x < n; x ++) {
				for (int y = 0; y < m; y ++) {
					if (tmp[x][y]) {
						for (int dx = x; dx < x + i; dx ++) {
							for (int dy = y; dy < y + i; dy ++) {
								if (dx >= n || dy >= m || !tmp[dx][dy]) {
									flg = false;
									break;
								}
								tmp[dx][dy] = 0;
							}
							if (!flg) break;
						}
						if (!flg) break;
					}
				}
				if (!flg) break;
			}

			if (flg) return cout << i, 0;
		}
	}

	return 0;
}