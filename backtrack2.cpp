#include <bits/stdc++.h>

using namespace std;

int n;
bool use[22];

void printPer(){
    for (int i = 1; i <= n; ++i){
        if (use[i]) cout << i < " ";
    }
    cout << "\n";
}

void back(int i){
    for (int j = 1; j <= n; ++j){
        used[j] = false;
        if (i == n) printPer();
        else back(i + 1);
        used[j] = true;
        if (i == n) printPer();
        else back(i + 1);
    }
}

int main(){
    cin >> n;
    back(1);
    return 0;
}
