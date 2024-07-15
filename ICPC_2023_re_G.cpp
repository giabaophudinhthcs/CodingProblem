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
		int v, pos;
		
		bool operator<(Data O){
			return this->v < O.v;
		}
};

int n, dp[nMax], trace[nMax], Pos, f[nMax], s[nMax];
Data T[nMax];

int cost_4(int p){
	return max(T[p].v - T[p - 1].v, T[p - 2].v - T[p - 3].v) + T[p - 1].v - T[p - 2].v;
}

int cost_6(int p){
	return max(max(T[p - 4].v - T[p - 5].v, T[p - 2].v - T[p - 3].v) + T[p - 3].v - T[p - 4].v, max(T[p - 2].v - T[p - 3].v, T[p].v - T[p - 1].v) + T[p - 1].v - T[p - 2].v);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (1){
		cin >> n;
		if (!n) return 0;
		
		FOR(x, 1, (n << 1)){
			cin >> T[x].v;
			T[x].pos = x;
			f[x] = s[x] = 0;
		}
		
		sort(T + 1, T + (n << 1) + 1);
		
		FOR(x, 1, (n << 1)){
			dp[x] = oo;
			trace[x] = -1;
		}
		
		dp[0] = 0;
		
		for (int x = 2; x <= (n << 1); x += 2){
			if (x >= 4){
				if (dp[x] > max(dp[x - 4], cost_4(x))){
					dp[x] = max(dp[x - 4], cost_4(x));
					trace[x] = x - 4;
				}
			}
			
			if (x >= 6){
				if (dp[x] > max(dp[x - 6], cost_6(x))){
					dp[x] = max(dp[x - 6], cost_6(x));
					trace[x] = x - 6;
				}
			}
		}
		
		Pos = (n << 1);
		while (Pos){
			if (trace[Pos] == Pos - 4){
				f[T[Pos].pos] = T[Pos - 1].pos;
				f[T[Pos - 1].pos] = T[Pos].pos;
				
				f[T[Pos - 2].pos] = T[Pos - 3].pos;
				f[T[Pos - 3].pos] = T[Pos - 2].pos;
				
				s[T[Pos].pos] = T[Pos - 2].pos;
				s[T[Pos - 2].pos] = T[Pos].pos;
				
				s[T[Pos - 1].pos] = T[Pos - 3].pos;
				s[T[Pos - 3].pos] = T[Pos - 1].pos;
			}else{
				f[T[Pos].pos] = T[Pos - 1].pos;
				f[T[Pos - 1].pos] = T[Pos].pos;
				
				f[T[Pos - 2].pos] = T[Pos - 4].pos;
				f[T[Pos - 4].pos] = T[Pos - 2].pos;
				
				f[T[Pos - 3].pos] = T[Pos - 5].pos;
				f[T[Pos - 5].pos] = T[Pos - 3].pos;
				
				s[T[Pos].pos] = T[Pos - 2].pos;
				s[T[Pos - 2].pos] = T[Pos].pos;
				
				s[T[Pos - 1].pos] = T[Pos - 3].pos;
				s[T[Pos - 3].pos] = T[Pos - 1].pos;
				
				s[T[Pos - 4].pos] = T[Pos - 5].pos;
				s[T[Pos - 5].pos] = T[Pos - 4].pos;
			}
			
			Pos = trace[Pos];
		}
		
		FOR(x, 1, (n << 1)) cout << f[x] << " ";
		cout << "\n";
		FOR(x, 1, (n << 1)) cout << s[x] << " ";
		cout << "\n";
	}
	
	return 0;
}
