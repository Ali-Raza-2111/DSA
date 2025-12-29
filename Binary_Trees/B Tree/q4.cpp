/*
    Assignment No. 06: B Tree
    BSSE 3A Fall 2025
    Q13. Write a function to traverse a B-tree and print its keys in sorted order.
*/

#include <iostream>
#include <vector>
using namespace std;

// Define the order of B-tree
const int M = 4; // Order of B-tree
const int MAX_KEYS = M - 1;

// B-tree node structure
struct BTreeNode {
    int keys[M];            // Array of keys
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

// B-tree class
class BTree {
private:
    BTreeNode* root;
    int order;

    // Split child function
    void splitChild(BTreeNode* parent, int index) {
        BTreeNode* fullChild = parent->children[index];
        BTreeNode* newChild = new BTreeNode(fullChild->isLeaf);
        
        int midIndex = MAX_KEYS / 2;
        
        newChild->numKeys = MAX_KEYS - midIndex - 1;
        for (int j = 0; j < newChild->numKeys; j++) {
            newChild->keys[j] = fullChild->keys[midIndex + 1 + j];
        }
        
        if (!fullChild->isLeaf) {
            for (int j = 0; j <= newChild->numKeys; j++) {
                newChild->children[j] = fullChild->children[midIndex + 1 + j];
            }
        }
        
        fullChild->numKeys = midIndex;
        
        for (int j = parent->numKeys; j > index; j--) {
            parent->children[j + 1] = parent->children[j];
        }
        parent->children[index + 1] = newChild;
        
        for (int j = parent->numKeys - 1; j >= index; j--) {
            parent->keys[j + 1] = parent->keys[j];
        }
        parent->keys[index] = fullChild->keys[midIndex];
        parent->numKeys++;
    }

