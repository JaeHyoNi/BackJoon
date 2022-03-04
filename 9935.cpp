#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str, bomb;
vector<char> temp;

void burst() {
    int bomb_siz = bomb.size(),siz = 0;
    bool flag;
    for (auto K : str) {
        siz++;
        temp.push_back(K);
        if (K == bomb[bomb_siz - 1]) {
            do {
                flag = true;
                if (temp.size() >= bomb_siz) {
                    for (int i = 0; i < bomb_siz; i++) {
                        if (temp[siz - bomb_siz + i] == bomb[i]) continue;
                        else {flag = false;break;}
                    }
                    if (flag) {
                        for (int i = 0; i < bomb_siz; i++) temp.pop_back();
                        siz -= bomb_siz;
                    }
                }
                else { 
                    flag = false; 
                }
            } while (flag == true && !temp.empty());
        }
    }
    if (temp.empty()) cout << "FRULA";
    else {for (auto K : temp) cout << K;}
}


int main() {
    cin >> str;
    cin >> bomb;
    burst();
    return 0;
}
