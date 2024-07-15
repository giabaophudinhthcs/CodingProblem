#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define len length

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int nMax = 1e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int t, n, a[nMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		FOR(x, 1, n) cin >> a[x];
		if (n == 1){
			cout << ((a[1] != 1) ? "Hieu\n" : "RR\n");
			continue;
		}
		int c1, c2;
		c1 = max(a[1], a[2]);
		c2 = min(a[1], a[2]);
		FOR(x, 3, n){
			if (a[x] > c1){
				c2 = c1;
				c1 = a[x];
			}else if (a[x] > c2) c2 = a[x];
		}
		cout << ((c1 - c2 == 1 && n % 2 == c1 % 2) ? "RR\n" : "Hieu\n");
	}
	return 0;
}
