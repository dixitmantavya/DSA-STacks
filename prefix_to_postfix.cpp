#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string prefixToPostfix(string &str) {
    stack<string> st;

    
    for (int i = str.size() - 1; i >= 0; i--) {
        char ch = str[i];

        if (isspace(ch)) continue; 

        if (isOperator(ch)) {
        
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

        
            string newExp = op1 + op2 + ch;

        
            st.push(newExp);
        }
        else {
        
            string temp(1, ch);
            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    string str = "*-A/BC-/AKL";  
    cout << "Postfix: " << prefixToPostfix(str) << endl;
    return 0;
}
