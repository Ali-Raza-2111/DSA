#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while(index > 0) {
            int parent = (index - 1) / 2;
            if(heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while(2*index + 1 < n) {
            int left = 2*index + 1;
            int right = 2*index + 2;
            int smallest = index;

            if(left < n && heap[left] < heap[smallest])
                smallest = left;
            if(right < n && heap[right] < heap[smallest])
                smallest = right;

            if(smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int deleteMin() {
        if(heap.empty()) return -1;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    void printHeap() {
        for(int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    int n, val;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> val;
        h.insert(val);
    }

    cout << "Heap: ";
    h.printHeap();

    cout << "Deleted Min: " << h.deleteMin() << endl;
    cout << "Heap after deletion: ";
    h.printHeap();

    return 0;
}
