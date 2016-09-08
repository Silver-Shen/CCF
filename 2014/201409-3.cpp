#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    bool sensitive;
    string origin, target;
    cin >> origin;
    cin >> sensitive;
    if (!sensitive) transform(origin.begin(), origin.end(), origin.begin(), ::tolower);
    int n ;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> target;
        string backup = target;
        if (!sensitive) transform(target.begin(), target.end(), target.begin(), ::tolower); 
        if (target.find(origin) != string::npos) cout << backup << endl;
    }
    return 0;
}