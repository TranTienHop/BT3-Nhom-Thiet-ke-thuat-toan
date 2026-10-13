#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

vector<int> adj[MAXN]; 
bool visited[MAXN];    

void bfs(int start_node) {
    queue<int> q;

    q.push(start_node);
    visited[start_node] = true;

    cout << "Ket qua duyet BFS: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void resetVisited(int n) {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

int main() {
    int n, m;
    cout << "Nhap so dinh (n) va so canh (m): ";
    if (!(cin >> n >> m)) return 0;

    cout << "Nhap danh sach " << m << " canh (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int start_node;
    cout << "Nhap dinh bat dau duyet: ";
    cin >> start_node;

    cout << "\n-----------------------------------\n";
   
    resetVisited(n);
    bfs(start_node);

    resetVisited(n);
    cout << "Ket qua duyet DFS: ";
    dfs(start_node);
    cout << "\n";

    return 0;
}