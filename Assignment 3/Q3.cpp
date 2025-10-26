#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return '\0';
        }
        Node* temp = top;
        char value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isPalindrome(const string& str) {
    Stack s;

    for (char c : str) {
        s.push(c);
    }

    string reversed_str = "";
    while (!s.isEmpty()) {
        reversed_str += s.pop();
    }

    return str == reversed_str;
}

int main() {
    string input;
    cout << "Enter a string to check if it is a palindrome: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
