#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int n;               
int A[MAXN][MAXN];    
int B[MAXN][MAXN];      
int f[MAXN];             
bool used[MAXN];          
bool found = false;

bool check(int u, int v) {
    for (int i = 1; i < u; i++) {
        if (A[i][u] != B[f[i]][v]) return false;
    }
    return true;
}

void backtrack(int u) {
    if (found) return;
    if (u > n) {
        bool ok = true;
        for (int i = 1; i <= n && ok; i++)
            for (int j = 1; j <= n; j++)
                if (A[i][j] != B[f[i]][f[j]]) {
                    ok = false;
                    break;
                }
        if (ok) found = true;
        return;
    }

    for (int v = 1; v <= n; v++) {
        if (!used[v] && check(u, v)) {
            f[u] = v;
            used[v] = true;
            backtrack(u + 1);
            if (found) return;
            used[v] = false;
        }
    }
}

void inputGraph(int G[MAXN][MAXN], string name, int &m) {
    cout << "Nhap so dinh cua " << name << ": ";
    cin >> n;
    cout << "Nhap so canh cua " << name << ": ";
    cin >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = 0;
    cout << "Nhap " << m << " canh (u v):\n";
    for (int k = 0; k < m; k++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1; 
    }
}

int main() {
    int m1, m2;

    cout << "=== DO THI G1 ===\n";
    inputGraph(A, "G1", m1);

    cout << "\n=== DO THI G2 ===\n";
    int n1 = n;
    inputGraph(B, "G2", m2);
    int n2 = n;

    if (n1 != n2) {
        cout << "\n=> Hai do thi KHONG dang cau (khac so dinh).\n";
        return 0;
    }
    if (m1 != m2) {
        cout << "\n=> Hai do thi KHONG dang cau (khac so canh).\n";
        return 0;
    }

    vector<int> deg1, deg2;
    for (int i = 1; i <= n; i++) {
        int d1 = 0, d2 = 0;
        for (int j = 1; j <= n; j++) {
            d1 += A[i][j];
            d2 += B[i][j];
        }
        deg1.push_back(d1);
        deg2.push_back(d2);
    }
    sort(deg1.begin(), deg1.end());
    sort(deg2.begin(), deg2.end());
    if (deg1 != deg2) {
        cout << "\n=> Hai do thi KHONG dang cau (khac bac dinh).\n";
        return 0;
    }

    n = n1;
    for (int i = 1; i <= n; i++) used[i] = false;
    backtrack(1);

    if (found) {
        cout << "\n=> Hai do thi DANG CAU!\n";
        cout << "Ham song anh f:\n";
        for (int i = 1; i <= n; i++)
            cout << "  f(" << i << ") = " << f[i] << "\n";
    } else {
        cout << "\n=> Hai do thi KHONG dang cau.\n";
    }

    return 0;
}
