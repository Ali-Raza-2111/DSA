/*
    Assignment No. 06: B Tree
    BSSE 3A Fall 2025
    Q14. Analyze the time complexity of your insertion and search algorithms for a B-tree.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Define the order of B-tree
const int M = 4; // Order of B-tree (minimum degree t = ceil(M/2))
const int MAX_KEYS = M - 1;
const int MIN_DEGREE = (M + 1) / 2; // t = ceil(M/2)

// B-tree node structure
struct BTreeNode {
    int keys[M];
    BTreeNode* children[M + 1];
    int numKeys;
    bool isLeaf;
    
    BTreeNode(bool leaf = true) {
        isLeaf = leaf;
        numKeys = 0;
        for (int i = 0; i <= M; i++) {
            children[i] = nullptr;
        }
    }
};

// B-tree class with complexity analysis
class BTree {
private:
    BTreeNode* root;
    int order;
    
    // Counters for complexity analysis
    int searchComparisons;
    int insertComparisons;
    int nodeSplits;
    int totalNodes;
    int treeHeight;

    // Calculate tree height
    int calculateHeight(BTreeNode* node) {
        if (node == nullptr) return 0;
        if (node->isLeaf) return 1;
        return 1 + calculateHeight(node->children[0]);
    }

    // Count nodes
    int countNodes(BTreeNode* node) {
        if (node == nullptr) return 0;
        int count = 1;
        if (!node->isLeaf) {
            for (int i = 0; i <= node->numKeys; i++) {
                count += countNodes(node->children[i]);
            }
        }
        return count;
    }

    // Count total keys
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

    // Search helper with comparison counting
    bool searchHelper(BTreeNode* node, int key) {
        if (node == nullptr) return false;

        int i = 0;
        while (i < node->numKeys && key > node->keys[i]) {
            searchComparisons++;
            i++;
        }
        if (i < node->numKeys) searchComparisons++; // Final comparison

        if (i < node->numKeys && node->keys[i] == key) {
            return true;
        }

        if (node->isLeaf) {
            return false;
        }

        return searchHelper(node->children[i], key);
    }

    // Split child
    void splitChild(BTreeNode* parent, int index) {
        nodeSplits++;
        
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

    // Insert non-full with comparison counting
    void insertNonFull(BTreeNode* node, int key) {
        int i = node->numKeys - 1;

        if (node->isLeaf) {
            while (i >= 0 && node->keys[i] > key) {
                insertComparisons++;
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            if (i >= 0) insertComparisons++;
            node->keys[i + 1] = key;
            node->numKeys++;
        } else {
            while (i >= 0 && node->keys[i] > key) {
                insertComparisons++;
                i--;
            }
            if (i >= 0) insertComparisons++;
            i++;

            if (node->children[i]->numKeys == MAX_KEYS) {
                splitChild(node, i);
                insertComparisons++;
                if (key > node->keys[i]) {
                    i++;
                }
            }
            insertNonFull(node->children[i], key);
        }
    }

public:
    BTree(int m = M) {
        root = nullptr;
        order = m;
        searchComparisons = 0;
        insertComparisons = 0;
        nodeSplits = 0;
        totalNodes = 0;
        treeHeight = 0;
    }

    // Search with complexity tracking
    bool search(int key) {
        searchComparisons = 0;
        return searchHelper(root, key);
    }

    // Insert with complexity tracking
    void insert(int key) {
        insertComparisons = 0;
        
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
                
                insertComparisons++;
                int i = 0;
                if (root->keys[0] < key) {
                    i++;
                }
                insertNonFull(root->children[i], key);
            } else {
                insertNonFull(root, key);
            }
        }
        
        // Update statistics
        treeHeight = calculateHeight(root);
        totalNodes = countNodes(root);
    }

    // Get last search comparisons
    int getSearchComparisons() { return searchComparisons; }
    
    // Get last insert comparisons
    int getInsertComparisons() { return insertComparisons; }
    
    // Get total node splits
    int getNodeSplits() { return nodeSplits; }
    
    // Get tree height
    int getHeight() { return treeHeight; }
    
    // Get total nodes
    int getTotalNodes() { return totalNodes; }
    
    // Get total keys
    int getTotalKeys() { return countKeys(root); }

    // Check if empty
    bool isEmpty() { return root == nullptr; }
};

// Function to print complexity analysis
void printComplexityAnalysis() {
    cout << "\n" << string(70, '=') << endl;
    cout << "              TIME COMPLEXITY ANALYSIS OF B-TREE" << endl;
    cout << string(70, '=') << endl;

    cout << "\n1. SEARCH OPERATION" << endl;
    cout << string(40, '-') << endl;
    cout << "   Algorithm:" << endl;
    cout << "   - Start from root, find appropriate child at each level" << endl;
    cout << "   - At each node, perform O(log m) comparisons (binary search)" << endl;
    cout << "     or O(m) comparisons (linear search)" << endl;
    cout << "   - Traverse down to leaf level" << endl;
    cout << endl;
    cout << "   Time Complexity:" << endl;
    cout << "   +------------------+---------------------------+" << endl;
    cout << "   | Case             | Complexity                |" << endl;
    cout << "   +------------------+---------------------------+" << endl;
    cout << "   | Best Case        | O(1)                      |" << endl;
    cout << "   | Average Case     | O(log n)                  |" << endl;
    cout << "   | Worst Case       | O(log n)                  |" << endl;
    cout << "   +------------------+---------------------------+" << endl;
    cout << endl;
    cout << "   Detailed Analysis:" << endl;
    cout << "   - Height of B-tree: h = O(log_t n) where t = minimum degree" << endl;
    cout << "   - Comparisons per node: O(m) for linear, O(log m) for binary" << endl;
    cout << "   - Total: O(m * log_t n) = O(log n) [since m is constant]" << endl;

    cout << "\n2. INSERTION OPERATION" << endl;
    cout << string(40, '-') << endl;
    cout << "   Algorithm:" << endl;
    cout << "   - Search for correct position (same as search)" << endl;
    cout << "   - Insert key in leaf node" << endl;
    cout << "   - Split nodes if necessary (propagates up)" << endl;
    cout << endl;
    cout << "   Time Complexity:" << endl;
    cout << "   +------------------+---------------------------+" << endl;
    cout << "   | Case             | Complexity                |" << endl;
    cout << "   +------------------+---------------------------+" << endl;
    cout << "   | Best Case        | O(log n) - no splits      |" << endl;
    cout << "   | Average Case     | O(log n)                  |" << endl;
    cout << "   | Worst Case       | O(m * log n) - all splits |" << endl;
    cout << "   +------------------+---------------------------+" << endl;
    cout << endl;
    cout << "   Detailed Analysis:" << endl;
    cout << "   - Finding position: O(log n)" << endl;
    cout << "   - Node split: O(m) - copying keys and children" << endl;
    cout << "   - Maximum h splits possible (one per level)" << endl;
    cout << "   - Total: O(log n) + O(m * h) = O(m * log n) worst case" << endl;
    cout << "   - Amortized: O(log n) since splits are infrequent" << endl;

    cout << "\n3. SPACE COMPLEXITY" << endl;
    cout << string(40, '-') << endl;
    cout << "   - Each node: O(m) for keys and children" << endl;
    cout << "   - Number of nodes: O(n/m) minimum" << endl;
    cout << "   - Total space: O(n)" << endl;
    cout << "   - Stack space for recursion: O(log n)" << endl;

    cout << "\n4. COMPARISON WITH OTHER DATA STRUCTURES" << endl;
    cout << string(40, '-') << endl;
    cout << "   +------------------+------------+------------+------------+" << endl;
    cout << "   | Data Structure   | Search     | Insert     | Delete     |" << endl;
    cout << "   +------------------+------------+------------+------------+" << endl;
    cout << "   | B-Tree           | O(log n)   | O(log n)   | O(log n)   |" << endl;
    cout << "   | Binary Search    | O(log n)   | O(log n)   | O(log n)   |" << endl;
    cout << "   | Tree (balanced)  |            |            |            |" << endl;
    cout << "   | BST (unbalanced) | O(n)       | O(n)       | O(n)       |" << endl;
    cout << "   | Hash Table       | O(1) avg   | O(1) avg   | O(1) avg   |" << endl;
    cout << "   | Linked List      | O(n)       | O(1)       | O(n)       |" << endl;
    cout << "   +------------------+------------+------------+------------+" << endl;

    cout << "\n5. WHY B-TREES ARE EFFICIENT FOR DISK" << endl;
    cout << string(40, '-') << endl;
    cout << "   - Higher branching factor = fewer disk accesses" << endl;
    cout << "   - Node size can match disk block size" << endl;
    cout << "   - Height is minimized: h = O(log_m n)" << endl;
    cout << "   - Example: m=1000, n=1 billion -> h = 3 levels only!" << endl;

    cout << "\n" << string(70, '=') << endl;
}

int main() {
    cout << "=== B-Tree Time Complexity Analysis ===" << endl;
    cout << "Order of B-tree (m): " << M << endl;
    cout << "Minimum degree (t): " << MIN_DEGREE << endl;
    cout << "Maximum keys per node: " << MAX_KEYS << endl << endl;

    BTree btree;

    // Insert keys and track statistics
    int keys[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90, 5, 15, 27, 33, 42};
    int n = sizeof(keys) / sizeof(keys[0]);

    cout << "=== INSERTION ANALYSIS ===" << endl;
    cout << string(60, '-') << endl;
    cout << setw(10) << "Key" << setw(15) << "Comparisons" << setw(12) << "Height" 
         << setw(12) << "Nodes" << setw(12) << "Splits" << endl;
    cout << string(60, '-') << endl;

    int totalSplits = 0;
    for (int i = 0; i < n; i++) {
        btree.insert(keys[i]);
        cout << setw(10) << keys[i] 
             << setw(15) << btree.getInsertComparisons()
             << setw(12) << btree.getHeight()
             << setw(12) << btree.getTotalNodes()
             << setw(12) << btree.getNodeSplits() - totalSplits << endl;
        totalSplits = btree.getNodeSplits();
    }

    cout << string(60, '-') << endl;
    cout << "Total keys inserted: " << n << endl;
    cout << "Final tree height: " << btree.getHeight() << endl;
    cout << "Total node splits: " << btree.getNodeSplits() << endl;
    cout << "Theoretical minimum height: " << (int)ceil(log(n + 1) / log(M)) << endl;

    cout << "\n=== SEARCH ANALYSIS ===" << endl;
    cout << string(50, '-') << endl;
    cout << setw(10) << "Key" << setw(15) << "Comparisons" << setw(15) << "Found" << endl;
    cout << string(50, '-') << endl;

    int searchKeys[] = {50, 25, 90, 42, 100, 1, 65};
    int totalSearchComparisons = 0;
    for (int key : searchKeys) {
        bool found = btree.search(key);
        cout << setw(10) << key 
             << setw(15) << btree.getSearchComparisons()
             << setw(15) << (found ? "Yes" : "No") << endl;
        totalSearchComparisons += btree.getSearchComparisons();
    }
    
    cout << string(50, '-') << endl;
    cout << "Average comparisons per search: " 
         << fixed << setprecision(2) 
         << (double)totalSearchComparisons / 7 << endl;
    cout << "Theoretical maximum (height * m): " << btree.getHeight() * MAX_KEYS << endl;

    // Print detailed complexity analysis
    printComplexityAnalysis();

    cout << "\n=== SUMMARY ===" << endl;
    cout << "For a B-tree of order " << M << " with " << n << " keys:" << endl;
    cout << "- Search complexity: O(log n) = O(log " << n << ") ≈ " 
         << fixed << setprecision(2) << log2(n) << " comparisons" << endl;
    cout << "- Insert complexity: O(log n) amortized" << endl;
    cout << "- Actual tree height: " << btree.getHeight() << endl;
    cout << "- B-trees are optimal for disk-based storage systems!" << endl;

    return 0;
}
