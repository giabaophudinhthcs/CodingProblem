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

const int nMax = 1e5 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

class Data{
	public:
		int u;
		ll w;
		
		bool operator<(Data O) const {
			return this->w > O.w;
		}
		
		void Init(int ver_u, ll Weight){
			this->u = ver_u;
			this->w = Weight;
		}
};

int m, n;
ll dist[nMax];
vector<Data> adj[nMax];
Data Ver;

int Hash(int i, int j){
	return (i - 1) * n + (j + 1);
}

void Dijkstra(){
	FOR(x, 1, m * n + 1) dist[x] = ooll;
	dist[1] = 0;
	priority_queue<Data> pq;
	Ver.Init(1, dist[1]);
	pq.push(Ver);
	
	while (!pq.empty()){
		Data S;
		S = pq.top();
		pq.pop();
		
		for (auto T: adj[S.u]){
			if (T.w + S.w < dist[T.u]){
				dist[T.u] = T.w + S.w;
				Ver.Init(T.u, dist[T.u]);
				pq.push(Ver);
			}
		}
	}
	
	cout << dist[m * n + 1];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> m >> n;
	
	FOR(p, 1, 2 * m){
		FOR(x, 1, n - 1 + (p & 1)){
			ll weight;
			cin >> weight;
			
			Data Ver_S, Ver_T;
			
			if (p == 1){
				Ver_S.Init(1, weight);
				Ver_T.Init(Hash(1, x), weight);
				
				adj[1].pb(Ver_T);
				adj[Hash(1, x)].pb(Ver_S);
			}else if (p & 1){
				Ver_S.Init(Hash((p - 1) >> 1, x), weight);
				Ver_T.Init(Hash((p + 1) >> 1, x), weight);
				
				adj[Hash((p - 1) >> 1, x)].pb(Ver_T);
				adj[Hash((p + 1) >> 1, x)].pb(Ver_S);
			}else{
				Ver_S.Init(Hash(p >> 1, x), weight);
				Ver_T.Init(Hash(p >> 1, x + 1), weight);
				
				adj[Hash(p >> 1, x)].pb(Ver_T);
				adj[Hash(p >> 1, x + 1)].pb(Ver_S);
			}
		}
	}
	
	Dijkstra();
	
	return 0;
}
