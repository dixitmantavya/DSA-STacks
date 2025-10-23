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

int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    return 0;
}

int eval(string &str){
    stack<int> st;
    stack<char> op;

    for (int i = 0; i < str.size(); i++){
        char ch = str[i];

        if (ch == ' ') continue; 

        if (isdigit(ch)){
            st.push(ch - '0');
        }
        else if (ch == '('){
            op.push(ch);
        }
        else if (ch == ')'){
            while(!op.empty() && op.top() != '('){
                char ops = op.top(); op.pop();
                int v1 = st.top(); st.pop();
                int v2 = st.top(); st.pop();
                st.push(calc(v2, v1, ops));
            }
            if (!op.empty()) op.pop(); 
        }
        else { 
            while(!op.empty() && precedence(op.top()) >= precedence(ch)){
                char ops = op.top(); op.pop();
                int v1 = st.top(); st.pop();
                int v2 = st.top(); st.pop();
                st.push(calc(v2, v1, ops));
            }
            op.push(ch);
        }
    }

    while(!op.empty()){
        char ops = op.top(); op.pop();
        int v1 = st.top(); st.pop();
        int v2 = st.top(); st.pop();
        st.push(calc(v2, v1, ops));
    }

    return st.top();
}

int main(){
    string expr = "1+(2*(3-1))+2";
    cout << eval(expr) << endl;
    return 0;
}
