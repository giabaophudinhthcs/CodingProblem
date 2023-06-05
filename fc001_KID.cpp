// Link: https://oj.vnoi.info/problem/fc001_kid

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

const int nMax = 1e5 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int k, m, x, y, X, Y;
vi adj[nMax];
bool vis[nMax];

bool bfs_check(int s, int K){
	int a = s;
	int V = 1, S = int(adj[a].size());
	queue<int> q;
	q.push(a);
	vis[a] = true;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (auto v: adj[u]){
			if (!vis[v]){
			    V++;
			    S += int(adj[v].size());
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return  (S == 2 * V - 2) || (V == K);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true){
		cin >> k >> m;
		if ((!k) && (!m)) return 0;
		int cnt = 0;
		set<ii> edge;
		map<int, int> nen;
		FOR(k, 1, m){
			cin >> x >> y;
			if (!nen.count(x)){
				cnt++;
				nen[x] = cnt;
			}
			if (!nen.count(y)){
				cnt++;
				nen[y] = cnt;
			}
			X = min(nen[x], nen[y]);
			Y = max(nen[x], nen[y]);
			edge.insert(make_pair(X,Y));
		}
		for (int i = 1; i <= cnt; i++) {
            adj[i].clear();
            vis[i] = false;
        }
		for (set<ii>::iterator it = edge.begin(); it != edge.end(); it++) {
            adj[it->first].push_back(it->second);
            adj[it->second].push_back(it->first);
        }
		bool res = true;
		FOR(x, 1, cnt) res &= (int(adj[x].size()) <= 2);
		FOR(x, 1, cnt){
			if (!vis[x]) res &= bfs_check(x, k);
		}
		cout << (res ? "Y\n" : "N\n");
	}
	return 0;
}

