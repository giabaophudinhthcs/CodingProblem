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

int n, v, q;
ll s = 0LL;
map<int, int> Even, Odd;
string Query;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(p, 1, n){
		cin >> v;
		s += v;
		if (v & 1) Odd[v]++;
		else Even[v]++;
	}
	
	cin >> Query;
	q = int(Query.len());
	
	FOR(t, 0, q - 1){
	    map<int, int> New;
		if (Query[t] == '0'){
			
			for (auto [v, cnt]: Even){
				int V = v >> 1;
				s -= (long long)V * cnt;
				
				if (V & 1) Odd[V] += cnt;
				else New[V] += cnt;
			}
			
			Even = New;
		}else{
			for (auto [v, cnt]: Odd){
				int V = v - 1;
				Even[V] += cnt;
				s -= cnt;
			}
			
			Odd = New;
		}
		
		cout << s << "\n";
	}
	return 0;
}
