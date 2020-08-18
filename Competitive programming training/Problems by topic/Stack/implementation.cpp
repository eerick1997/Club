#include <bits/stdc++.h>

struct stack {
    struct node {
        node *previous;
        int value;
        node(int v) {
            previous = nullptr;
            value = v;
        }
    };

    node *top_node;
    int size;

    stack() {
        top_node = nullptr;
        size = 0;
    }

    void push(int v) {
        node *new_node = new node(v);
        if(!size)
            top_node = new_node;
        else 
            new_node -> previous = top_node, top_node = new_node;
        size++;
    }

    void pop() {
        if(!size)
            std::cout << "Stack is empty\n";
        else
            top_node = top_node -> previous;
        size--;
    }

    bool empty() {
        return !size;
    }

    int top() {
        return top_node -> value;
    }
};

int main() {
    stack *Stack = new stack();
    Stack -> push(1);
    Stack -> push(2);
    Stack -> push(3);
    Stack -> push(4);
    Stack -> push(5);

    std::cout << Stack -> top() << std::endl;
    Stack -> pop(); 
    std::cout << Stack -> top() << std::endl;
    Stack -> pop();
    std::cout << Stack -> top() << std::endl;
    Stack -> pop();
    std::cout << Stack -> top() << std::endl;
    Stack -> pop();
    std::cout << Stack -> top() << std::endl;
    Stack -> pop();
    return 0;
}