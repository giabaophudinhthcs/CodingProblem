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

int n, k, x, y, z;
ll res = 0LL;
set<ii> Xo, Yo, Zo;
map<int, ll> cntX, cntY, cntZ;
map<ii, ll> cntXY;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	FOR(p, 1, k){
		cin >> x >> y >> z;
		if (!x) Xo.insert({y, z});
		if (!y) Yo.insert({z, x});
		if (!z) Zo.insert({x, y});
	}
	
	for (auto [Y, Z]: Xo){
		res += n;
		cntY[Y]++;
		cntZ[Z]++;
	}
	
	for (auto [Z, X]: Yo){
		res += (n - cntZ[Z]);
		cntX[X]++;
		for (auto [YY, ZZ]: Xo){
			if (Z == ZZ) cntXY[{X, YY}]++;
		}
	}
	
	for (auto [X, Y]: Zo){
		res += (n - cntY[Y] - cntX[X] + cntXY[{X, Y}]);
	}
	
	cout << res;
	return 0;
}
