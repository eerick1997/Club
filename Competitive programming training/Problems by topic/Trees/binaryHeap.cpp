#include <bits/stdc++.h>

using namespace std;

struct MinHeap {
    vector<int> Nodes;
    int numberOfNodes;
    int maxCapacity;

    MinHeap(int _maxCapacity) {
        maxCapacity = _maxCapacity;
        numberOfNodes = 0;
        Nodes.resize(maxCapacity);
    }

    int getParent(int index) {
        return ((index - 1) / 2);
    }

    int getLeft(int index) {
        return 2 * index + 1;
    }

    int getRight(int index) {
        return 2 * index + 2;
    }

    void insert(int key) {
        if(maxCapacity == numberOfNodes) {
            cout << "Overflow: impossible to insert a new key.\n";
            return;
        }
        numberOfNodes++;
        int currentNodeIndex = numberOfNodes - 1;
        Nodes[currentNodeIndex] = key;

        while(numberOfNodes > 0 and Nodes[getParent(currentNodeIndex)] > Nodes[currentNodeIndex]) {
            swap(Nodes[currentNodeIndex], Nodes[getParent(currentNodeIndex)]);
            currentNodeIndex = getParent(currentNodeIndex);
        }
    }

    void minHeapify(int index) {
        int left = getLeft(index);
        int right = getRight(index);
        int smallest = index;
        if(left < numberOfNodes and Nodes[left] < Nodes[smallest])
            smallest = left;
        if(right < numberOfNodes and Nodes[right] < Nodes[smallest])
            smallest = right;

        if(smallest != index) {
            swap(Nodes[smallest], Nodes[index]);
            minHeapify(smallest);
        }
    }

    int getMin() {
        return numberOfNodes > 0 ? Nodes[0] : INT32_MAX;
    }

    int extractMin() {
        
        //Underflow
        if(numberOfNodes <= 0)
            return INT32_MAX;
        
        if(numberOfNodes == 1) {
            numberOfNodes--;
            return Nodes[0];
        }

        int root = Nodes[0];
        Nodes[0] = Nodes[numberOfNodes - 1];
        numberOfNodes--;
        minHeapify(0);

        return root;
    }

    void print() {
        for(int i = 0; i < numberOfNodes; i++) {
            const int node = Nodes[i];
            cout << node << " ";
        }
        
        cout << endl;
    }

};

int main() {
    MinHeap *minheap = new MinHeap(11);
    minheap -> insert(11);
    cout << (minheap -> getMin()) << endl;

    minheap -> insert(3);
    cout << (minheap -> getMin()) << endl;

    minheap -> insert(2);
    cout << (minheap -> getMin()) << endl;

    minheap -> insert(1);
    cout << (minheap -> getMin()) << endl;

    minheap -> insert(15);
    cout << (minheap -> getMin()) << endl;

    minheap -> insert(5);
    cout << (minheap -> getMin()) << endl;

    minheap -> insert(4);
    cout << (minheap -> getMin()) << endl;

    minheap -> insert(45);
    cout << (minheap -> getMin()) << endl;
    
    minheap -> print();
    cout << (minheap -> extractMin()) << endl;
    minheap -> print();
    cout << (minheap -> extractMin()) << endl;
    minheap -> print();
}