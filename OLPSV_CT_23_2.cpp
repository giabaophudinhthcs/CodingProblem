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

int n, q, pos[10][nMax], type, mark[nMax][10], FP[nMax][10], cnt[10];
ll a[nMax];

class ST_Normal{
	public:
		ll val[nMax];
		
		void build(int si, int sl, int sr){
			if (sl == sr){
				this->val[si] = a[sl];
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm);
			this->build(si << 1 | 1, sm + 1, sr);
			this->val[si] = this->val[si << 1] + this->val[si << 1 | 1];
		}
		
		void update(int si, int sl, int sr, int Pos, ll Val){
			if (Pos < sl || Pos > sr) return;
			
			if (sl == sr){
				this->val[si] = Val;
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, Pos, Val);
			this->update(si << 1 | 1, sm + 1, sr, Pos, Val);
			this->val[si] = this->val[si << 1] + this->val[si << 1 | 1];
		}
		
		ll get(int si, int sl, int sr, int l, int r){
			if (sr < l || r < sl) return 0;
			
			if (l <= sl && sr <= r) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			return (this->get(si << 1, sl, sm, l, r) + this->get(si << 1 | 1, sm + 1, sr, l, r));
		}
};

class ST_Lord_JackBotox{
	public:
		ll val[nMax];
		
		void build(int si, int sl, int sr, int d){
			if (sl == sr){
				this->val[si] = a[pos[d][sl]];
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm, d);
			this->build(si << 1 | 1, sm + 1, sr, d);
			this->val[si] = this->val[si << 1] + this->val[si << 1 | 1];
		}
		
		void update(int si, int sl, int sr, int Pos, ll Val){
			if (Pos < sl || Pos > sr) return;
			
			if (sl == sr){
				this->val[si] = Val;
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, Pos, Val);
			this->update(si << 1 | 1, sm + 1, sr, Pos, Val);
			this->val[si] = this->val[si << 1] + this->val[si << 1 | 1];
		}
		
		ll get(int si, int sl, int sr, int l, int r){
			if (sr < l || r < sl) return 0;
			
			if (l <= sl && sr <= r) return this->val[si];
			
			int sm = (sl + sr) >> 1;
			return (this->get(si << 1, sl, sm, l, r) + this->get(si << 1 | 1, sm + 1, sr, l, r));
		}
};

ST_Normal tree;
ST_Lord_JackBotox Lord_tree[10];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	FOR(V, 0, 9) cnt[V] = 0;
	
	cin >> n >> q;
	FOR(x, 1, n){
	    cin >> a[x];
	    FOR(digit, 0, 9) mark[x][digit] = 0;
	}
	
	FOR(num, 1, n){
	    int tmp = num;
	    while (tmp){
	        mark[num][tmp % 10] = 1;
	        tmp /= 10;
	    }
	}
	
	FOR(digit, 2, 9){
	    FOR(num, 1, n){
	        if (num % digit == 0 || mark[num][digit] == 1){
	            mark[num][digit] = 1;
	            cnt[digit]++;
	            pos[digit][cnt[digit]] = num;
	            FP[num][digit] = cnt[digit];
	        }
	    }
	}
	
	tree.build(1, 1, n);
	FOR(V, 2, 9){
	    if (cnt[V] > 0) Lord_tree[V].build(1, 1, cnt[V], V);
	}
	
	while (q--){
	    cin >> type;
	    if (type == 1){
	        int p, c;
	        cin >> p >> c;
	        
	        tree.update(1, 1, n, p, c);
	        FOR(digit, 2, 9){
	        	if (mark[p][digit] == 1) Lord_tree[digit].update(1, 1, cnt[digit], FP[p][digit], c);
			}
	    }else{
	        int l, r, Qd;
	        cin >> l >> r >> Qd;
	        if (Qd == 1) cout << tree.get(1, 1, n, l, r) * 2 << "\n";
	        else{
	        	ll res = tree.get(1, 1, n, l, r);
	        	int L = l, R = r;
	        	while (mark[L][Qd] == 0) L++;
	        	while (mark[R][Qd] == 0) R--;
	        	if (L <= R) res += Lord_tree[Qd].get(1, 1, cnt[Qd], FP[L][Qd], FP[R][Qd]);
	        	cout << res << "\n";
			}
	    }
	}
	
	return 0;
}

