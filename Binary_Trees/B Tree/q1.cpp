/*
    Assignment No. 06: B Tree
    BSSE 3A Fall 2025
    Q10. Implement a function to search a key in a B-tree and return whether the key exists.
*/

#include <iostream>
using namespace std;

// Define the order of B-tree
const int M = 3; // Order of B-tree (minimum degree t = ceil(M/2))

// B-tree node structure
struct BTreeNode {
    int keys[M - 1];        // Array of keys
    BTreeNode* children[M]; // Array of child pointers
    int numKeys;            // Current number of keys
    bool isLeaf;            // True if node is a leaf
    
    // Constructor to initialize a new node
    BTreeNode(bool leaf = true) {
        isLeaf = leaf;
        numKeys = 0;
        for (int i = 0; i < M; i++) {
            children[i] = nullptr;
        }
    }
};

// B-tree class
class BTree {
private:
    BTreeNode* root;
    int order;

    // Helper function to search a key in subtree rooted at node
    bool searchHelper(BTreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }

        // Find the first key greater than or equal to the search key
        int i = 0;
        while (i < node->numKeys && key > node->keys[i]) {
            i++;
        }

        // If the key is found at this node
        if (i < node->numKeys && node->keys[i] == key) {
            return true;
        }

        // If node is a leaf, key is not present
        if (node->isLeaf) {
            return false;
        }

        // Recursively search in the appropriate child
        return searchHelper(node->children[i], key);
    }

public:
    // Constructor to initialize an empty B-tree
    BTree(int m = M) {
        root = nullptr;
        order = m;
    }

    // Function to search a key in the B-tree
    bool search(int key) {
        return searchHelper(root, key);
    }

    // Simple insert function (for testing - without overflow handling)
    void simpleInsert(int key) {
        if (root == nullptr) {
            root = new BTreeNode(true);
            root->keys[0] = key;
            root->numKeys = 1;
        } else {
            // Simple insertion into root (only for demonstration)
            if (root->numKeys < M - 1) {
                int i = root->numKeys - 1;
                while (i >= 0 && root->keys[i] > key) {
                    root->keys[i + 1] = root->keys[i];
                    i--;
                }
                root->keys[i + 1] = key;
                root->numKeys++;
            }
        }
    }

    // Function to check if tree is empty
    bool isEmpty() {
        return root == nullptr;
    }
};

int main() {
    cout << "=== B-Tree Search Implementation ===" << endl;
    cout << "Order of B-tree: " << M << endl << endl;

    BTree btree;

    // Check if tree is empty initially
    cout << "Is tree empty? " << (btree.isEmpty() ? "Yes" : "No") << endl;

    // Insert some keys for testing
    cout << "\nInserting keys: 10, 20, 5, 15" << endl;
    btree.simpleInsert(10);
    btree.simpleInsert(20);
    btree.simpleInsert(5);
    btree.simpleInsert(15);

    cout << "\n--- Search Results ---" << endl;
    
    // Search for existing keys
    int searchKeys[] = {10, 20, 5, 15, 25, 7};
    for (int key : searchKeys) {
        bool found = btree.search(key);
        cout << "Search for key " << key << ": " 
             << (found ? "Found" : "Not Found") << endl;
    }

    return 0;
}
