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

string Message, s;
int n, ok[6], res = 1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (cin >> s) Message += (s + " ");
	n = int(Message.len());
	
	// Welcome
	FOR(p, 6, n - 1){
		int check = 1;
		check &= (Message[p - 6] == 'W');
		check &= (Message[p - 5] == 'e');
		check &= (Message[p - 4] == 'l');
		check &= (Message[p - 3] == 'c');
		check &= (Message[p - 2] == 'o');
		check &= (Message[p - 1] == 'm');
		check &= (Message[p] == 'e');
		ok[1] |= check;
	}
	
	// Hue
	FOR(p, 2, n - 1){
		int check = 1;
		check &= (Message[p - 2] == 'H');
		check &= (Message[p - 1] == 'u');
		check &= (Message[p] == 'e');
		ok[2] |= check;
	}
	
	// University
	FOR(p, 9, n - 1){
		int check = 1;
		check &= (Message[p - 9] == 'U');
		check &= (Message[p - 8] == 'n');
		check &= (Message[p - 7] == 'i');
		check &= (Message[p - 6] == 'v');
		check &= (Message[p - 5] == 'e');
		check &= (Message[p - 4] == 'r');
		check &= (Message[p - 3] == 's');
		check &= (Message[p - 2] == 'i');
		check &= (Message[p - 1] == 't');
		check &= (Message[p] == 'y');
		ok[3] |= check;
	}
	
	// of
	FOR(p, 1, n - 1){
		int check = 1;
		check &= (Message[p - 1] == 'o');
		check &= (Message[p] == 'f');
		ok[4] |= check;
	}
	
	// Sciences
	FOR(p, 7, n - 1){
		int check = 1;
		check &= (Message[p - 7] == 'S');
		check &= (Message[p - 6] == 'c');
		check &= (Message[p - 5] == 'i');
		check &= (Message[p - 4] == 'e');
		check &= (Message[p - 3] == 'n');
		check &= (Message[p - 2] == 'c');
		check &= (Message[p - 1] == 'e');
		check &= (Message[p] == 's');
		ok[5] |= check;
	}
	
	FOR(p, 1, 5) res &= ok[p];
	cout << (res ? "Yes" : "No");
	return 0;
}
