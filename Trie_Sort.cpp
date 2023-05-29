#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
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

const int nMax = 2e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

class Node{
	public:
		int child[30];
};

class Trie{
	public:
		Node nodes[nMax];
		int cur, mark[nMax];
		
		void root(){
			this->cur = 0;
			memset(this->nodes[cur].child, -1, sizeof(this->nodes[cur].child));
		}
		
		void init(){
			this->root();
			memset(this->mark, 0, sizeof(this->mark));
		}
		
		int newNode(){
			this->cur++;
			memset(this->nodes[cur].child, -1, sizeof(this->nodes[cur].child));
			return cur;
		}
		
		void add_str(string S){
			int p = 0, N = int(S.len());
			FOR(x, 0, N - 1){
				int hash = S[x] - 'a';
				if (this->nodes[p].child[hash] == -1) this->nodes[p].child[hash] = this->newNode();
				p = this->nodes[p].child[hash];
			}
			this->mark[p] = 1;
		}
		
		void dfs(int p, string& cr, vs& res){
			if (this->mark[p]) res.pb(cr);
			
			FOR(x, 0, 25){
				if (this->nodes[p].child[x] != -1){
					cr += char(x + 'a');
					this->dfs(this->nodes[p].child[x], cr, res);
					cr.pop_back();
				}
			}
		}
		
		void Trie_Sort(){
			// VIPPRO SORT !!!!!!!!!!!!!
			vs res;
			string cr = "";
    		this->dfs(0, cr, res);
    		for (auto S: res) cout << S << "\n";
		}
};

int n;
string S;
Trie tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	tree.init();	
	FOR(x, 1, n){
		cin >> S;
		tree.add_str(S);
	}
	tree.Trie_Sort();
	return 0;
}
