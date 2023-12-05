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

class Segment{
	public:
		ll x, yl, yr;
		int type;
		
		bool operator<(const Segment& o) const {
			return (this->x < o.x) || (this->x == o.x && this->type < o.type);
		}
		
		void init(ll X, ll Y1, ll Y2, int v){
			this->x = X;
			this->yl = Y1;
			this->yr = Y2;
			this->type = v;
		}
};

Segment L[nMax];
int k, n, cnt_y = 0;
map<ll, int> Hash_val;
ll Coor_Y[nMax], Y_val[nMax], xc1, yc1, xc2, yc2, xt1, yt1, xt2, yt2, res = 0, a;
char dir;

class Node{
	public:
		ll covered_len;
		int rect_cnt;
};

class ST{
	public:
		Node nodes[nMax];
		
		void build(int si, int sl, int sr){
			this->nodes[si].rect_cnt = 0;
			this->nodes[si].covered_len = 0;
			
			if (sl == sr) return;
			
			int sm = (sl + sr) >> 1;
			this->build(si << 1, sl, sm);
			this->build(si << 1 | 1, sm + 1, sr);
		}
		
		void update(int si, int sl, int sr, int l, int r, int val){
			if (r < sl || sr < l) return;
			
			if (l <= sl && sr <= r){
				this->nodes[si].rect_cnt += val;
				
				if (this->nodes[si].rect_cnt > 0) this->nodes[si].covered_len = Y_val[sr + 1] - Y_val[sl];
				else if (sl != sr) this->nodes[si].covered_len = this->nodes[si << 1].covered_len + this->nodes[si << 1 | 1].covered_len;
				else this->nodes[si].covered_len = 0;
				
				return;
			}
			
			int sm = (sl + sr) >> 1;
			this->update(si << 1, sl, sm, l, r, val);
			this->update(si << 1 | 1, sm + 1, sr, l, r, val);
			
			if (this->nodes[si].rect_cnt > 0) this->nodes[si].covered_len = Y_val[sr + 1] - Y_val[sl];
			else this->nodes[si].covered_len = this->nodes[si << 1].covered_len + this->nodes[si << 1 | 1].covered_len;
		}
};

ST tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	xc1 = yc1 = 0;
	xc2 = yc2 = k;
	FOR(p, 1, n){
		cin >> dir >> a;
		if (dir == 'N'){
			xt1 = xc1;
			yt1 = yc1 + a;
			xt2 = xc2;
			yt2 = yc2 + a;
			L[(p << 1) - 1].init(xc1, yc1, yt2, 1);
			L[(p << 1)].init(xt2, yc1, yt2, -1);
			Coor_Y[(p << 1) - 1] = yc1;
			Coor_Y[(p << 1)] = yt2;
			xc1 = xt1;
			yc1 = yt1;
			xc2 = xt2;
			yc2 = yt2;
		}else if (dir == 'E'){
			xt1 = xc1 + a;
			yt1 = yc1;
			xt2 = xc2 + a;
			yt2 = yc2;
			L[(p << 1) - 1].init(xc1, yc1, yt2, 1);
			L[(p << 1)].init(xt2, yc1, yt2, -1);
			Coor_Y[(p << 1) - 1] = yc1;
			Coor_Y[(p << 1)] = yt2;
			xc1 = xt1;
			yc1 = yt1;
			xc2 = xt2;
			yc2 = yt2;
		}else if (dir == 'S'){
			xt1 = xc1;
			yt1 = yc1 - a;
			xt2 = xc2;
			yt2 = yc2 - a;
			L[(p << 1) - 1].init(xt1, yt1, yc2, 1);
			L[(p << 1)].init(xc2, yt1, yc2, -1);
			Coor_Y[(p << 1) - 1] = yt1;
			Coor_Y[(p << 1)] = yc2;
			xc1 = xt1;
			yc1 = yt1;
			xc2 = xt2;
			yc2 = yt2;
		}else if (dir == 'W'){
			xt1 = xc1 - a;
			yt1 = yc1;
			xt2 = xc2 - a;
			yt2 = yc2;
			L[(p << 1) - 1].init(xt1, yt1, yc2, 1);
			L[(p << 1)].init(xc2, yt1, yc2, -1);
			Coor_Y[(p << 1) - 1] = yt1;
			Coor_Y[(p << 1)] = yc2;
			xc1 = xt1;
			yc1 = yt1;
			xc2 = xt2;
			yc2 = yt2;
		}
	}
	
	sort(L + 1, L + (n << 1) + 1);
	sort(Coor_Y + 1, Coor_Y + (n << 1) + 1);
	
	FOR(p, 1, (n << 1)){
		if (!Hash_val[Coor_Y[p]]){
			cnt_y++;
			Hash_val[Coor_Y[p]] = cnt_y;
			Y_val[cnt_y] = Coor_Y[p];
		}
	}
	
	FOR(p, 1, (n << 1)){
		L[p].yl = Hash_val[L[p].yl];
		L[p].yr = Hash_val[L[p].yr];
	}
	
	tree.build(1, 1, cnt_y - 1);
	
	FOR(p, 1, (n << 1) - 1){
		tree.update(1, 1, cnt_y - 1, L[p].yl, L[p].yr - 1, L[p].type);
		res += tree.nodes[1].covered_len * (L[p + 1].x - L[p].x);
	}
	
	cout << res;
	return 0;
}
