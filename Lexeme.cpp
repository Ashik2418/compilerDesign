#include<bits/stdc++.h>
using namespace std;
# define int long long
#define opti ios_base::sync_with_stdio(false);
# define mise cin.tie(NULL);
signed main(){
opti mise

    char lexeme[50];
    cout << "Enter a lexeme: ";
    cin >> lexeme;
    bool valid_id = true;
    if (!((lexeme[0] >= 'a' && lexeme[0] <= 'z') || (lexeme[0] >= 'A' && lexeme[0] <= 'Z') || lexeme[0] == '_')) {
        valid_id = false;
    } else {
         for (int i = 1; i < strlen(lexeme); i++) {
            if (!((lexeme[i] >= 'a' && lexeme[i] <= 'z') || (lexeme[i] >= 'A' && lexeme[i] <= 'Z') || (lexeme[i] >= '0' && lexeme[i] <= '9') || lexeme[i] == '_')) {
                valid_id  = false;
                break;
            }
        }
    }
     if (valid_id ) {
        cout << "Valid" <<endl;
    } else {
        cout << "not valid " << endl;
    }

    int lexemeLength = strlen(lexeme);
  cout << "Length of the lexeme: " << lexemeLength <<endl;

    return 0;
}
