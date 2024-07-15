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
typedef unsigned long long ull;
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
		int x, y, z, id;
		
		void Inp(){
			cin >> this->x >> this->y >> this->z;
		}
		
		void Out(){
			cout << this->x << " " << this->y << " " << this->z << " ";
		}
		
		bool operator<(Point O) const {
			return (this->x < O.x) || (this->x == O.x && this->y < O.y) || (this->x == O.x && this->y == O.y && this->z < O.z);
		}
};

int a, b, c, m, cnt = 0, l, r;
Point C[1005], L[1005], R[1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	while (1){
		cin >> a;
		
		if (a == -1LL) return 0;
		
		cin >> b >> c >> m;
		
		FOR(p, 1, m){
			C[p].Inp();
			C[p].id = p;
		}
		
		cout << "YES\n";
		
		sort(C + 1, C + m + 1);
		
		cnt = 0;
		
		// Ox
		FOR(p, 1, m){
			if (p == 1){
				l = 1;
				L[C[1].id].x = 1;
			}else if (C[p].x > C[p - 1].x){
				r = p - 1;
				FOR(pp, l, r){
					L[C[pp].id].x = L[C[l].id].x;
					R[C[pp].id].x = C[p].x - 1;
				}
				
				L[C[p].id].x = C[p].x;
				l = p;
			}
		}
		FOR(pp, l, m){
			L[C[pp].id].x = L[C[l].id].x;
			R[C[pp].id].x = a;
		}
		
		// Oy
		FOR(p, 1, m){
			if (p == 1){
				l = 1;
				L[C[1].id].y = 1;
			}else if (C[p].x == C[p - 1].x && C[p].y > C[p - 1].y){
				r = p - 1;
				FOR(pp, l, r){
					L[C[pp].id].y = L[C[l].id].y;
					R[C[pp].id].y = C[p].y - 1;
				}
				
				L[C[p].id].y = C[p].y;
				l = p;
			}else if (C[p].x > C[p - 1].x){
				r = p - 1;
				FOR(pp, l, r){
					L[C[pp].id].y = L[C[l].id].y;
					R[C[pp].id].y = b;
				}
				
				L[C[p].id].y = 1;
				l = p;
			}
		}
		FOR(pp, l, m){
			L[C[pp].id].y = L[C[l].id].y;
			R[C[pp].id].y = b;
		}
		
		// Oz
		FOR(p, 1, m){
			if (p == 1){
				l = 1;
				L[C[1].id].z = 1;
			}else if (C[p].x == C[p - 1].x && C[p].y == C[p - 1].y && C[p].z > C[p - 1].z){
				r = p - 1;
				FOR(pp, l, r){
					L[C[pp].id].z = L[C[l].id].z;
					R[C[pp].id].z = C[p].z - 1;
				}
				
				L[C[p].id].z = C[p].z;
				l = p;
			}else if ((C[p].x == C[p - 1].x && C[p].y > C[p - 1].y) || (C[p].x > C[p - 1].x)){
				r = p - 1;
				FOR(pp, l, r){
					L[C[pp].id].z = L[C[l].id].z;
					R[C[pp].id].z = c;
				}
				
				L[C[p].id].z = 1;
				l = p;
			}
		}
		FOR(pp, l, m){
			L[C[pp].id].z = L[C[l].id].z;
			R[C[pp].id].z = c;
		}
		
		// Print
		FOR(p, 1, m){
			L[p].Out();
			R[p].Out();
			cout << "\n";
		}
	}
	
	return 0;
}
