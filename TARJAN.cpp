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

int n, m, num[nMax], low[nMax], timeDfs = 0, cnt_scc = 0;
vi adj[nMax];
bool dell[nMax];
stack<int> scc;

void dfs(int s){
	num[s] = low[s] = ++timeDfs;
	scc.push(s);
	
	for (auto v: adj[s]){
		if (!dell[v]){
			if (!num[v]){
				dfs(v);
				low[s] = min(low[s], low[v]);
			}else low[s] = min(low[s], num[v]);
		}
	}
	
	if (low[s] == num[s]){
		cnt_scc++;
		
		int v;
		do{
			v = scc.top();
			dell[v] = true;
			scc.pop();
		}while (v != s);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	FOR(x, 1, n){
		num[x] = 0;
		dell[x] = false;
	}
	
	FOR(x, 1, m){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	
	FOR(x, 1, n){
		if (!num[x]) dfs(x);
	}
	
	cout << cnt_scc;
	 
	return 0;
}
