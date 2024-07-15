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

const int nMax = 1e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, k, a[nMax];
ll dp[nMax][11], res = 0LL;

class ST{
	public:
		ll val[nMax];
		
		void build(int si, int sl, int sr){
			this->val[si] = 0;
			
			if (sl == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm);
			this->build(si << 1 | 1, sm + 1, sr);
		}
		
		void update(int si, int sl, int sr, int pos, ll Val){
			if (pos < sl || sr < pos) return;
			
			this->val[si] += Val;
			
			if (pos == sl && pos == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, pos, Val);
			this->update(si << 1 | 1, sm + 1, sr, pos, Val);
		}
		
		ll get(int si, int sl, int sr, int l, int r){
			if (sr < l || r < sl) return 0;
			
			if (l <= sl && sr <= r) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			ll g1 = this->get(si << 1, sl, sm, l, r);
			ll g2 = this->get(si << 1 | 1, sm + 1, sr, l, r);
			return (g1 + g2);
		}
};

ST tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> n >> k;
	FOR(x, 1, n){
		int i;
		cin >> i;
		cin >> a[i];
		dp[x][1] = 1;
	}
	
	FOR(i, 2, k){
		tree.build(1, 1, n);
		FOR(x, 1, n){
			if (a[x] == 1) dp[x][i] = 0;
			else dp[x][i] = tree.get(1, 1, n, 1, a[x] - 1);
			
			tree.update(1, 1, n, a[x], dp[x][i - 1]);
		}
	}
	
	FOR(x, 1, n) res += dp[x][k];
	cout << res;
	
	return 0;
}
