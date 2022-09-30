#include <bits/stdc++.h>

using namespace std;

int n, a[12];
bool used[12];

void printPer(){
    for (int i = 1; i <= n; ++i){
        cout << a[i] << " ";
    }
    cout << "\n"
}

void back(int i){
    for (int j = 1; j <= n; ++j){
        if (!used[j]){
            a[i] = j;
            used[j] = true;
            if (i == n) printPer();
            else back(i + 1);
            used[i] = false;
        }
    }
}

int main(){
    cin >> n;
    back(1);
}
