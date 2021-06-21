#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<int> stack1;
    stack1.push(4);
    stack1.push(2);
    stack1.push(1);
    stack1.push(3);
    cout << "stack1.top() = " << stack1.top() << endl;

    stack<int> stack2;

    while(stack1.size() != 0) {
        int holder = stack1.top();
        // cout << "holder: " << holder << endl;
        // cout << "stack1.size() == " << stack1.size() << endl;
        stack1.pop();
        if (stack2.size() == 0) {
            // cout << "Placing " << holder << " in stack2" << endl;
            stack2.push(holder);
        }
        // stack 2 is not empty, check if we can place holder on top or need to sort
        else {
            if(holder < stack2.top()) {
                // cout << "Holder: " << holder << " is less than stack2.top() " << stack2.top() << endl;
                stack2.push(holder);
            }
            // need to sort stack 2 before placing holder
            else {
                while(stack2.size() > 0 && holder > stack2.top()) {
                    // cout << "Removing " << stack2.top() << " from stack2" << endl;
                    int topS2 = stack2.top();
                    stack2.pop();
                    // cout << "stack2.size() " << stack2.size() << endl;
                    stack1.push(topS2);
                    if(stack2.size() == 0) {
                        break;
                    }
                }
                // cout << "Placing " << holder << " in stack2" << endl;
                stack2.push(holder);
            }
        }
        // cout << "stack1 size: " << stack1.size() << endl;
        // cout << "stack2 size: " << stack2.size() << endl;
    }
    cout << "Stack 2 contents: " << endl;
    while(stack2.size() != 0) {
        cout << stack2.top() << endl;
        stack2.pop();
    }

    return 0;
}