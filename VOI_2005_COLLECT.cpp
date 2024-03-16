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

class Money{
	public:
		int gold, silver, copper;
		
		int trans_time;
		
		void Inp(){
			this->trans_time = 0;
			cin >> this->gold >> this->silver >> this->copper;
		}
		
		void Out(){
			cout << this->gold << " " << this->silver << " " << this->copper << " " << this->trans_time << "\n";
		}
		
		void Init(int z, int s, int w){
			this->gold = z;
			this->silver = s;
			this->copper = w;
			this->trans_time = 0;
		}
		
		bool operator<(Money Other){
			return (this->gold < Other.gold || (this->gold == Other.gold && this->silver < Other.silver) || (this->gold == Other.gold && this->silver == Other.silver && this->copper < Other.copper) || (this->gold == Other.gold && this->silver == Other.silver && this->copper == Other.copper && this->trans_time < Other.trans_time));
		}
};

int k, z, s, w, z1, z2, s1, s2, w1, w2, visited[5][5][5];
Money Start, Need, A, B, Add;
vector<pair<Money, Money>> Convert;
queue<Money> q;
vector<Money> res;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	Start.Inp();
	Need.Inp();
	
	while (cin >> z1 >> s1 >> w1 >> z2 >> s2 >> w2){
		A.Init(z1, s1, w1);
		B.Init(z2, s2, w2);
		Convert.pb(make_pair(A, B));
	}
	
	q.push(Start);
	
	while (!q.empty()){
		Money Cur = q.front();
		q.pop();
		
		if (Cur.gold >= Need.gold && Cur.silver >= Need.silver && Cur.copper >= Need.copper) res.pb(Cur);
		else{
			for (auto C: Convert){
				if (Cur.gold >= C.ff.gold && Cur.silver >= C.ff.silver && Cur.copper >= C.ff.copper && Cur.trans_time + 1 <= k){
					z = Cur.gold - C.ff.gold + C.ss.gold;
					s = Cur.silver - C.ff.silver + C.ss.silver;
					w = Cur.copper - C.ff.copper + C.ss.copper;
					Add.Init(z, s, w);
					Add.trans_time = Cur.trans_time + 1;
					
					if (z <= 4 && s <= 4 && w <= 4 && !visited[z][s][w]){
						visited[z][s][w] = 1;
						q.push(Add);
					}
				}
			}
		}
	}
	
	if (res.empty()) cout << -1;
	else{
		sort(all(res));
		cout << res.size() << "\n";
		for (auto Collection: res) Collection.Out();
	}
	
	return 0;
}
