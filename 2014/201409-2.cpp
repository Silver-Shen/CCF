#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    bool area[101][101] = {0};
    int n, x1, y1, x2, y2;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for (int k=x1; k<x2; k++)
            for (int l=y1; l<y2; l++) area[k][l] = true;                
    }
    int ans = 0;
    for (int i=0; i<=100; i++)
        for (int j=0; j<100; j++) ans += area[i][j];
    cout << ans << endl;
    return 0;
}