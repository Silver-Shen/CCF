#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int rect[1001], n, length[1001], area = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> rect[i];
        length[i] = 1;
    }
    for (int i=0; i<n; i++){
        int l = i, r = i;
        while (l - 1 >= 0 && rect[l-1]>=rect[i]) l--; 
        while (r + 1 < n && rect[r+1]>=rect[i]) r++;
        if ((r - l + 1) * rect[i] > area) area = (r - l + 1) * rect[i];
    }
    cout << area << endl;
    return 0;
}