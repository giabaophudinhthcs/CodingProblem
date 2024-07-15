/*
Calculate Phi Euler function.
Formula to calculate Phi Euler function: https://en.wikipedia.org/wiki/Eul
er%27s_totient_function
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll Phi(ll n){
	ll a = n;
	for (ll i = 2; i * i <= n; ++i){
		if (n % i == 0){
			a /= i;
			a *= (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1){
		a /= n;
		a *= (n - 1);
	}
	return a;
}

int main(){
	ll n;
	cin >> n;
	cout << Phi(n);
}
