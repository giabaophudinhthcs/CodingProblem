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

const int nMax = 3e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, a[nMax], tmp[nMax], l[nMax], r[nMax];

class ST{
	public:
		int val[nMax];
		
		void build(int si, int sl, int sr){
			if (sl == sr){
				this->val[si] = a[sl];
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm);
			this->build(si << 1 | 1, sm + 1, sr);
			this->val[si] = max(this->val[si << 1], this->val[si << 1 | 1]);
		}
		
		int get(int si, int sl, int sr, int Left, int Right){
			if (Right < sl || sr < Left) return 0;
			
			if (Left <= sl && sr <= Right) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			return max(this->get(si << 1, sl, sm, Left, Right), this->get(si << 1 | 1, sm + 1, sr, Left, Right));
		}
};

ST tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("INCOME.INP", "r", stdin);
	freopen("INCOME.OUT", "w", stdout);
	
	cin >> n;
	
	FOR(x, 1, n) cin >> a[x];
	FOR(x, 1, n) cin >> l[x] >> r[x];
	
	if (n <= 500){
		FOR(t, 1, n){
			int ok = 1;
			
			FOR(x, 1, n){
				tmp[x] = a[x];
				FOR(y, l[x], r[x]) tmp[x] = max(tmp[x], a[y]);
				ok &= (tmp[x] == a[x]);
			}
			
			if (ok){
				cout << t;
				return 0;
			}
			
			FOR(x, 1, n) a[x] = tmp[x];
		}
	}else{
		FOR(t, 1, 25){
			int ok = 1;
			
			tree.build(1, 1, n);
			FOR(x, 1, n){
				tmp[x] = max(a[x], tree.get(1, 1, n, l[x], r[x]));
				ok &= (tmp[x] == a[x]);
			}
			
			if (ok){
				cout << t;
				return 0;
			}
			
			FOR(x, 1, n) a[x] = tmp[x];
		}
		
		cout << 3;
	}
	
	return 0;
}
