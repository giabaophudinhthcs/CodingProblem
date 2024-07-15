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
// const auto seed = chrono::steady_clock::now().time_since_epoch().count();

class Point{
	public:
		ll x, y;
		
		void inp(){
			cin >> this->x >> this->y;
		}
		
		void out(){
			cout << this->x << " " << this->y << "\n";
		}
		
		bool operator<(Point O){
			return (this->x < O.x) || (this->x == O.x && this->y < O.y);
		}
};

class Vec{
	public:
		ll x, y;
		
		void init(Point A, Point B){
			this->x = B.x - A.x;
			this->y = B.y - A.y;
		}
};

ll Cross_Product(Vec u, Vec v){
	return u.x * v.y - u.y * v.x;
}

bool Check_Counterclockwise(Point A, Point B, Point C){
	Vec AB, BC;
	AB.init(A, B);
	BC.init(B, C);
	
	return Cross_Product(AB, BC) >= 0LL;
}

Point A[5];
int t;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	FOR(test, 1, t){
		FOR(x, 1, 4) A[x].inp();
		
		sort(A + 1, A + 5);
		
		vector<Point> hull;
		hull.pb(A[1]);
		
		FOR(x, 2, 4){
			while (hull.size() >= 2 && Check_Counterclockwise(hull[int(hull.size()) - 2], hull[int(hull.size()) - 1], A[x])) hull.pop_back();
			hull.pb(A[x]);
		}
		
		FORD(x, 3, 1){
		    if (hull.size() >= 2 && hull[int(hull.size()) - 2].x == A[x].x && hull[int(hull.size()) - 2].y == A[x].y) continue;
			while (hull.size() >= 2 && Check_Counterclockwise(hull[int(hull.size()) - 2], hull[int(hull.size()) - 1], A[x])) hull.pop_back();
			hull.pb(A[x]);
		}
		
		hull.pop_back();
		
		cout << (hull.size() == 4 ? "YES\n" : "NO\n");
	}
	
	return 0;
}
