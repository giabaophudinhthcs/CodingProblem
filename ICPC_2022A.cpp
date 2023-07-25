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

class query{
	public:
		char type, res;
		int s, u, v;
		
		void inp(){
			cin >> this->type;
			if (this->type != 'C'){
				if (this->type == 'Q') cin >> this->s;
				cin >> this->u >> this->v;
			}
		}
		
		bool Ask(){
			return (this->type == '?' || this->type == 'Q');
		}
};

class DSU{
	public:
		int par[nMax], sz[nMax];
		
		void make(int v){
			this->par[v] = v;
			this->sz[v] = 1;
		}
		
		int find(int v){
			return (v == this->par[v] ? v : this->par[v] = this->find(this->par[v]));
		}
		
		bool check(int u, int v){
			return (this->find(u) == this->find(v));
		}
		
		void combine(int u, int v){
			if (this->check(u, v)) return;
			u = this->find(u);
			v = this->find(v);
			if (this->sz[u] <= this->sz[v]) swap(u, v);
			this->par[v] = u;
			this->sz[u] += this->sz[v];
		}
		
		
};

int n, q, Snap = -1;
query Q[nMax];
vector<int> qSnap[nMax];
DSU test;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	FOR(x, 1, 1e6) test.make(x);
	cin >> n >> q;
	Q[0].type = 'C';
	FOR(x, 1, q){
		Q[x].inp();
		if (Q[x].type == 'Q') qSnap[Q[x].s].pb(x);
	}
	FOR(x, 0, q){
		if (Q[x].type == 'A') test.combine(Q[x].u, Q[x].v);
		else if (Q[x].type == '?') Q[x].res = (test.check(Q[x].u, Q[x].v) ? 'Y' : 'N');
		else if (Q[x].type == 'C'){
			Snap++;
			for (auto qq: qSnap[Snap]) Q[qq].res = (test.check(Q[qq].u, Q[qq].v) ? 'Y' : 'N');
		}
	}
	FOR(x, 1, q){
		if (Q[x].Ask()) cout << Q[x].res;
	}
	return 0;
}
