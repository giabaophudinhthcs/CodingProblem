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
		ll x, y, z;
		
		void Inp(){
			cin >> this->x >> this->y >> this->z;
		}
};

ll a, b, c, Vol;
int m;
bool res;
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
		
		res = true;
		
		FOR(p, 1, m) C[p].Inp();
		FOR(p, 1, m){
			L[p].Inp();
			R[p].Inp();
		}
		
		FOR(p, 1, m){
			bool ok1, ok2, ok3;
			ok1 = (1 <= L[p].x) && (L[p].x <= R[p].x) && (R[p].x <= a);
			ok2 = (1 <= L[p].y) && (L[p].y <= R[p].y) && (R[p].y <= b);
			ok3 = (1 <= L[p].z) && (L[p].z <= R[p].z) && (R[p].z <= c);
			
			res &= (ok1 && ok2 && ok3);
		}
		
		FOR(p, 1, m){
			bool ok1, ok2, ok3;
			ok1 = (L[p].x <= C[p].x) && (C[p].x <= R[p].x);
			ok2 = (L[p].y <= C[p].y) && (C[p].y <= R[p].y);
			ok3 = (L[p].z <= C[p].z) && (C[p].z <= R[p].z);
			
			res &= (ok1 && ok2 && ok3);
		}
		
		FOR(i, 1, m - 1){
			FOR(j, i + 1, m){
				bool ok1, ok2, ok3;
				ok1 = (R[i].x < L[j].x || R[j].x < L[i].x);
				ok2 = (R[i].y < L[j].y || R[j].y < L[i].y);
				ok3 = (R[i].z < L[j].z || R[j].z < L[i].z);
				
				res &= (ok1 || ok2 || ok3);
			}
		}
		
		Vol = 0LL;
		
		FOR(p, 1, m){
			ll dx, dy, dz;
			dx = R[p].x - L[p].x + 1;
			dy = R[p].y - L[p].y + 1;
			dz = R[p].z - L[p].z + 1;
			
			Vol += (dx * dy * dz);
		}
		
		res &= (Vol == (a * b * c));
		
		cout << (res ? "YES\n" : "NO\n");
	}
	
	return 0;
}
