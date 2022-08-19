#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    	map<int, bool> visited;
    	map<int, vector<int>> adj;
    	map<int, int> previous;
    	void addEdge(int v1, int v2);
    	void dfsPathfinding(int v);
    	void printPath(map<int, int> p, int start, int end);
};

void graph::addEdge(int v1, int v2){
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

void graph::dfsPathfinding(int v){
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); ++i){
        if (!visited[adj[v][i]]) previous[adj[v][i]] = v;
        dfsPathfinding(adj[v][i]);
    }
}

void graph::printPath(map<int, int> p, int start, int end){
    if (!p[end]){
        cout << "Khong co duong di tu dinh so " << start << " den dinh so " << end << " :((\n";
        cout << "dak dak buh buh lmao";
        return;
    }
    cout << "Duong di tu dinh so " << start << " den dinh so " << end << ": ";
    int i = end;
    stack<int> way;
    way.push(i);
    while (p[i] != start){
        i = p[i];
        way.push(i);
    }
    while (!way.empty()){
        cout << way.top() << " -> ";
        way.pop();
    }
}

int main(){
    // Driver code
}
