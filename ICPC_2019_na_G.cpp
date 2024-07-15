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

int n, pos, m;
ll a[nMax], s[nMax], S[nMax], res, g;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	pos = n + 1;
	FOR(x, 1, n) cin >> a[x];
	
	sort(a + 1, a + n + 1);
	FOR(x, 1, n){
		s[x] = s[x - 1] + a[x];
		S[x] = S[x - 1] + llabs(a[x]);
		if (a[x] > 0 && pos > n) pos = x;
	}
	
	// x = 0 || x = n:
	res = S[n];
	m = (1 + n) >> 1;
	res = min(res, (2 * m - n) * a[m] - 2 * s[m] + s[n]);
	
	// 1 <= x < n:
	FOR(x, 1, n - 1){
		m = (1 + x) >> 1;
		g = (2 * m - x) * a[m] - 2 * s[m] + s[x];
		res = min(res, g + S[n] - S[x]);
		
		m = (x + 1 + n) >> 1;
		g = (2 * m - x - n) * a[m] - 2 * s[m] + s[x] + s[n];
		res = min(res, g + S[x]);
	}
	
	cout << res;
	
	return 0;
}
