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

ll n, Wins = 0, Loses = 0, Ties = 0;
int De = 0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n >> De) De++;
	De--;
	FOR(x, 0, De){
		FOR(y, 0, De){
			int m = min(x, y);
			int M = max(x, y);
			ll a = ((n >> m) + 1) >> 1;
			ll b = ((n >> M) + 1) >> 1;
			if (m & 1) Wins += a * b;
			else{
				if (m == M) Loses += a * b;
				else Ties += a * b;
			}
		}
	}
	cout << Wins << "\n" << Ties << "\n" << Loses;
	return 0;
}
