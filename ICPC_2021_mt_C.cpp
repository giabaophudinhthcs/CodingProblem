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

class Data_Pack{
	public:
		double val;
		int left;
		int right;		
};

int n;
double a[nMax], s[nMax], res = 0.0;
stack<Data_Pack> S;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	s[0] = 0.0;
	FOR(x, 1, n){
		cin >> a[x];
		s[x] = s[x - 1] + a[x];
		res += (1.0 * a[x] * a[x]);
	}
	
	FOR(x, 1, n){
		Data_Pack T;
		T = {a[x], x, x};
		
		while (!S.empty() && S.top().val > T.val){
			T.left = S.top().left;
			T.val = (1.0 * (s[x] - s[T.left - 1])) / (1.0 * (x - T.left + 1));
			S.pop();
		}
		
		S.push(T);
	}
	
	while (!S.empty()){
		Data_Pack DP;
		DP = S.top();
		res += (1.0 * (DP.right - DP.left + 1) * DP.val * DP.val) - 2.0 * DP.val * (s[DP.right] - s[DP.left - 1]);
		S.pop();
	}
	
	res = sqrt(res);
	cout << fixed << setprecision(9) << res;
	return 0;
}
