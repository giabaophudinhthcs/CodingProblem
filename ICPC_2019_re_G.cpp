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

int test, n, res, k;
string s, t, s_temp;

int d(int N){
	return 5 * N * N + 4 * N;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> test;
	while (test--){
		res = 0;
		cin >> s;
		n = int(s.len());
		if (n == 1) cout << int(s[0] - '0') - 1 << "\n";
		else if (n == 2){
			s_temp = s;
			if (s == "10"){
				cout << 9 << "\n";
				continue;
			}
			if (s[1] == '0' && s[0] != '1'){
				s_temp[0]--;
				s_temp[1] = '9';
				res++;
			}
			
			res += 9;
			
			char c = '0';
			
			if (s_temp[0] != '1'){
			    res += int(s_temp[0] - '0') + 1;
			    c = '1';
			}
			
			res += int(s_temp[1] - c);
			
			cout << res << "\n";
		}else{
			k = -1;
			s_temp = s;
			bool ok = 1;
			FOR(p, 1, n - 1) ok &= (s[p] == '0');
			if (s[0] == '1' && ok){
				cout << d(n - 1) << "\n";
				continue;
			}
			if (s[0] != '1' && ok){
				s_temp[0]--;
				FOR(p, 1, n - 1) s_temp[p] = '9';
			}
			FOR(p, 1, n - 2){
				if (s_temp[p] != '0'){
					k = p;
					break;
				}
			}
			
			res = d(n - 1);
			
			if (k == -1){
				if (s_temp[0] != '1') res += int(s_temp[0] - '0') + 1;
				
				res += int(s_temp[n - 1] - '0') - 1;
				cout << res << "\n";
				continue;
			}
			
			if (s_temp[0] != '1') res += int(s_temp[0] - '0') + 1;
			FOR(p, 1, n - 2){
				if (p == k) res += int(s_temp[p] - '0');
				if (p > k) res += (int(s_temp[p] - '0') + 1);
			}
			res += int(s_temp[n - 1] - '0');
			if (s[0] != '1' && ok) res++;
			cout << res << "\n";
		}
	}
	return 0;
}
