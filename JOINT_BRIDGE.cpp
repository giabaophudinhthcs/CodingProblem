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

int n, m, num[nMax], low[nMax], Is_Joint[nMax], timeDfs = 0, bridge = 0, joint = 0;
vi adj[nMax];

void dfs(int s, int par){
	int child = 0;
	num[s] = low[s] = ++timeDfs;
	
	for (auto v: adj[s]){
		if (v != par){
			if (!num[v]){
				dfs(v, s);
				low[s] = min(low[s], low[v]);
			
				if (low[v] == num[v]) bridge++;
				
				child++;
				if ((s == par && child > 1) || (low[v] >= num[s] && s != par)) Is_Joint[s] = 1;
			}else low[s] = min(low[s], num[v]);
		}
	}
	
	// cout << s << " " << child << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	FOR(x, 1, m){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	FOR(x, 1, n){
		if (!num[x]) dfs(x, x);
	}
	
	FOR(x, 1, n){
	    joint += Is_Joint[x];
	}
	
	cout << joint << " " << bridge;
	 
	return 0;
}
