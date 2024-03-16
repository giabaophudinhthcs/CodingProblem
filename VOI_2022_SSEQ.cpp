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

const int nMax = 5e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

class ST{
	public:
		ll val[nMax], lazy[nMax];
		
		void build(int si, int sl, int sr){
			this->val[si] = this->lazy[si] = 0;
			
			if (sl == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm);
			this->build(si << 1 | 1, sm + 1, sr);
		}
		
		void fix(int si, int sl, int sr){
			this->val[si] += this->lazy[si];
			
			if (sl != sr){
				this->lazy[si << 1] += this->lazy[si];
				this->lazy[si << 1 | 1] += this->lazy[si];
			}
			
			this->lazy[si] = 0;
		}
		
		void update(int si, int sl, int sr, int l, int r, ll v){
			this->fix(si, sl, sr);
			
			if (sr < l || r < sl) return;
			
			if (l <= sl && sr <= r){
				this->lazy[si] += v;
				this->fix(si, sl, sr);
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, l, r, v);
			this->update(si << 1 | 1, sm + 1, sr, l, r, v);
			this->val[si] = max(this->val[si << 1], this->val[si << 1 | 1]);
		}
		
		ll get(int si, int sl, int sr, int l, int r){
			this->fix(si, sl, sr);
			
			if (sr < l || r < sl) return -ooll;
			
			if (l <= sl && sr <= r) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			ll g1 = this->get(si << 1, sl, sm, l, r);
			ll g2 = this->get(si << 1 | 1, sm + 1, sr, l, r);
			return max(g1, g2);
		}
};

class Segment{
	public:
		int l, r;
		ll w;
		
		void inp(){
			cin >> this->l >> this->r >> this->w;
		}
};

int n;
Segment S[nMax];
ST tree;
vi L[nMax];
ll res = -ooll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("SSEQ.INP", "r", stdin);
	freopen("SSEQ.OUT", "w", stdout);
	
	tree.build(1, 1, 1e6);
	
	cin >> n;
	FOR(x, 1, n){
		S[x].inp();
		tree.update(1, 1, 1e6, S[x].r, 1e6, S[x].w);
		L[S[x].l].pb(x);
	}
	
	FOR(x, 0, 1e6){
		for (auto k: L[x]){
			tree.update(1, 1, 1e6, S[k].r, 1e6, -S[k].w);
		}
		
		res = max(res, tree.val[1]);
	}
	
	cout << res;
	
	return 0;
}
