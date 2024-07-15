#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define len length

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

int n;
ll m, a[nMax], pre[nMax], suf[nMax], max_h, min_h;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> n >> m;
	max_h = min_h = a[1];
	FOR(i, 1, n){
		cin >> a[i];
		max_h = max(max_h, a[i]);
		min_h = min(min_h, a[i]);
	}
	
	ll lo = min_h, hi = max_h, mid, res = -1;
	
	while (lo <= hi){
		mid = (lo + hi) >> 1;
		
		pre[1] = max(a[1], mid);
		FOR(i, 2, n) pre[i] = max(pre[i - 1], max(a[i], mid));
		
		suf[n] = max(a[n], mid);
		FORD(i, n - 1, 1) suf[i] = max(suf[i + 1], max(a[i], mid));
		
		ll Amount = 0LL;
		FOR(i, 1, n) Amount += (min(pre[i], suf[i]) - max(a[i], mid));
		
		if (Amount >= m){
			res = mid;
			lo = mid + 1;
		}else hi = mid - 1;
	}
	
	cout << res;
	
	return 0;
}
