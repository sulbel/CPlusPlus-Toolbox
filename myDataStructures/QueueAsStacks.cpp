#include <iostream>
#include <stack>

using namespace std;

class myQueue {
    private:
        stack <int> inStack;
        stack <int> outStack;

    private:
        void fillQueue();

    public:
        // myQueue();
        void peekFront();
        void myEnqueue(int);
        int myDequeue();
        int queueSize();
        bool isEmpty();
};

// print the element at the front of the queue
void myQueue::peekFront() {
    // ensure that outStack has some content
    if (isEmpty()) {
        fillQueue();
    }
    cout << "At the front of the queue: " << outStack.top() << endl;
    return;
}

// adds a value to the queue, via pushing the value to inStack
void myQueue::myEnqueue(int value) {
    //cout << "Inserting " << value << " to inStack." << endl;
    inStack.push(value);
}

// transfer contents of inStack to outStack
void myQueue::fillQueue() {
    // only fill the queue if outStack is empty
    if (isEmpty()) {
        if (inStack.empty()) {
            cout << "There has not been any input!" << endl;
            return;
        }
        else {
            while (!inStack.empty()) {
                //cout << "Pushing " << inStack.top() << " to the output stack." << endl;
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
}

// removes the value from the front of the queue
int myQueue::myDequeue() {
    // ensure that outStack has some content
    if (isEmpty()) {
        fillQueue();
    }
    // now that outStack has some elements, we can dequeue the element at the front of the queue
    cout << "Dequeueing element " << outStack.top() << endl;
    int returnVal = outStack.top();
    outStack.pop();
    return returnVal;
}

// returns the size of the queue
int myQueue::queueSize() {
    // ensure that outStack has some content
    if (isEmpty()) {
        fillQueue();
    }
    return (outStack.size());
}

// returns true (1) if outStack has no contents
bool myQueue::isEmpty() {
    return (outStack.empty());
}

int main() {
    myQueue myQ;
    for (int n = 1; n < 6; n++) {
        myQ.myEnqueue(n);
    }

    myQ.peekFront();
    cout << "The queue has size: " << myQ.queueSize() << endl;

    int frontOfQueue;
    frontOfQueue = myQ.myDequeue();
    //cout << "Obtained frontOfQueue value: " << frontOfQueue << endl;

    while (!myQ.isEmpty()) {
        frontOfQueue = myQ.myDequeue();
    }
    
    return 0;
}