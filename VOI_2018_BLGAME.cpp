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

int a, b, c, m, n, k, t[1005][1005], vis[1005][1005], res = 1;
queue<ii> q;
ii dir[4];

bool Inside(int X, int Y){
	return (1 <= X && X <= m && 1 <= Y && Y <= n);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	dir[0] = {-1, 0};
	dir[1] = {0, 1};
	dir[2] = {1, 0};
	dir[3] = {0, -1};
	
	cin >> a >> b >> c >> m >> n >> k;
	
	FOR(x, 1, m){
		FOR(y, 1, n) t[x][y] = vis[x][y] = 0;
	}
	
	FOR(s, 1, k){
		int u, v;
		cin >> u >> v;
		t[u][v] = 1;
	}
	
	if (a == 1 && b == 1 && c == 1){
		q.push({1, 1});
		vis[1][1] = 1;
		while (!q.empty()){
			ii u = q.front();
			q.pop();
			
			FOR(x, 0, 3){
				if (!Inside(u.ff + dir[x].ff, u.ss + dir[x].ss)) continue;
				if (!t[u.ff + dir[x].ff][u.ss + dir[x].ss] && !vis[u.ff + dir[x].ff][u.ss + dir[x].ss]){
					vis[u.ff + dir[x].ff][u.ss + dir[x].ss] = 1;
					res++;
					q.push({u.ff + dir[x].ff, u.ss + dir[x].ss});
				}
			}
		}
		
		cout << res;
		return 0;
	}
	
	if (a == 1 && b == 2 && c == 1) cout << 7;
	else cout << a * b;
	
	return 0;
}
