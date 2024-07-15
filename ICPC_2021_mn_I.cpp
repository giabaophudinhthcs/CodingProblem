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

class Data_Pack{
	public:
		int val, pos;
		
		bool operator<(Data_Pack Other){
			return (this->val < Other.val);
		}
};

class ST{
	public:
		int val[nMax];
		
		void build(int si, int sl, int sr){
			this->val[si] = 0;
			
			if (sl == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm);
			this->build(si << 1 | 1, sm + 1, sr);
		}
		
		void update(int si, int sl, int sr, int p, int v){
			if (p < sl || p > sr) return;
			
			this->val[si] += v;
			
			if (sl == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, p, v);
			this->update(si << 1 | 1, sm + 1, sr, p, v);
		}
		
		int get(int si, int sl, int sr, int l, int r){
			if (r < sl || sr < l) return 0;
			
			if (l <= sl && sr <= r) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			int g1 = this->get(si << 1, sl, sm, l, r);
			int g2 = this->get(si << 1 | 1, sm + 1, sr, l, r);
			return g1 + g2;
		}
};

int n;
ll resL[nMax], resR[nMax], res, cnt = 0;
Data_Pack a[nMax];
ST tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n){
		cin >> a[x].val;
		a[x].pos = x;
	}
	sort(a + 1, a + n + 1);
	tree.build(1, 1, n);
	
	cnt = 0;
	FOR(x, 1, n){
		resL[x] = cnt;
		cnt += (x - 1) - tree.get(1, 1, n, 1, a[x].pos);
		tree.update(1, 1, n, a[x].pos, 1);
	}
	
	tree.build(1, 1, n);
	cnt = 0;
	FORD(x, n, 1){
		resR[x] = cnt;
		cnt += (n - x) - tree.get(1, 1, n, a[x].pos, n);
		tree.update(1, 1, n, a[x].pos, 1);
	}
	
	res = resL[1] + resR[1];
	FOR(p, 2, n) res = min(res, resL[p] + resR[p]);
	cout << res;
	return 0;
}
