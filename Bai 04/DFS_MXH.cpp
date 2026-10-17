
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 15;
int n = 14;
int a[MAX][MAX] = {0};
bool visited[MAX];
int parent[MAX];

void themCanh(int u, int v) {
    a[u][v] = 1;
    a[v][u] = 1;
}

void taoDoThi() {
    // Thanh phan lien thong 1: 1 - 7
    themCanh(1, 2);
    themCanh(1, 3);
    themCanh(2, 4);
    themCanh(3, 4);
    themCanh(4, 5);
    themCanh(5, 6);
    themCanh(6, 7);

    // Thanh phan lien thong 2: 8 - 13
    themCanh(8, 9);
    themCanh(8, 10);
    themCanh(9, 11);
    themCanh(10, 12);
    themCanh(11, 12);
    themCanh(12, 13);

    // Dinh 14 khong co canh ket noi
}

void khoiTaoVisited() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void DFS(int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v = 1; v <= n; v++) {
        if (a[u][v] == 1 && !visited[v]) {
            DFS(v);
        }
    }
}

void hienThiMaTran() {
    cout << "\nMA TRAN KE:\n";

    cout << "    ";
    for (int i = 1; i <= n; i++)
        cout << i << "\t";
    cout << endl;

    for (int i = 1; i <= n; i++) {
        cout << i << "\t";
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void thanhPhanLienThong() {
    khoiTaoVisited();
    int dem = 0;

    cout << "\nCAC THANH PHAN LIEN THONG:\n";

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dem++;
            cout << "Thanh phan " << dem << ": ";
            DFS(i);
            cout << endl;
        }
    }

    cout << "Tong so thanh phan lien thong: "
         << dem << endl;
}

void DFS_TimDuong(int u) {
    visited[u] = true;

    for (int v = 1; v <= n; v++) {
        if (a[u][v] == 1 && !visited[v]) {
            parent[v] = u;
            DFS_TimDuong(v);
        }
    }
}

void timDuongDi(int s, int t) {
    if (s < 1 || s > n || t < 1 || t > n) {
        cout << "Nguoi dung khong hop le!\n";
        return;
    }

    khoiTaoVisited();

    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
    }

    DFS_TimDuong(s);

    if (!visited[t]) {
        cout << "Khong ton tai duong di giua "
             << s << " va " << t << endl;
        return;
    }

    vector<int> duongDi;

    for (int v = t; v != -1; v = parent[v]) {
        duongDi.push_back(v);
    }

    reverse(duongDi.begin(), duongDi.end());

    cout << "Ton tai duong di!\n";
    cout << "Duong di: ";

    for (int i = 0; i < (int)duongDi.size(); i++) {
        cout << duongDi[i];

        if (i < (int)duongDi.size() - 1)
            cout << " -> ";
    }

    cout << endl;
}

void hienThiNguoiDung() {
    cout << "\nDANH SACH NGUOI DUNG:\n";

    for (int i = 1; i <= n; i++) {
        cout << "Nguoi dung " << i << endl;
    }
}

int main() {
    taoDoThi();

    int chon, s, t;

    do {
        cout << "\n========== MANG XA HOI ==========\n";
        cout << "1. Hien thi danh sach nguoi dung\n";
        cout << "2. Hien thi ma tran ke\n";
        cout << "3. Duyet do thi bang DFS\n";
        cout << "4. Dem va liet ke thanh phan lien thong\n";
        cout << "5. Tim duong di giua hai nguoi dung\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
            case 1:
                hienThiNguoiDung();
                break;

            case 2:
                hienThiMaTran();
                break;

            case 3:
                khoiTaoVisited();
                cout << "Nhap dinh bat dau: ";
                cin >> s;

                if (s >= 1 && s <= n) {
                    cout << "Thu tu DFS: ";
                    DFS(s);
                    cout << endl;
                } else {
                    cout << "Dinh khong hop le!\n";
                }
                break;

            case 4:
                thanhPhanLienThong();
                break;

            case 5:
                cout << "Nhap nguoi dung bat dau: ";
                cin >> s;
                cout << "Nhap nguoi dung ket thuc: ";
                cin >> t;
                timDuongDi(s, t);
                break;

            case 0:
                cout << "Ket thuc chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;
}
