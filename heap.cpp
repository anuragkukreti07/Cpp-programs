#include <bits/stdc++.h>
using namespace std;

class heap {
    private:
        vector<int> data;

    public:
        
    void minHeapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int n = data.size();

        if (left < n && data[left] < data[smallest])
            smallest = left;

        if (right < n && data[right] < data[smallest])
            smallest = right;

        if (smallest != idx) {
            swap(data[idx], data[smallest]);
            minHeapify(smallest);
        }
    }

    void maxHeapify(int idx) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int n = data.size();

        if (left < n && data[left] > data[largest])
            largest = left;

        if (right < n && data[right] > data[largest])
            largest = right;

        if (largest != idx) {
            swap(data[idx], data[largest]);
            maxHeapify(largest);
        }
    }

    void minPush(int element) {
        data.push_back(element);
        int idx = data.size() - 1;
        while (idx > 0 && data[(idx - 1) / 2] > data[idx]) {
            swap(data[idx], data[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void maxPush(int element) {
        data.push_back(element);
        int idx = data.size() - 1;
        while (idx > 0 && data[(idx - 1) / 2] < data[idx]) {
            swap(data[idx], data[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    int Top() {
        if (data.empty()) {
            cout << "Heap is empty" << endl;
            return INT_MIN; 
        }
        return data[0];
    }

    void Pop() {
        if (data.empty()) {
            cout << "Heap is empty" << endl;
            return;
        }

        data[0] = data.back();
        data.pop_back();
        if (!data.empty()) {
            if (data.size() > 1) {
                if (data[0] > data[1]) {
                    minHeapify(0);
                } else {
                    maxHeapify(0);
                }
            }
        }
    }

    void minTomax() {
        for (int i = data.size() / 2 - 1; i >= 0; i--)
            maxHeapify(i);
    }

    void maxTomin() {
        for (int i = data.size() / 2 - 1; i >= 0; i--)
            minHeapify(i);
    }

};

int main() {
    heap obj;
    int n, ch;
    cout << "Enter 1. Min Heap\n2.Max Heap\n";
    cin >> n;
    do {
        cout << "1.Enter element\n2.See top element\n3.Pop top element\n4.Convert min to max\n5.Convert Max to Min\n";
        cin >> ch;
        if (ch == 1) {
            int k;
            cout << "Enter number\n";
            cin >> k;
            if (n == 1) {
                obj.minPush(k);
            } else {
                obj.maxPush(k);
            }
        } else if (ch == 2) {
            cout << obj.Top() << endl;
        } else if (ch == 3) {
            obj.Pop();
        } else if (ch == 4) {
            if (n == 2) {
                cout << "Already a max heap\n";
            } else {
                obj.minTomax();
                n = 2;
            }
        } else if (ch == 5) {
            if (n == 1) {
                cout << "Already a min heap\n";
            } else {
                obj.maxTomin();
                n = 1;
            }
        }
    } while (ch > 0 && ch <= 5);
    return 0;
}
