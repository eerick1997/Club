#include<bits/stdc++.h>

using namespace std;

struct Graph {
    struct Node {
        vector<char> neighbors;
        int indegree;
        bool visited;
        Node() : visited(false), indegree(0){}
    };

    map<char, Node*> nodes;
    int numberOfVertex;

    Graph() : numberOfVertex(0) {}

    void createNode(char key) {
        if(nodes.find(key) == end(nodes))
            nodes[key] = new Node();
    }

    void join(char from, char to) {
        nodes[from] -> neighbors.push_back(to);
        nodes[to] -> indegree++;
        numberOfVertex++;
    }

    string getOrder() {
        string ans = "";
        int countVertex = 0;

        priority_queue<char, vector<char>, greater<int>> Queue;
        for(auto element : nodes)
            if(element.second -> indegree == 0)
                Queue.push(element.first);
        
        while(!Queue.empty()) {
            char currNode = Queue.top();
            Queue.pop();

            ans += currNode;
            for(char letter : nodes[currNode] -> neighbors) {
                if(--nodes[letter] -> indegree == 0)
                    Queue.push(letter);
            }
            countVertex++;       
        }

        if(numberOfVertex == countVertex)
            return "";

        return ans;
    }

    void printGraph() {
        cout << endl;
        for(auto element : nodes) {
            cout << element.first << " = {";
            for(auto letter : element.second -> neighbors)
                cout << letter << " ";
            cout << "}\n";
        }
        cout << endl;
    }
};



string alienOrder(vector<string> &words) {
    const int size = words.size();
    Graph *graph = new Graph();

    for(string word : words) 
        for(const char letter : word)
            graph -> createNode(letter);
    
    //Building the graph
    for(int i = 0; i < size - 1; i++) {
        const int length = min(words[i].size(), words[i + 1].size());
        bool characterDiffers = false;
        for(int j = 0; j < length; j++) {
            const char charFrom = words[i][j];
            const char charTo = words[i + 1][j];

            if(charFrom != charTo) {
                graph -> join(charFrom, charTo);
                characterDiffers = true;
                break;
            }
        }
        if(!characterDiffers and words[i + 1].size() < words[i].size())
            return "";
    }
    
    return graph -> getOrder();
}


int main() {
    vector<string> words = {"abc", "ab"};//{"wrt","wrf","er","ett","rftt"};//{"zy", "zx"};
    cout << alienOrder(words) << endl;
}