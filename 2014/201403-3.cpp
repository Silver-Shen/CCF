#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    bool option[26]={0}, para[26]={0};
    string statement;
    char last;
    cin >> statement;
    for (int i=0; i<statement.size(); i++){
        if (statement[i]>='a' && statement[i]<='z'){
            last = statement[i];
            option[last-97] = true;
        }else if (statement[i] == ':') para[last-97] = true;        
    }

    // for (int i=0; i<26; i++)
    //     if (option[i]){
    //         cout << "Option -" << char(i+97) << ':';
    //         if (para[i]) cout << "Parameter\n";
    //         else cout << "Non-Parameter\n"; 
    //     }

    int N;
    string command;    
    cin >> N;
    getline(cin, command);
    for (int i=0; i<N; i++){        
        getline(cin, command);
        cout << "Case " << i + 1 << ":";
        int pointer = 0;
        // filter command name
        while (pointer < command.size() && command[pointer] != ' ') pointer++;
        pointer++;
        // filter non-option command
        if (pointer > command.size()){
            cout << endl;
            continue;
        }
        // analyze option and parameter
        char lastOption = '#';
        bool havePara = false, active[26]={0};
        string parameter[26];
        while (pointer < command.size()){
            // get the substring to analyze
            int j=0;
            while (pointer+j<command.size() && command[pointer+j] != ' ') j++;
            string temp = command.substr(pointer, j);
            if (havePara){ // parameter
                parameter[lastOption-97] = temp;
                lastOption = '#';
                havePara = false;
            }else if (temp.size() == 2 && temp[0] == '-' && option[temp[1]-97]){ // option
                active[temp[1]-97] = true;
                lastOption = temp[1];
                havePara = para[temp[1]-97];
            }else break;
            pointer += j+1;
        }
        for (int i=0; i<26; i++){
            if (active[i]){
                cout << " -" << char(i+97);
                if (para[i]) cout << ' ' << parameter[i];     
            }
        }
        cout << endl;
    }
    return 0;
}