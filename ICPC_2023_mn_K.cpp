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

int n, a[nMax], l[nMax], r[nMax], res = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n) cin >> a[x];
	
	l[0] = 0;
	FOR(x, 1, n) l[x] = min(l[x - 1] + 1, a[x]);
	
	r[n + 1] = 0;
	FORD(x, n, 1) r[x] = min(r[x + 1] + 1, a[x]);
	
	FOR(x, 1, n) res = max(res, min(l[x], r[x]));
	cout << res;
	return 0;
}
