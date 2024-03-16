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

int V, E, num[nMax], low[nMax], timeDfs = 0, comp = 0;
vi adj[nMax];
ll f = -1, res = 0, sz[nMax], B = 0, A;

void dfs(int s, int par){
	num[s] = low[s] = ++timeDfs;
	
	for (auto v: adj[s]){
		if (v != par){
			if (!num[v]){
				dfs(v, s);
				
				sz[s] += sz[v];
				low[s] = min(low[s], low[v]);
			
				if (low[v] == num[v]){
					B++;
					res += sz[v] * (V - sz[v]);
				}
			}else low[s] = min(low[s], num[v]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> V >> E;
	
	FOR(x, 1, V) sz[x] = 1;
	
	FOR(x, 1, E){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	FOR(x, 1, V){
		if (!num[x]){
			dfs(x, x);
			comp++;
			
			if (f == -1) f = timeDfs;
		}
	}
	
	if (comp > 2) cout << 0;
	else if (comp == 2){
		res = f * (V - f) * (E - B);
		cout << res;
	}else{
		res -= B;
		A = V;
		A *= (V - 1);
		A >>= 1;
		res += 1LL * (E - B) * (A - E);
		cout << res;
	}
	
	return 0;
}
