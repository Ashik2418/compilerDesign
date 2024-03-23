#include<bits/stdc++.h>
using namespace std;
# define int long long
#define opti ios_base::sync_with_stdio(false);
# define mise cin.tie(NULL);
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



void Tokenizer(const string &code,
               int &identifierCount,
               int &keywordCount,
               int &symbolCount,
               int &operatorCount,
               int &integerCount,
               int &floatCount,
               int &exponentialCount) {
    stringstream ss(code);
    string word;

    while (ss >> word) {
        if (isKeyword(word)) {
            keywordCount++;
        } else if (isIdentifier(word)) {
            identifierCount++;
        } else if (isSymbol(word)) {
            symbolCount++;
        } else if (isOperator(word)) {
            operatorCount++;
        } else if (regex_match(word, regex("\\b\\d+\\b"))) { // Integer regex
            integerCount++;
        } else if (regex_match(word, regex("\\b\\d+\\.\\d+\\b"))) { // Float regex
            floatCount++;
        } else if (regex_match(word, regex("\\b\\d+e[-+]?\\d+\\b"))) { // Exponential regex
            exponentialCount++;
        }
    }
}

signed main(){
opti mise
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string code;
    cout << "Enter code: ";
    getline(cin, code);
    cout<<code<<endl;
    stringstream ss(code);
    string word;

    int tokenCount = 0;

    while (ss >> word) {
        tokenCount++;
    }
    int identifierCount = 0, keywordCount = 0, symbolCount = 0, operatorCount = 0;
    int integerCount = 0, floatCount = 0, exponentialCount = 0;

    Tokenizer(code, identifierCount, keywordCount, symbolCount, operatorCount, integerCount, floatCount, exponentialCount);
     vector<string> keywords, identifiers, symbols, operators;
    Tokenizer(code, keywords, identifiers, symbols, operators);

    // Print counts
    cout<<endl;
     cout << "Token count: " << tokenCount << endl;

    cout << "Identifier: " << identifierCount << endl;
    cout<<"Identifiers: ";
    for (const string &word : identifiers) {
        cout << word << " ";
    }
    cout << endl;
    cout << "Keyword: " << keywordCount << endl;
    cout<< "Keywords: ";
    for (const string &word : keywords) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Symbol: " << symbolCount << endl;
    cout<<"Symbols: ";
    for (const string &word : symbols) {
        cout << word << " ";
    }
    cout << endl;
    cout << "Operator: " << operatorCount << endl;
    cout << "Operators: ";
    for (const string &word : operators) {
        cout << word << " ";
    }
    cout<<endl;
    cout << "Integer: " << integerCount << endl;
    cout << "Float: " << floatCount << endl;
    cout << "Exponential: " << exponentialCount << endl;
    return 0;
}

