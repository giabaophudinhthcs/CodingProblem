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

class Query{
	public:
		string type;
		ll val;
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
			if (sr < p || p < sl) return;
			
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
			return (g1 + g2);
		}
};

map<ll, int> H;
int q, n = 0, ability, Hash_val = 0, cnt = 0;
ll a[nMax], A[nMax], cur = -1;
Query Q[nMax];
string s;
ST tree;

int SUM(int p){
	return tree.get(1, 1, Hash_val, 1, p);
}

void IN(ll x){
	int x_Hash = H[x];
	tree.update(1, 1, Hash_val, x_Hash, 1);
	cnt++;
}

void OUT(ll x){
	int x_Hash = H[x];
	tree.update(1, 1, Hash_val, x_Hash, -1);
	cnt--;
}

void MEDIAN(){
	if (cnt & 1){
		int Find_Pos = (cnt + 1) >> 1, lo = 1, hi = Hash_val, mid, Pos = -1;
		while (lo <= hi){
			mid = (lo + hi) >> 1;
			if (SUM(mid) >= Find_Pos){
				Pos = mid;
				hi = mid - 1;
			}else lo = mid + 1;
		}
		cout << A[Pos] << "\n";
	}else{
		int res = 0, Find_Pos = cnt >> 1, lo = 1, hi = Hash_val, mid, Pos = -1;
		while (lo <= hi){
			mid = (lo + hi) >> 1;
			if (SUM(mid) >= Find_Pos){
				Pos = mid;
				hi = mid - 1;
			}else lo = mid + 1;
		}
		res += A[Pos];
		Find_Pos++;
		lo = 1;
		hi = Hash_val;
		Pos = -1;
		while (lo <= hi){
			mid = (lo + hi) >> 1;
			if (SUM(mid) >= Find_Pos){
				Pos = mid;
				hi = mid - 1;
			}else lo = mid + 1;
		}
		res += A[Pos];
		cout << (res >> 1);
		if (res & 1) cout << ".5";
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> q;
	FOR(x, 1, q){
		cin >> s;
		Q[x].type = s;
		if (s != "MEDIAN"){
			cin >> ability;
			Q[x].val = ability;
			n++;
			a[n] = ability;
		}
	}
	sort(a + 1, a + n + 1);
	FOR(x, 1, n){
		if (cur != a[x]){
			Hash_val++;
			H[a[x]] = Hash_val;
			A[Hash_val] = a[x];
			cur = a[x];
		}
	}
	tree.build(1, 1, Hash_val);
	FOR(x, 1, q){
		if (Q[x].type == "IN") IN(Q[x].val);
		if (Q[x].type == "OUT") OUT(Q[x].val);
		if (Q[x].type == "MEDIAN") MEDIAN();
	}
	return 0;
}
