#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, number[1001];
    cin >> n;
    for (int i=0; i<n; i++) cin >> number[i];
    sort(number, number + n);
    int ans = 0;
    for (int i=1; i<n; i++) if (number[i] - number[i-1] == 1) ans++;
    cout << ans << endl;
    return 0;
}