#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    double data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = NULL; }

    void push(double val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    double pop() {
        if (top == NULL) return 0;
        double val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

double evaluatePostfix(string postfix) {
    Stack s;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        // number hai
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0'); // character ko number bana diya
        }
        // operator aaya
        else {
            double b = s.pop(); // pehle second operand
            double a = s.pop(); // phir first operand

            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }

    return s.pop(); // final result
}

int main() {
    string postfix;

    cout << "Enter Postfix expression (single digits only): ";
    cin >> postfix;

    double result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}