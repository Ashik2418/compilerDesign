#include<bits/stdc++.h>
using namespace std;
# define int long long
#define opti ios_base::sync_with_stdio(false);
# define mise cin.tie(NULL);
#include <string>
#include <vector>
#include <sstream>
#include <set>
bool isIdentifier(const string &word) {
    return (isalpha(word[0]) || word[0] == '_');
}

bool isSymbol(const string &word) {
    return word.size() == 1 && (word.find_first_of("{}()[];,.:'\"") != string::npos);
}

bool isOperator(const string &word) {
    return (word == "<<" || word.find_first_of("=+-*/%<>!&|^~?:") != string::npos);
}

bool isKeyword(const string &word) {
    static const set<string> keywordSet = {"break", "char", "continue", "do", "double", "else", "float", "for",
                                           "if", "int", "long", "return", "while", "cout", "cin", "endl"};

    return keywordSet.find(word) != keywordSet.end();
}

void Tokenizer(const string &code,
               vector<string> &keywords,
               vector<string> &identifiers,
               vector<string> &symbols,
               vector<string> &operators) {
               stringstream ss(code);
               string word;
               set<string> matching;

    while (ss >> word) {
        if (matching.insert(word).second) {
            if (isKeyword(word)) {
                keywords.push_back(word);
            } else if (isIdentifier(word)) {
                identifiers.push_back(word);
            } else if (isSymbol(word)) {
                symbols.push_back(word);
            } else if (isOperator(word)) {
                operators.push_back(word);
            }
        }
    }
}

signed main(){
opti mise
    string code;
    cout << "Enter -->> " << endl;
    cout << "Enter code: ";
    getline(cin, code);

    vector<string> keywords, identifiers, symbols, operators;
    Tokenizer(code, keywords, identifiers, symbols, operators);

    cout << "Keywords: ";
    for (const string &word : keywords) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Identifiers: ";
    for (const string &word : identifiers) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Symbols: ";
    for (const string &word : symbols) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Operators: ";
    for (const string &word : operators) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
