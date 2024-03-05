#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int BLOCK_SIZE = 350;

int arr[MAXN];
int blocks[BLOCK_SIZE];
int block_size;

void build(int n) {
    for (int i = 0; i < n; ++i)
        blocks[i / block_size] += arr[i];
}

int query(int l, int r) {
    int sum = 0;
    while (l < r && l % block_size != 0 && l != 0)
        sum += arr[l++];
    while (l + block_size <= r) {
        sum += blocks[l / block_size];
        l += block_size;
    }
    while (l <= r)
        sum += arr[l++];
    return sum;
}

void update(int idx, int val) {
    int block_idx = idx / block_size;
    blocks[block_idx] += val - arr[idx];
    arr[idx] = val;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    block_size = sqrt(n);
    build(n);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << endl;
        } else {
            int idx, val;
            cin >> idx >> val;
            update(idx, val);
        }
    }
    
    return 0;
}
