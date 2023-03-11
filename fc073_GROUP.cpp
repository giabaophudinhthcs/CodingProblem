// Link: https://oj.vnoi.info/problem/fc073_group

#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define ff first
#define ss second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;
typedef vector<int> vi;

const int nMax = 1e5 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;

int n, m, vis[nMax];
vi adj[nMax];

void bfs_vippro(int s){
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()){
        int t = q.front();
        q.pop();
        for (auto v: adj[t]){
            if (!vis[v]){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR(x, 1, m){
	    int u, v;
	    cin >> u >> v;
	    if (u != v){
	        adj[u].pb(v);
	        adj[v].pb(u);
	    }
	}
	int ans = 0;
	FOR(x, 1, n) vis[x] = 0;
	FOR(x, 1, n){
	    if (!vis[x]){
	        ans++;
	        bfs_vippro(x);
	    }
	}
	cout << ans;
	return 0;
}
