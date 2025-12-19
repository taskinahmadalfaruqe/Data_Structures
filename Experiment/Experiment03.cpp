#include <iostream>
#include <stack>
using namespace std;

// Get operator priority
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Perform calculation
int calculate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    string exp = "3*(3+4)";
    stack<int> num;     // operand stack
    stack<char> op;    // operator stack

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // If operand
        if (isdigit(ch)) {
            num.push(ch - '0');
        }
        // Left bracket
        else if (ch == '(') {
            op.push(ch);
        }
        // Right bracket
        else if (ch == ')') {
            while (op.top() != '(') {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                char oper = op.top(); op.pop();
                num.push(calculate(a, b, oper));
            }
            op.pop(); // remove '('
        }
        // Operator
        else {
            while (!op.empty() && priority(op.top()) >= priority(ch)) {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                char oper = op.top(); op.pop();
                num.push(calculate(a, b, oper));
            }
            op.push(ch);
        }
    }

    // Final calculation
    while (!op.empty()) {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char oper = op.top(); op.pop();
        num.push(calculate(a, b, oper));
    }

    cout << "Result: " << num.top() << endl;
    return 0;
}
