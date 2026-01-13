/*
    Assignment No. 06: B Tree
    BSSE 3A Fall 2025
    Q11. Write a program to insert a key into a B-tree without handling node overflow.
*/

#include <iostream>
using namespace std;

// Define the order of B-tree
const int M = 5; // Order of B-tree (max children = M, max keys = M-1)

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
        for (int i = 0; i < M - 1; i++) {
            keys[i] = 0;
        }
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

    // Helper function to insert key in a non-full node
    void insertNonFull(BTreeNode* node, int key) {
        int i = node->numKeys - 1;

        if (node->isLeaf) {
            // Find position and insert key in leaf node
            while (i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->numKeys++;
        } else {
            // Find the child which will have the new key
            while (i >= 0 && node->keys[i] > key) {
                i--;
            }
            i++;

            // Insert in the appropriate child
            // Note: This does NOT handle overflow
            insertNonFull(node->children[i], key);
        }
    }

    // Traverse and print helper
    void traverseHelper(BTreeNode* node) {
        if (node == nullptr) return;
        
        int i;
        for (i = 0; i < node->numKeys; i++) {
            if (!node->isLeaf) {
                traverseHelper(node->children[i]);
            }
            cout << node->keys[i] << " ";
        }
        if (!node->isLeaf) {
            traverseHelper(node->children[i]);
        }
    }

public:
    // Constructor to initialize an empty B-tree
    BTree(int m = M) {
        root = nullptr;
        order = m;
    }

    // Function to insert a key WITHOUT handling overflow
    // Warning: This will only work correctly when node doesn't overflow
    void insert(int key) {
        cout << "Inserting key: " << key << endl;

        if (root == nullptr) {
            // Create root node if tree is empty
            root = new BTreeNode(true);
            root->keys[0] = key;
            root->numKeys = 1;
            cout << "  -> Created new root with key " << key << endl;
        } else {
            // Check if root has space (no overflow handling)
            if (root->numKeys < M - 1) {
                insertNonFull(root, key);
                cout << "  -> Inserted into existing node" << endl;
            } else {
                cout << "  -> WARNING: Node is full! Overflow not handled." << endl;
                cout << "     Key " << key << " cannot be inserted without split." << endl;
            }
        }
    }

    // Function to traverse the B-tree
    void traverse() {
        cout << "B-tree keys (in-order): ";
        if (root == nullptr) {
            cout << "(empty)";
        } else {
            traverseHelper(root);
        }
        cout << endl;
    }

    // Function to display tree structure
    void displayNode(BTreeNode* node, int level) {
        if (node == nullptr) return;
        
        cout << "Level " << level << ": [";
        for (int i = 0; i < node->numKeys; i++) {
            cout << node->keys[i];
            if (i < node->numKeys - 1) cout << ", ";
        }
        cout << "] (Keys: " << node->numKeys << "/" << M-1 << ")" << endl;
    }

    void display() {
        cout << "\n--- B-Tree Structure ---" << endl;
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
        } else {
            displayNode(root, 0);
        }
        cout << "------------------------" << endl;
    }

    // Check if tree is empty
    bool isEmpty() {
        return root == nullptr;
    }

    // Get maximum keys per node
    int getMaxKeys() {
        return M - 1;
    }
};

int main() {
    cout << "=== B-Tree Insertion (Without Overflow Handling) ===" << endl;
    cout << "Order of B-tree: " << M << endl;
    cout << "Maximum keys per node: " << M - 1 << endl << endl;

    BTree btree;

    // Insert keys that fit in a single node (M-1 = 4 keys for order 5)
    cout << "--- Inserting keys that fit in root node ---" << endl;
    btree.insert(30);
    btree.display();

    btree.insert(10);
    btree.display();

    btree.insert(50);
    btree.display();

    btree.insert(20);
    btree.display();

    // Try to insert more keys (will show overflow warning)
    cout << "\n--- Attempting to insert more keys (overflow scenario) ---" << endl;
    btree.insert(40);  // This will trigger overflow warning
    btree.display();

    cout << "\n--- Final Traversal ---" << endl;
    btree.traverse();

    cout << "\nNote: This implementation does NOT handle node splitting." << endl;
    cout << "When a node is full, additional insertions are rejected." << endl;

    return 0;
}
