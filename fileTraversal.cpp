//Tree Traversal

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <cctype>
#include <algorithm>

class Node {
public:
    std::string data;
    std::vector<Node*> children;

    Node(const std::string& value) : data(value) {}
};

class Tree {
private:
    Node* root;
     int nodeCounter=0;  // Counter for tracking the number of nodes
     int nodeHeight;
    int num_nodes;

    // Helper function for depth-first traversal
    void depthFirstTraversal(Node* node) const {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";

        for (Node* child : node->children) {
            depthFirstTraversal(child);
        }
    }

public:
    Tree() : root(nullptr) {}



    // Function to create a general tree
    // Time complexity: O(m * n), where m is the number of nodes and n is the height of the tree
     void createMockWebGraph() {
        root = new Node("A"); // Root page
        Node* B = new Node("B");
        Node* C = new Node("C");
        Node* D = new Node("D");
        Node* E = new Node("E");
        Node* F = new Node("F");
        Node* G = new Node("G");

        // Constructing the tree
        root->children = {B, C};
        B->children = {D, E};
        C->children = {F, G};
    }
    // Function to get the root node
    // Time complexity: O(1)
    Node* getRoot() const {
        return root;
    }

    // Function to perform breadth-first traversal
    // Time complexity: O(m), where m is the number of nodes in the tree
    void breadthFirstTraversal() const {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        std::cout << "Breadth-First Traversal: ";
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            std::cout << current->data << " ";

            for (Node* child : current->children) {
                q.push(child);
            }
        }

        std::cout << std::endl;
    }

    // Function to perform depth-first traversal
    // Time complexity: O(m), where m is the number of nodes in the tree
    void depthFirstTraversal() const {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        std::cout << "Depth-First Traversal: ";
        depthFirstTraversal(root);
        std::cout << std::endl;
    }
};


int main() {
    const int min_height = 3;
    const int min_nodes = 20;
    const int min_children = 2;

    Tree tree;


    // Create the tree with input validation
    tree.createMockWebGraph();


    // Menu for traversal options
    int choice;
    do {
        std::cout << "\nTraversal Options:\n";
        std::cout << "1. Breadth-First Traversal\n";
        std::cout << "2. Depth-First Traversal\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                tree.breadthFirstTraversal();
                break;
            case 2:
                tree.depthFirstTraversal();
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    return 0;
}