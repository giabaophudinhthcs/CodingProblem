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

const int nMax = 1e5 + 5;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, a[nMax], q;
vi val[nMax * 4];

void build(int si, int sl, int sr){
	if (sl == sr){
		val[si].pb(a[sl]);
		return;
	}
	
	int sm = (sl + sr) >> 1;
	build(si << 1, sl, sm);
	build(si << 1 | 1, sm + 1, sr);
	
	val[si].assign(sr - sl + 1, 0);
	merge(val[si << 1].begin(), val[si << 1].end(), val[si << 1 | 1].begin(), val[si << 1 | 1].end(), val[si].begin());
}

int get(int si, int sl, int sr, int L, int R, int v){
	if (sr < L || R < sl) return 0;
	
	if (L <= sl && sr <= R) return (upper_bound(val[si].begin(), val[si].end(), v) - val[si].begin());
	
	int sm = (sl + sr) >> 1;
	return (get(si << 1, sl, sm, L, R, v) + get(si << 1 | 1, sm + 1, sr, L, R, v));
}

int find(int Left, int Right, int Pos){
	// Find k-largest number in a[l], a[l + 1], ..., a[r]
	// Solution: Use Binary Search and Segment Tree
	
	int lo = 0, hi = 1e5, mid, res = 0;
	while (lo <= hi){
		mid = (lo + hi) >> 1;
		int cnt = get(1, 1, n, Left, Right, mid);
		if (cnt >= Pos){
			res = mid;
			hi = mid - 1;
		}else lo = mid + 1;
	}
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	cin >> n >> q;
	FOR(x, 1, n) cin >> a[x];
	
	build(1, 1, n);
	
	FOR(x, 1, q){
		int l, r, k;
		cin >> l >> r;
		k = int((r - l + 2) / 2);
		cout << find(l, r, k) << "\n";
	}
	
	return 0;
}
