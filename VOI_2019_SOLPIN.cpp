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

int m, n, q, type, row = 0, col = 0;
ll a, s[503][503];

ll Sum(int X1, int Y1, int X2, int Y2){
	return s[X2][Y2] - s[X1 - 1][Y2] - s[X2][Y1 - 1] + s[X1 - 1][Y1 - 1];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	FOR(r, 1, m){
		FOR(c, 1, n){
			cin >> a;
			s[r][c] = s[r - 1][c] + s[r][c - 1] - s[r - 1][c - 1] + a;
		}
	}
	
	cin >> q;
	FOR(x, 1, q){
		cin >> type;
		
		if (!type){
			int Dir_R, Dir_C;
			cin >> Dir_C >> Dir_R;
			row += Dir_R;
			col += Dir_C;
		}else{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			
			x1 = (x1 + row) % m;
			if (!x1) x1 = m;
			y1 = (y1 + col) % n;
			if (!y1) y1 = n;
			
			x2 = (x2 + row) % m;
			if (!x2) x2 = m;
			y2 = (y2 + col) % n;
			if (!y2) y2 = n;
			
			if (x1 <= x2 && y1 <= y2) cout << Sum(x1, y1, x2, y2);
			else if (x1 <= x2 && y1 > y2) cout << Sum(x1, y1, x2, n) + Sum(x1, 1, x2, y2);
			else if (x1 > x2 && y1 <= y2) cout << Sum(x1, y1, m, y2) + Sum(1, y1, x2, y2);
			else cout << Sum(1, 1, x2, y2) + Sum(1, y1, x2, n) + Sum(x1, 1, m, y2) + Sum(x1, y1, m, n);
			
			cout << "\n";
		}
	}
	
	return 0;
}
