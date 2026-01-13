/*
    Assignment No. 06: B Tree
    BSSE 3A Fall 2025
    Q12. Extend Q11 to handle node splitting during insertion.
*/

#include <iostream>
using namespace std;

// Define the order of B-tree
const int M = 3; // Order of B-tree (minimum degree t = ceil(M/2))
const int MAX_KEYS = M - 1;
const int MIN_KEYS = (M - 1) / 2;

// B-tree node structure
struct BTreeNode {
    int keys[M];            // Array of keys (extra space for temporary overflow)
    BTreeNode* children[M + 1]; // Array of child pointers
    int numKeys;            // Current number of keys
    bool isLeaf;            // True if node is a leaf
    
    // Constructor to initialize a new node
    BTreeNode(bool leaf = true) {
        isLeaf = leaf;
        numKeys = 0;
        for (int i = 0; i <= M; i++) {
            children[i] = nullptr;
        }
    }
};

// B-tree class with node splitting
class BTree {
private:
    BTreeNode* root;
    int order;

    // Function to split a full child node
    void splitChild(BTreeNode* parent, int index) {
        BTreeNode* fullChild = parent->children[index];
        BTreeNode* newChild = new BTreeNode(fullChild->isLeaf);
        
        int midIndex = MAX_KEYS / 2;
        
        // Copy the upper half of keys to new child
        newChild->numKeys = MAX_KEYS - midIndex - 1;
        for (int j = 0; j < newChild->numKeys; j++) {
            newChild->keys[j] = fullChild->keys[midIndex + 1 + j];
        }
        
        // Copy children if not leaf
        if (!fullChild->isLeaf) {
            for (int j = 0; j <= newChild->numKeys; j++) {
                newChild->children[j] = fullChild->children[midIndex + 1 + j];
            }
        }
        
        // Reduce number of keys in full child
        fullChild->numKeys = midIndex;
        
        // Make space for new child in parent
        for (int j = parent->numKeys; j > index; j--) {
            parent->children[j + 1] = parent->children[j];
        }
        parent->children[index + 1] = newChild;
        
        // Move middle key up to parent
        for (int j = parent->numKeys - 1; j >= index; j--) {
            parent->keys[j + 1] = parent->keys[j];
        }
        parent->keys[index] = fullChild->keys[midIndex];
        parent->numKeys++;
        
        cout << "  -> Split performed! Middle key " << parent->keys[index] << " moved up." << endl;
    }

    // Insert key in a non-full node
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

            // Check if found child is full
            if (node->children[i]->numKeys == MAX_KEYS) {
                splitChild(node, i);
                // Determine which child to insert into after split
                if (key > node->keys[i]) {
                    i++;
                }
            }
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

    // Print tree structure helper
    void printTreeHelper(BTreeNode* node, int level, string prefix) {
        if (node == nullptr) return;
        
        cout << prefix;
        if (level > 0) {
            cout << "|-- ";
        }
        
        cout << "[";
        for (int i = 0; i < node->numKeys; i++) {
            cout << node->keys[i];
            if (i < node->numKeys - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        if (!node->isLeaf) {
            for (int i = 0; i <= node->numKeys; i++) {
                string newPrefix = prefix;
                if (level > 0) {
                    newPrefix += "|   ";
                }
                printTreeHelper(node->children[i], level + 1, newPrefix);
            }
        }
    }

public:
    // Constructor to initialize an empty B-tree
    BTree(int m = M) {
        root = nullptr;
        order = m;
    }

    // Function to insert a key WITH overflow handling (node splitting)
    void insert(int key) {
        cout << "Inserting key: " << key << endl;

        if (root == nullptr) {
            // Create root node if tree is empty
            root = new BTreeNode(true);
            root->keys[0] = key;
            root->numKeys = 1;
            cout << "  -> Created new root with key " << key << endl;
        } else {
            // If root is full, create new root
            if (root->numKeys == MAX_KEYS) {
                BTreeNode* newRoot = new BTreeNode(false);
                newRoot->children[0] = root;
                root = newRoot;
                splitChild(root, 0);
                
                // Determine which child to insert into
                int i = 0;
                if (root->keys[0] < key) {
                    i++;
                }
                insertNonFull(root->children[i], key);
            } else {
                insertNonFull(root, key);
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

    // Function to print tree structure
    void printTree() {
        cout << "\n=== B-Tree Structure ===" << endl;
        if (root == nullptr) {
            cout << "(empty tree)" << endl;
        } else {
            printTreeHelper(root, 0, "");
        }
        cout << "========================" << endl;
    }

    // Check if tree is empty
    bool isEmpty() {
        return root == nullptr;
    }
};

int main() {
    cout << "=== B-Tree Insertion WITH Node Splitting ===" << endl;
    cout << "Order of B-tree: " << M << endl;
    cout << "Maximum keys per node: " << MAX_KEYS << endl;
    cout << "Minimum keys per node (except root): " << MIN_KEYS << endl << endl;

    BTree btree;

    // Insert keys to demonstrate splitting
    int keys[] = {10, 20, 5, 6, 12, 30, 7, 17, 3, 8};
    int n = sizeof(keys) / sizeof(keys[0]);

    cout << "--- Inserting keys ---" << endl;
    for (int i = 0; i < n; i++) {
        btree.insert(keys[i]);
        btree.printTree();
        btree.traverse();
        cout << endl;
    }

    cout << "\n=== Final B-Tree ===" << endl;
    btree.printTree();
    btree.traverse();

    cout << "\nNote: This implementation handles node splitting when a node" << endl;
    cout << "becomes full during insertion. The middle key is promoted to" << endl;
    cout << "the parent, and the node is split into two nodes." << endl;

    return 0;
}
