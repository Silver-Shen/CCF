#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int number[1001]={0}, n, ans = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        number[int(abs(temp))]++;
    }
    for (int i=0; i<1001; i++) if (number[i] > 1) ans++;
    cout << ans << endl;
    return 0;
}