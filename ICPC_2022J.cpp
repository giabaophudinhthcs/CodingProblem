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

int t, n, m, a[mMax][mMax], r[mMax], c[mMax];

void Input(){
	cin >> n >> m;
	FOR(x, 1, n){
		FOR(y, 1, m) cin >> a[x][y];
	}
}

void Solve(){
	int R = 0, C = 0;
	FOR(x, 1, n){
		int cur = a[x][1], ok = 1;
		FOR(y, 2, m) ok &= (cur == a[x][y]);
		R += ok;
	}
	
	FOR(y, 1, m){
		int cur = a[1][y], ok = 1;
		FOR(x, 2, n) ok &= (cur == a[x][y]);
		C += ok;
	}
	cout << R * C << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		Input();
		Solve();
	}
	return 0;
}
