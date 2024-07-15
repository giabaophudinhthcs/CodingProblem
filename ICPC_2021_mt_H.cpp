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

class Point{
	public:
		int x, y;
		
		void inp(){
			cin >> this->x >> this->y;
		}
};

class Line{
	public:
		double a, b, c;
		
		void init(Point S, Point T){
			a = T.y - S.y;
			b = S.x - T.x;
			c = T.x * S.y - S.x * T.y;
		}
		
		double f(Point M){
			return (this->a * M.x + this->b * M.y + this->c);
		}
};

class Circle{
	public:
		Point Center;
		double R;
		
		void inp(){
			Center.inp();
			cin >> this->R;
		}
};

Point A, B;
Line d;
Circle C;
double P, LHS, RHS;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	A.inp();
	B.inp();
	d.init(A, B);
	C.inp();
	cin >> P;
	LHS = d.f(C.Center) * d.f(C.Center);
	RHS = C.R * C.R * (d.a * d.a + d.b * d.b);
	if (LHS >= RHS){
		cout << "NO";
		return 0;
	}
	return 0;
}
