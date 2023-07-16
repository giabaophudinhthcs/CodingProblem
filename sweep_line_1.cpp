// Sweep line 1: Find the distance of the closest pair of point (in Euclid distance)

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
const ll MOD = 1e9 + 7LL;
const ll MODLL = 1e18 + 7LL;
const int oo = 2e9 + 10LL;
const ll ooll = 2e18 + 10LL;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

class Point{
	public:
		ll x, y;
		
		bool operator<(Point A){
			return (this->x < A.x || (this->x == A.x && this->y < A.y));
		}
		
		void inp(){
			cin >> this->x >> this->y;
		}
};

class cmp{
    public:
        bool operator () (const Point& a, const Point& b) const {
            if (a.y != b.y) return a.y < b.y;
            return a.x < b.x;
        }
};

ll sqr_dist(Point A, Point B){
	return ((A.x - B.x) * (A.x - B.x)) + ((A.y - B.y) * (A.y - B.y));
}

int n;
ll sqr_res;
Point p[nMax];
set<Point, cmp> S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n) p[x].inp();
	sqr_res = sqr_dist(p[1], p[2]);
	sort(p + 1, p + n + 1);
	FOR(x, 1, n){
		ll d = sqrt(sqr_res);
		Point T;
		T.x = -1000001LL;
		T.y = p[x].y - d;
		
		while (1){
			auto it = S.upper_bound(T);
			
			if (it == S.end()) break;
			
			T = *it;
			if (T.y > p[x].y + d) break;
			
			if (T.x < p[x].x - d){
				S.erase(it);
				continue;
			}
			
			sqr_res = min(sqr_res, sqr_dist(p[x], T)); 
		}
		
		S.insert(p[x]);
	}
	cout << fixed << setprecision(6) << sqrt(sqr_res);
	return 0;
}
