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

class Event{
	public:
		int x, y, l, r, v;
		
		bool operator<(Event o){
			return ((this->x < o.x) || (this->x == o.x && this->v > o.v));
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
			if (sl > p || sr < p) return;
			
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
			return (this->get(si << 1, sl, sm, l, r) + this->get(si << 1 | 1, sm + 1, sr, l, r));
		}
};

int n, res = 0;
Event T[nMax];
ST tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	tree.build(1, 1, 30000);
	cin >> n;
	FOR(p, 1, n){
		cin >> T[2 * p - 1].x >> T[2 * p].x >> T[2 * p - 1].y;
		T[2 * p].y = T[2 * p - 1].y;
		T[2 * p - 1].v = 1;
		T[2 * p].v = -1;
	}
	FOR(p, 2 * n + 1, 3 * n){
		cin >> T[p].l >> T[p].r >> T[p].x;
		T[p].v = 0;
	}
	sort(T + 1, T + 3 * n + 1);
	FOR(p, 1, 3 * n){
		if (T[p].v == 0) res += tree.get(1, 1, 30000, T[p].l, T[p].r);
		else tree.update(1, 1, 30000, T[p].y, T[p].v);
	}
	cout << res;
	return 0;
}
