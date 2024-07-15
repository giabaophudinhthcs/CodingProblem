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

class Point{
	public:
		int x, y;
		
		void Inp(){
			cin >> this->x >> this->y;
		}
};

class Line{
	public:
		double a, b, c;
		
		double F(Point A){
			return (1.0 * this->a * A.x + 1.0 * this->b * A.y + this->c);
		}
};

int k, t, po, ne, ok;
double a, b, c[3];
Point A[10], M, N, P;
Line d[3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> d[1].a >> d[1].b >> c[1] >> c[2];
		d[2].a = d[1].a;
		d[2].b = d[1].b;
		d[1].c = -c[1];
		d[2].c = -c[2];
		cin >> k;
		FOR(p, 1, k) A[p].Inp();
		
		po = ne = 0;
		FOR(p, 1, k){
			if (d[1].F(A[p]) > 0.0) po = 1;
			if (d[1].F(A[p]) < 0.0) ne = 1;
		}
		if (po && ne){
			cout << "YES\n";
			continue;
		}
		
		po = ne = 0;
		FOR(p, 1, k){
			if (d[2].F(A[p]) > 0.0) po = 1;
			if (d[2].F(A[p]) < 0.0) ne = 1;
		}
		if (po && ne){
			cout << "YES\n";
			continue;
		}
		
		if (d[1].b == 0.0){
			M.y = N.y = 0;
			M.x = (-1.0 * d[1].c) / (1.0 * d[1].a);
			N.x = (-1.0 * d[2].c) / (1.0 * d[2].a);
		}else{
			M.x = N.x = 0;
			M.y = (-1.0 * d[1].c) / (1.0 * d[1].b);
			N.y = (-1.0 * d[2].c) / (1.0 * d[2].b);
		}
		P.x = (M.x + N.x) / 2.0;
		P.y = (M.y + N.y) / 2.0;
		
		ok = 1;
		FOR(p, 1, k) ok &= (d[1].F(P) * d[1].F(A[p]) <= 0.0);
		if (ok){
			cout << "NO\n";
			continue;
		}
		
		ok = 1;
		FOR(p, 1, k) ok &= (d[2].F(P) * d[2].F(A[p]) <= 0.0);
		cout << (ok ? "NO\n" : "YES\n");
	}
	return 0;
}
