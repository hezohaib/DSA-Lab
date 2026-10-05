#include <iostream>
#include <string>
using namespace std;

// Node for stack
struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    void push(char c) {
        Node* newNode = new Node();
        newNode->data = c;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == NULL) {
            return '\0'; // empty stack
        }
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return top == NULL;
    }

    char peek() {
        if (top == NULL) return '\0';
        return top->data;
    }
};

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // opening bracket aaya to push kar do
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // closing bracket aaya
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false; // koi opening nahi mila
            }
            char topChar = s.pop();
            if (!isMatching(topChar, ch)) {
                return false; // matching nahi hua
            }
        }
    }

    // last mein stack empty hona chahiye
    return s.isEmpty();
}

int main() {
    string exp;

    cout << "Enter expression with brackets: ";
    cin >> exp;

    if (isBalanced(exp)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}