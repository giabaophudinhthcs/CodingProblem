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

int t, n, a[nMax], c[nMax];
ll res = 0LL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	FOR(test, 1, t){
		cin >> n;
		FOR(x, 1, n) c[x] = 0;
		FOR(x, 1, n){
			cin >> a[x];
			c[x] = 0;
		}
		int l = 1, r = 1;
		c[a[1]] = 1;
		while (l <= n && r <= n){
			while (r <= n && c[a[r]] <= 1){
				res += (r - l + 1);
				r++;
				c[a[r]]++;
			}
			
			while (l <= n && c[a[r]] > 1){
				c[a[l]]--;
				l++;
			}
		}
		cout << res << "\n";
		res = 0LL;
	}
	return 0;
}
