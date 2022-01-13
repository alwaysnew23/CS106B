/**
 * Author: Vincent X
 * Date:   2022-01-12
 */

#include <iostream>

using namespace std;

void permuteHelpler(string s, string chosen);
void permute(string s);

int main() {
    permute("ab");
    
    return 0;
}

void permuteHelpler(string s, string chosen){
    if (s.empty()) {
        cout << chosen << endl;
    } else {
        for (int i = 0; i < s.length(); i++) {
            // choose
            char c = s[i];
            chosen += c;
            s.erase(i, 1);

            // explore
            permuteHelpler(s, chosen);

            // un-choose
            s.insert(i, 1, c);
            chosen.erase(chosen.length() - 1, 1);
        }
    }
}

void permute(string s) {
    permuteHelpler(s, "");
}