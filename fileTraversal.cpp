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
    void createTree(int min_height, int min_nodes, int min_children) {

        do {
            // Read the number of nodes from the user
            std::cout << "Enter the number of nodes (>= " << min_nodes << "): ";
            std::cin >> num_nodes;

            // Validate user input
            if (std::cin.fail() || num_nodes < min_nodes) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a non-negative integer greater than or equal to " << min_nodes << ".\n";
            } else {
                break;
            }
        } while (nodeCounter < num_nodes && nodeHeight <= min_height);

        std::string value;
        std::cout << "Enter the value for the root node: ";
        std::cin >> value;
        root = new Node(value);


        std::queue<Node*> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) {
            Node* current = levelQueue.front();
            levelQueue.pop();

            int numChildren;
            do {
                if(nodeCounter >= num_nodes && nodeHeight > min_height ){
                // Inform the user about the conditions being met
                std::cout << std::endl << "The conditions are met! Press O to stop or " << std::endl;
                }


                std::cout << "Enter the number of children for node " << current->data << " (>= " << min_children << "): ";
                std::cin >> numChildren;
                nodeHeight++; // Increment the counter for the height


                std::cout << std::endl<< "Current nodeCounter: " << nodeCounter << std::endl;
                std::cout << "Current nodeHeight: " << nodeHeight << std::endl;



                if (std::cin.fail() || numChildren < min_children) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a non-negative integer greater than or equal to " << min_children << ".\n";
                } else {
                    break;
                }
                } while (nodeCounter < num_nodes && nodeHeight <= min_height);






                if (nodeCounter >= num_nodes && nodeHeight > min_height && numChildren == 0) {

                std::cout << "Breaking out of the loop as nodeCounter >= num_nodes and nodeHeight > min_height.\n" << std::endl;
                break;
            }

            for (int i = 0; i < numChildren; ++i) {
                std::string childValue;
                do {
                    std::cout << "Enter the value for child " << i + 1 << " of node " << current->data << ": ";

                    nodeCounter++;  // Increment the counter for the root node
                    std::cin >> childValue;

                    if (std::cin.fail() || !std::all_of(childValue.begin(), childValue.end(), ::isalnum)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid input. Please enter a string containing only letters and numbers.\n";
                    } else {
                        break;
                    }
                } while (nodeCounter < num_nodes && nodeHeight <= min_height);

                Node* child = new Node(childValue);
                current->children.push_back(child);
                levelQueue.push(child);
            }
        }
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
    tree.createTree(min_height, min_nodes, min_children);


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