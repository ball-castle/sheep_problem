#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--) {
        ll n, c0 = 0, c1 = 0;
        cin >> n;

        while(n--) {
            string s;
            cin >> s;
            
            bool f = 0;
            for(ll i = 0; i < 4; i++) {
                if(s.substr(i, 3) == "xxx") f = 1;
            }

            if(f) {c1 ^= 1; continue;}

            for(ll i = 0; i < 5; i++) {
                if(s.substr(i, 2) == "xx") f = 1;;
            }

            if(f) {c0 ^= 1; continue;}

        }
        cout << ((c0 | c1) ?  "Monocarp" : "Polycarp") << '\n';
    }

    return 0;
}