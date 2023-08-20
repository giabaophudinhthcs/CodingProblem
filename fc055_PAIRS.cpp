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
		
		void update(int si, int sl, int sr, int Pos){
			if (Pos < sl || sr < Pos) return;
			
			this->val[si]++;
			
			if (Pos == sl && Pos == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, Pos);
			this->update(si << 1 | 1, sm + 1, sr, Pos);
		}
		
		int get(int si, int sl, int sr, int l, int r){
			if (r < sl || sr < l) return 0;
			
			if (l <= sl && sr <= r) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			int g1 = get(si << 1, sl, sm, l, r);
			int g2 = get(si << 1 | 1, sm + 1, sr, l, r);
			return (g1 + g2);
		}
};

int n, a[nMax], N, odd[nMax];
ll res = 0LL;
vi pos[nMax];
ST tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	tree.build(1, 1, n);
	N = n - (n & 1);
	odd[0] = 0;
	FOR(x, 1, n){
		cin >> a[x];
		if (!(a[x] & 1)) pos[a[x]].pb(x);
		odd[x] = odd[x - 1] + (a[x] & 1);
	}
	
	// s[l] = s[p] - 1
	
	for (int k = N; k >= 2; k -= 2){
		if (pos[k].size()){
			for (auto p: pos[k]){
				int lo = 0, hi = p - 1, mid, l = 0;
				while (lo <= hi){
					mid = (lo + hi) >> 1;
					if (odd[mid] < odd[p]){
						l = mid;
						lo = mid + 1;
					}else hi = mid - 1;
				}
				res += tree.get(1, 1, n, 1, l);
			}
			
			for (auto p: pos[k]) tree.update(1, 1, n, p);
		}
	}
	cout << res;
	return 0;
}
