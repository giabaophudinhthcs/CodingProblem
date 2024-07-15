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

class Trap{
	public:
		int type, pos;
		ll a, b;
		
		void Inp(){
			cin >> this->a >> this->b;
			
			if (this->a == 0LL && this->b == 0LL) this->type = 1;
			if (this->a == 0LL && this->b > 0LL) this->type = 2;
			if (this->a > 0LL && this->b == 0LL) this->type = 3;
			if (this->a > 0LL && this->b > 0LL) this->type = 4;
		}
};

int n, pos2 = 0, pos4 = 0;
Trap T[nMax];
ll val2 = 0, val3 = 0, val4 = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> n;
	
	FOR(x, 1, n){
		T[x].Inp();
		T[x].pos = x;
		
		if (T[x].type == 2){
			val2 = max(val2, T[x].b);
			if (T[x].b == val2) pos2 = x;
		}
		if (T[x].type == 3) val3 += T[x].a;
		if (T[x].type == 4){
			val4 = max(val4, T[x].b);
			if (T[x].b == val4) pos4 = x;
		}
	}
	
	return 0;
}
