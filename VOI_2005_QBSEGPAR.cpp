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

int n, k, f[nMax], g[nMax], cnt;
ll a[nMax], s[nMax], b[nMax];

class ST_Min{
	public:
		int val[nMax];
		
		void build(int si, int sl, int sr){
			this->val[si] = oo;
			
			if (sl == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm);
			this->build(si << 1 | 1, sm + 1, sr);
		}
		
		void update(int si, int sl, int sr, int pos, int v){
			if (pos < sl || sr < pos) return;
			
			if (sl == pos && sr == pos){
				this->val[si] = min(this->val[si], v);
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, pos, v);
			this->update(si << 1 | 1, sm + 1, sr, pos, v);
			this->val[si] = min(this->val[si << 1], this->val[si << 1 | 1]);
		}
		
		int get(int si, int sl, int sr, int l, int r){
			if (r < sl || sr < l) return oo;
			
			if (l <= sl && sr <= r) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			return min(this->get(si << 1, sl, sm, l, r), this->get(si << 1 | 1, sm + 1, sr, l, r));
		}
};

class ST_Max{
	public:
		int val[nMax];
		
		void build(int si, int sl, int sr){
			this->val[si] = -oo;
			
			if (sl == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm);
			this->build(si << 1 | 1, sm + 1, sr);
		}
		
		void update(int si, int sl, int sr, int pos, int v){
			if (pos < sl || sr < pos) return;
			
			if (sl == pos && sr == pos){
				this->val[si] = max(this->val[si], v);
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, pos, v);
			this->update(si << 1 | 1, sm + 1, sr, pos, v);
			this->val[si] = max(this->val[si << 1], this->val[si << 1 | 1]);
		}
		
		int get(int si, int sl, int sr, int l, int r){
			if (r < sl || sr < l) return -oo;
			
			if (l <= sl && sr <= r) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			return max(this->get(si << 1, sl, sm, l, r), this->get(si << 1 | 1, sm + 1, sr, l, r));
		}
};

ST_Min F_tree;
ST_Max G_tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	FOR(x, 1, n){
		cin >> a[x];
		s[x] = s[x - 1] + a[x];
	}
	
	ll lo = -1e9, hi = 1e9, res = -oo;
	while (lo <= hi){
	    map<ll, int> h;
		ll mid = (lo + hi) >> 1;
		
		f[0] = g[0] = 0;
		FOR(x, 1, n){
			f[x] = oo;
			g[x] = -oo;
		}
		
		cnt = 0;
		
		FOR(x, 0, n){
			b[2 * x + 1] = s[x];
			b[2 * x + 2] = s[x] - mid;
		}
		
		sort(b + 1, b + 2 * n + 3);
		
		FOR(x, 1, 2 * n + 2){
			if (h[b[x]] == 0){
				cnt++;
				h[b[x]] = cnt;
			}
		}
		
		F_tree.build(1, 1, cnt);
		F_tree.update(1, 1, cnt, h[s[0]], f[0]);
		G_tree.build(1, 1, cnt);
		G_tree.update(1, 1, cnt, h[s[0]], g[0]);
		
		FOR(x, 1, n){			
			f[x] = min(f[x], F_tree.get(1, 1, cnt, h[s[x] - mid], cnt) + 1);
			F_tree.update(1, 1, cnt, h[s[x]], f[x]);
			
			g[x] = max(g[x], G_tree.get(1, 1, cnt, h[s[x] - mid], cnt) + 1);
			G_tree.update(1, 1, cnt, h[s[x]], g[x]);
		}
		
		if (f[n] <= k && k <= g[n]){
			res = mid;
			hi = mid - 1;
		}else lo = mid + 1;
	}
	
	cout << res;
	
	return 0;
}
