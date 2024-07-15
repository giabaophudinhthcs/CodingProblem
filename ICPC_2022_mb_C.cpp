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

const int nMax = 5e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, m = 0, s, t, cap[2005][2005], flow[2005][2005], trace[2005], maxFlow = 0, a[2005], b[2005], color[2005];
vi adj[2005];
ii edge[nMax];

void bfs(){
	FOR(x, 1, n + 2) trace[x] = 0;
	trace[s] = -1;
	
	queue<int> q;
	q.push(s);
	
	while (!q.empty()){
		int u = q.front();
		q.pop();
		
		for (auto v: adj[u]){
			if (trace[v] != 0 || flow[u][v] == cap[u][v]) continue;
			
			trace[v] = u;
			q.push(v);
		}
	}
}

void bfs_2(){
	FOR(x, 2, n + 1) color[x] = 0;
	queue<int> q;
	color[2] = 1;
	q.push(2);
	
	while (!q.empty()){
		int U = q.front();
		q.pop();
		for (auto V: adj[U]){
			if (!color[V]){
				color[V] = 3 - color[U];
				q.push(V);
			}
		}
	}
}

void Inc_Flow(){
	int delta = oo, v = t;
	while (v != s){
		int u = trace[v];
		delta = min(delta, cap[u][v] - flow[u][v]);
		v = u;
	}
	
	maxFlow += delta;
	
	v = t;
	while (v != s){
		int u = trace[v];
		flow[u][v] += delta;
		flow[v][u] -= delta;
		v = u;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	while (cin >> n){
	    FOR(x, 2, n + 1){
    		cin >> a[x] >> b[x];
    		FOR(y, 2, x - 1){
    			if (abs(a[x] - a[y]) + abs(b[x] - b[y]) == 1){
    				adj[x].pb(y);
    				adj[y].pb(x);
    				edge[++m] = {x, y};
    			}
    		}
    	}
    	
    	bfs_2();
    	
    	FOR(x, 1, m){
    		int u = edge[x].ff;
    		int v = edge[x].ss;
    		if (color[u] == 2) swap(u, v);
    		cap[u][v] = 1;
    	}
    	
    	FOR(x, 2, n + 1){
    		if (color[x] == 1){
    			adj[1].pb(x);
    			adj[x].pb(1);
    			cap[1][x] = 1;
    		}else{
    			adj[n + 2].pb(x);
    			adj[x].pb(n + 2);
    			cap[x][n + 2] = 1;
    		}
    	}
    	
    	s = 1;
    	t = n + 2;
    	
    	do{
    		bfs();
    		if (trace[t]) Inc_Flow();
    	}while (trace[t]);
    	
    	cout << n - maxFlow << "\n";
    	
    	maxFlow = 0;
    	FOR(x, 1, n + 2){
    	    FOR(y, 1, n + 2){
    	        cap[x][y] = flow[x][y] = 0;
    	    }
    	}
    	FOR(x, 1, n + 2) adj[x].clear();
	}
	
	return 0;
}
