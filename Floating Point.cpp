#include<bits/stdc++.h>
using namespace std;
# define int long long
#define opti ios_base::sync_with_stdio(false);
# define mise cin.tie(NULL);
enum State {
    A,
    B,
    C,
    D,
    E
};

bool floatingPoint(string lexeme) {
    State currentState = A;

    for (char ch : lexeme) {
        switch (currentState) {
            case A:
                if (isdigit(ch)) {
                    currentState = B;
                } else if (ch == '.') {
                    currentState = C;
                }
                else {
                    return false;
                }
                break;

            case B:
                if (isdigit(ch)) {
                } else if (ch == '.') {
                    currentState = C;
                } else {
                    return false;
                }
                break;

            case C:
                if (isdigit(ch)) {
                    currentState = E;
                } else {
                    return false;
                }
                break;

            case D:
                if (isdigit(ch)) {
                    currentState = E;
                } else {
                    return false;
                }
                break;

            case E:
                if (isdigit(ch)) {
                } else {
                    return false;
                }
                break;
        }
    }

    return currentState == B || currentState == E;
}
signed main(){
opti mise
    string i;

    cout << "Enter a lexeme: ";
    cin >> i;

    if (floatingPoint(i)) {
        cout << "Valid floating-point number!" << endl;
    } else {
        cout << "Not a valid floating-point number." << endl;
    }

    return 0;
}