    // Insert in non-full node
    void insertNonFull(BTreeNode* node, int key) {
        int i = node->numKeys - 1;

        if (node->isLeaf) {
            while (i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->numKeys++;
        } else {
            while (i >= 0 && node->keys[i] > key) {
                i--;
            }
            i++;

            if (node->children[i]->numKeys == MAX_KEYS) {
                splitChild(node, i);
                if (key > node->keys[i]) {
                    i++;
                }
            }
            insertNonFull(node->children[i], key);
        }
    }

    // ============================================
    // TRAVERSAL FUNCTIONS - Main focus of Q13
    // ============================================

    // In-order traversal (prints keys in sorted order)
    void inOrderTraversal(BTreeNode* node) {
        if (node == nullptr) return;
        
        int i;
        for (i = 0; i < node->numKeys; i++) {
            // First, traverse left subtree (child before key)
            if (!node->isLeaf) {
                inOrderTraversal(node->children[i]);
            }
            // Then print the key
            cout << node->keys[i] << " ";
        }
        // Traverse the rightmost child
        if (!node->isLeaf) {
            inOrderTraversal(node->children[i]);
        }
    }

    // In-order traversal that stores keys in a vector
    void inOrderToVector(BTreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        int i;
        for (i = 0; i < node->numKeys; i++) {
            if (!node->isLeaf) {
                inOrderToVector(node->children[i], result);
            }
            result.push_back(node->keys[i]);
        }
        if (!node->isLeaf) {
            inOrderToVector(node->children[i], result);
        }
    }

    // Pre-order traversal (root first, then children)
    void preOrderTraversal(BTreeNode* node, int level) {
        if (node == nullptr) return;
        
        // Print indentation based on level
        for (int j = 0; j < level; j++) cout << "  ";
        
        // Print all keys in current node
        cout << "[";
        for (int i = 0; i < node->numKeys; i++) {
            cout << node->keys[i];
            if (i < node->numKeys - 1) cout << ", ";
        }
        cout << "]" << endl;
        
        // Recursively traverse children
        if (!node->isLeaf) {
            for (int i = 0; i <= node->numKeys; i++) {
                preOrderTraversal(node->children[i], level + 1);
            }
        }
    }

    // Level-order traversal (BFS)
    void levelOrderTraversal(BTreeNode* node) {
        if (node == nullptr) return;
        
        // Using simple array as queue (for demonstration)
        BTreeNode* queue[100];
        int front = 0, rear = 0;
        int levelEnd[100];
        int levelCount = 0;
        
        queue[rear++] = node;
        levelEnd[levelCount++] = rear;
        
        int currentLevel = 0;
        cout << "Level " << currentLevel << ": ";
        
        while (front < rear) {
            BTreeNode* current = queue[front++];
            
            // Print current node
            cout << "[";
            for (int i = 0; i < current->numKeys; i++) {
                cout << current->keys[i];
                if (i < current->numKeys - 1) cout << ", ";
            }
            cout << "] ";
            
            // Add children to queue
            if (!current->isLeaf) {
                for (int i = 0; i <= current->numKeys; i++) {
                    if (current->children[i] != nullptr) {
                        queue[rear++] = current->children[i];
                    }
                }
            }
            
            // Check if we've finished current level
            if (front == levelEnd[currentLevel]) {
                cout << endl;
                currentLevel++;
                if (front < rear) {
                    cout << "Level " << currentLevel << ": ";
                    levelEnd[levelCount++] = rear;
                }
            }
        }
    }

    // Count total keys in tree
    int countKeys(BTreeNode* node) {
        if (node == nullptr) return 0;
        
        int count = node->numKeys;
        if (!node->isLeaf) {
            for (int i = 0; i <= node->numKeys; i++) {
                count += countKeys(node->children[i]);
            }
        }
        return count;
    }

public:
    // Constructor
    BTree(int m = M) {
        root = nullptr;
        order = m;
    }

    // Insert function
    void insert(int key) {
        if (root == nullptr) {
            root = new BTreeNode(true);
            root->keys[0] = key;
            root->numKeys = 1;
        } else {
            if (root->numKeys == MAX_KEYS) {
                BTreeNode* newRoot = new BTreeNode(false);
                newRoot->children[0] = root;
                root = newRoot;
                splitChild(root, 0);
                
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

    // ============================================
    // PUBLIC TRAVERSAL METHODS
    // ============================================

    // Traverse and print in sorted order (in-order)
    void traverseSorted() {
        cout << "Sorted order (In-order traversal): ";
        if (root == nullptr) {
            cout << "(empty tree)";
        } else {
            inOrderTraversal(root);
        }
        cout << endl;
    }

    // Get all keys in sorted order as vector
    vector<int> getSortedKeys() {
        vector<int> result;
        inOrderToVector(root, result);
        return result;
    }

    // Pre-order traversal (shows tree structure)
    void traversePreOrder() {
        cout << "Pre-order traversal (tree structure):" << endl;
        if (root == nullptr) {
            cout << "(empty tree)" << endl;
        } else {
            preOrderTraversal(root, 0);
        }
    }

    // Level-order traversal
    void traverseLevelOrder() {
        cout << "Level-order traversal:" << endl;
        if (root == nullptr) {
            cout << "(empty tree)" << endl;
        } else {
            levelOrderTraversal(root);
        }
    }

    // Get total number of keys
    int getTotalKeys() {
        return countKeys(root);
    }

    // Check if empty
    bool isEmpty() {
        return root == nullptr;
    }
};

int main() {
    cout << "=== B-Tree Traversal - Print Keys in Sorted Order ===" << endl;
    cout << "Order of B-tree: " << M << endl;
    cout << "Maximum keys per node: " << MAX_KEYS << endl << endl;

    BTree btree;

    // Insert some keys
    int keys[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90};
    int n = sizeof(keys) / sizeof(keys[0]);

    cout << "Inserting keys: ";
    for (int i = 0; i < n; i++) {
        cout << keys[i] << " ";
        btree.insert(keys[i]);
    }
    cout << endl << endl;

    // Demonstrate different traversals
    cout << "========================================" << endl;
    cout << "1. IN-ORDER TRAVERSAL (SORTED ORDER)" << endl;
    cout << "========================================" << endl;
    btree.traverseSorted();

    cout << "\n========================================" << endl;
    cout << "2. PRE-ORDER TRAVERSAL (TREE STRUCTURE)" << endl;
    cout << "========================================" << endl;
    btree.traversePreOrder();

    cout << "\n========================================" << endl;
    cout << "3. LEVEL-ORDER TRAVERSAL (BFS)" << endl;
    cout << "========================================" << endl;
    btree.traverseLevelOrder();

    cout << "\n========================================" << endl;
    cout << "4. KEYS AS SORTED ARRAY" << endl;
    cout << "========================================" << endl;
    vector<int> sortedKeys = btree.getSortedKeys();
    cout << "Sorted array: [";
    for (int i = 0; i < sortedKeys.size(); i++) {
        cout << sortedKeys[i];
        if (i < sortedKeys.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "\nTotal keys in tree: " << btree.getTotalKeys() << endl;

    cout << "\n========================================" << endl;
    cout << "EXPLANATION OF IN-ORDER TRAVERSAL" << endl;
    cout << "========================================" << endl;
    cout << "For each node, we:" << endl;
    cout << "1. Recursively visit the left subtree (child before first key)" << endl;
    cout << "2. Print the first key" << endl;
    cout << "3. Recursively visit subtree between keys" << endl;
    cout << "4. Continue until all keys and children are processed" << endl;
    cout << "This produces keys in ascending sorted order." << endl;

    return 0;
}
