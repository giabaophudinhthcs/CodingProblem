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

class Data{
	public:
		ll s;
		int x, y;
		
		bool operator<(Data O){
			return (this->s < O.s) || (this->s == O.s && this->x < O.x) || (this->s == O.s && this->x == O.x && this->y > O.y);
		}
};

int n, d, cnt = 0, res = 0, dem = 0, l[nMax], r[nMax];
Data List[nMax];
ll a[2005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("PAIR.INP", "r", stdin);
	freopen("PAIR.OUT", "w", stdout);
	
	cin >> n >> d;
	FOR(x, 1, n) cin >> a[x];
	
	sort(a + 1, a + n + 1);
	
	FOR(x, 1, n - 1){
		FOR(y, x + 1, n){
			cnt++;
			List[cnt].s = a[x] + a[y];
			List[cnt].x = x;
			List[cnt].y = y;
		}
	}
	
	sort(List + 1, List + cnt + 1);
	
	FOR(L, 1, cnt){
		int R = L;
		dem++;
		l[dem] = L;
		while (R < cnt && List[R + 1].s == List[L].s) R++;
		r[dem] = R;
		L = R;
	}
	
	FOR(x, 1, dem){
		map<int, int> m;
		int g = 0;
		FOR(p, l[x], r[x]){
			if (m[List[p].x] == 0 && m[List[p].y] == 0){
				g++;
				m[List[p].x] = 1;
				m[List[p].y] = 1;
			}
		}
		res = max(res, g);
	}
	
	if (d == 1){
		FOR(x, 1, dem - 1){
			map<int, int> m;
			int g = 0;
			
			FOR(p, l[x + 1], r[x + 1]){
				if (m[List[p].x] == 0 && m[List[p].y] == 0 && List[p].s == List[l[x]].s + 1){
					g++;
					m[List[p].x] = 1;
					m[List[p].y] = 1;
				}
			}
			
			FOR(p, l[x], r[x]){
				if (m[List[p].x] == 0 && m[List[p].y] == 0){
					g++;
					m[List[p].x] = 1;
					m[List[p].y] = 1;
				}
			}
			
			res = max(res, g);
		}
	}
	
	cout << res;
	
	return 0;
}
