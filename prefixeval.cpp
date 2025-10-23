#include <iostream>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

int calc(int x, int y, char op) {
    switch (op) {
        case '^': return pow(x, y);
        case '*': return x * y;
        case '/': return x / y;
        case '+': return x + y;
        case '-': return x - y;
        default:
            cout << "Invalid operator: " << op << endl;
            return 0;
    }
}

int eval(string &str) {
    stack<int> st;


    for (int i = str.size() - 1; i >= 0; i--) {
        char ch = str[i];

        if (isdigit(ch)) {
            st.push(ch - '0');
        } 
        else {
            
            int v1 = st.top(); st.pop();
            int v2 = st.top(); st.pop();

            int ans = calc(v2, v1, ch);
            st.push(ans);
        }
    }

    return st.top();
}

int main() {
    string str = "-9+*132";  
    cout << eval(str) << endl;
    return 0;
}
