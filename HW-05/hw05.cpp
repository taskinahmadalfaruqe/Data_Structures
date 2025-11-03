#include <iostream>
using namespace std;

template<typename T>
class BothStack {
private:
    T* array;
    int capacity;
    int top1;
    int top2;
public:
    BothStack(int size) {
        capacity = size;
        array = new T[capacity];
        top1 = -1;
        top2 = capacity;
    }
    ~BothStack() {
        delete[] array;
    }
    void Push(int i, T x) {
        if (top1 + 1 == top2) {
            cout << "BothStack is full!" << endl; 
            return;
        }
        if (i == 1) {
            top1++;
            array[top1] = x;
        } else if (i == 2) {
            top2--;
            array[top2] = x;
        } else {
            cout << "Invalid stack number! Use 1 or 2." << endl;
        }
    }
    T Pop(int i) {
        if (i == 1) {
            // Pop from stack 1
            if (top1 == -1) {
                cout << "Stack 1 is empty!" << endl;
                return T();
            }
            T value = array[top1];
            top1--;
            return value;
        } else if (i == 2) {
            // Pop from stack 2
            if (top2 == capacity) {
                cout << "Stack 2 is empty!" << endl;
                return T();
            }
            T value = array[top2];
            top2++;
            return value;
        } else {
            cout << "Invalid stack number! Use 1 or 2." << endl;
            return T();
        }
    }
    bool IsEmpty(int i) {
        if (i == 1) return top1 == -1;
        if (i == 2) return top2 == capacity;
        return true;
    }
    void Display() {
        cout << "BothStack contents:" << endl;

        cout << "Stack 1 (left): ";
        if (top1 == -1) {
            cout << "empty";
        } else {
            for (int i = 0; i <= top1; i++) {
                cout << array[i] << " ";
            }
        }
        cout << endl;

        cout << "Stack 2 (right): ";
        if (top2 == capacity) {
            cout << "empty";
        } else {
            for (int i = capacity - 1; i >= top2; i--) {
                cout << array[i] << " ";
            }
        }
        cout << endl;
        cout << "Full array: ";
        for (int i = 0; i < capacity; i++) {
            if (i <= top1) {
                cout << array[i] << " ";
                // Stack 1 elements
            } else if (i >= top2) {
                cout << array[i] << " ";
                // Stack 2 elements
            } else {
                cout << "_ ";
                // Empty space
            }
        }
        cout << endl;
    }
};

int main() {
    BothStack<int> stack(10);

    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {7, 8, 9, 10, 11};

    cout << "Pushing [1,2,3,4,5] to Stack 1..." << endl;
    for (int i = 0; i < 5; i++) {
        stack.Push(1, array1[i]);
    }

    cout << "Pushing [7,8,9,10,11] to Stack 2..." << endl;
    for (int i = 0; i < 5; i++) {
        stack.Push(2, array2[i]);
    }

    cout << endl;
    stack.Display();
    cout << "\nPopping one element from each stack:" << endl;
    cout << "Popped from Stack 1: " << stack.Pop(1) << endl;
    cout << "Popped from Stack 2: " << stack.Pop(2) << endl;

    cout << "\nAfter popping:" << endl;
    stack.Display();

    return 0;
}