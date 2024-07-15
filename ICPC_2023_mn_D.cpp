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

int type, n, g, a[505][505], d[505][505];
ii dir[5];

int bfs_01_calc(){
	FOR(x, 1, n){
		FOR(y, 1, n) d[x][y] = -1;
	}
	deque<ii> q;
	q.pf({1, 1});
	d[1][1] = (g > a[1][1]);
	while (!q.empty()){
		ii s = q.front();
		q.pop_front();
		if (s.ff == n && s.ss == n) return d[n][n];
		FOR(DIR, 1, 4){
			ii t;
			t = {s.ff + dir[DIR].ff, s.ss + dir[DIR].ss};
			if (t.ff < 1 || t.ff > n) continue;
			if (t.ss < 1 || t.ss > n) continue;
			if (d[t.ff][t.ss] >= 0) continue;
			
			int w = (g > a[t.ff][t.ss]);
			d[t.ff][t.ss] = d[s.ff][s.ss] + w;
			if (w) q.pb(t);
			else q.pf(t);
		}
	}
	
	return oo;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	dir[1] = {-1, 0};
	dir[2] = {1, 0};
	dir[3] = {0, -1};
	dir[4] = {0, 1};
	
	cin >> type >> n;
	if (type == 1) cin >> g;
	FOR(x, 1, n){
		FOR(y, 1, n) cin >> a[x][y];
	}
	
	if (type == 1) cout << bfs_01_calc();
	else{
		int l = 1, r = 10000, res = 1;
		while (l <= r){
			g = (l + r) >> 1;
			if (bfs_01_calc() == 0){
				res = g;
				l = g + 1;
			}else r = g - 1;
		}
		cout << res;
	}
	return 0;
}
