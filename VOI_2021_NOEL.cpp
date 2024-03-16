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

class Data{
	public:
		int x, y;
		
		bool 
};

int n, d, a[2005], pos[2005], res = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d;
	FOR(x, 1, 2 * n){
		cin >> a[x];
		pos[a[x]] = x;
	}
	
	FOR(Border, 1, 2 * n - 1){
		int cnt = 0;
		ii pos_pair[20005];
		
		FOR(x, 1, Border){
			pos_pair[++cnt].ff = 
		}
	}
	
	return 0;
}
