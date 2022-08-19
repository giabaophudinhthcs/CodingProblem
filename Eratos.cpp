#include <bits/stdc++.h>
using namespace std;

const int Max = 1e6 + 10;

bool isPrime[Max];
vector<int> prime;

void eratos(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i <= 1e6; ++i){
		if (isPrime[i]){
			for (int j = i * i; j <= 1e6; j += i) isPrime[j] = false;
		}
	}
	
	for (int i = 0; i <= 1e6; ++i){
		if (isPrime[i]) prime.push_back(i);
	}
}
