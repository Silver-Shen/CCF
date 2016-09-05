#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string ISBN;
    cin >> ISBN;
    int pointer[9] = {0,2,3,4,6,7,8,9,10}, code = 0;    
    for (int i=0; i<9; i++) code += (i + 1) * (ISBN[pointer[i]] - 48);
    if (code % 11 == ISBN[12] - 48 || code % 11 == 10 && ISBN[12] == 'X') cout << "Right\n";
    else{
        char last = (code % 11 == 10) ? 'X' : code % 11 + 48;
        ISBN[12] = last;
        cout << ISBN << endl;
    }
    return 0;
}