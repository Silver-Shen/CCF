#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, a[1001];
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int ans = 0, maxNum = 0, i = 0;
    while (i < n){
        int j = i + 1;
        while (j < n && a[j] == a[i]) j++;
        if (j - i > maxNum){
            maxNum = j - i;
            ans = a[i];
        }
        i = j;        
    }
    cout << ans << endl;
    return 0;
}