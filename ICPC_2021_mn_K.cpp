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

int n, res = 0;
ll x[nMax], y, z;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(p, 1, n) cin >> x[p];
	cin >> y >> z;
	y = abs(y - z);
	FOR(p, 1, n) x[p] = abs(x[p] - z);
	sort(x + 1, x + n + 1);
	FOR(p, 1, n){
		if (x[p] < y){
			res++;
			y -= x[p];
		}else break;
	}
	cout << res;
	return 0;
}
