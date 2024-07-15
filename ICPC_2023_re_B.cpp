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

int t, n, m, v, AC_sub[22];
bool ok;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		ok = 1;
		FOR(prob, 1, m) AC_sub[prob] = 0;
		FOR(x, 1, n){
			int pts = 0;
			FOR(y, 1, m){
				cin >> v;
				pts += v;
				AC_sub[y] += v;
			}
			ok = ok && (pts > 0 && pts < m);
		}
		
		FOR(prob, 1, m) ok = ok && (AC_sub[prob]);
		
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}
