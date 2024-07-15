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

class Fraction{
	public:
		double t, m;
};

int n;
Fraction a[nMax];
double res = 0;
stack<Fraction> S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n){
		cin >> a[x].t;
		res += 1.0 * a[x].t * a[x].t;
	}
	FOR(x, 1, n) cin >> a[x].m;
	FOR(x, 1, n){
		Fraction F;
		F.t = a[x].t * a[x].m;
		F.m = a[x].m * a[x].m;
		while (!S.empty()){
			Fraction G;
			G = S.top();
			if (G.t * F.m >= G.m * F.t) break;
			else{
				F.t += G.t;
				F.m += G.m;
				S.pop();
			}
		}
		S.push(F);
	}
	
	while (!S.empty()){
		Fraction G;
		G = S.top();
		double A = (G.t * G.t) / (1.0 * G.m);
		res -= A;
		S.pop();
	}
	
	cout << fixed << setprecision(10) << res;
	return 0;
}
