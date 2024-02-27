#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> arr(n);

struct Node {
    int maxIndex;
    int minIndex;
};

void buildSegmentTree(vector<int>& arr, vector<Node>& tree, int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode].maxIndex = start;
        tree[treeNode].minIndex = start;
        return;
    }

    int mid = (start + end) / 2;
    buildSegmentTree(arr, tree, start, mid, 2 * treeNode);
    buildSegmentTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    if (arr[tree[2 * treeNode].maxIndex] > arr[tree[2 * treeNode + 1].maxIndex]) {
        tree[treeNode].maxIndex = tree[2 * treeNode].maxIndex;
    } else {
        tree[treeNode].maxIndex = tree[2 * treeNode + 1].maxIndex;
    }

    if (arr[tree[2 * treeNode].minIndex] < arr[tree[2 * treeNode + 1].minIndex]) {
        tree[treeNode].minIndex = tree[2 * treeNode].minIndex;
    } else {
        tree[treeNode].minIndex = tree[2 * treeNode + 1].minIndex;
    }
}

Node query(vector<Node>& tree, int start, int end, int treeNode, int left, int right) {
    // Completely outside the given range
    if (start > right || end < left) {
        Node nullNode;
        nullNode.maxIndex = -1;
        nullNode.minIndex = -1;
        return nullNode;
    }

    // Completely inside the given range
    if (start >= left && end <= right) {
        return tree[treeNode];
    }

    // Partially inside and partially outside the given range
    int mid = (start + end) / 2;
    Node leftNode = query(tree, start, mid, 2 * treeNode, left, right);
    Node rightNode = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    Node result;
    if (leftNode.maxIndex == -1) {
        result = rightNode;
    } else if (rightNode.maxIndex == -1) {
        result = leftNode;
    } else {
        if (arr[leftNode.maxIndex] > arr[rightNode.maxIndex]) {
            result.maxIndex = leftNode.maxIndex;
        } else {
            result.maxIndex = rightNode.maxIndex;
        }
    }

    if (leftNode.minIndex == -1) {
        result = rightNode;
    } else if (rightNode.minIndex == -1) {
        result = leftNode;
    } else {
        if (arr[leftNode.minIndex] < arr[rightNode.minIndex]) {
            result.minIndex = leftNode.minIndex;
        } else {
            result.minIndex = rightNode.minIndex;
        }
    }

    return result;
}

int main() {

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<Node> tree(4 * n);
    buildSegmentTree(arr, tree, 0, n - 1, 1);

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    while (q--) {
        int left, right;
        cout << "Enter the range: ";
        cin >> left >> right;

        Node result = query(tree, 0, n - 1, 1, left, right);
        cout << "Max index: " << result.maxIndex << ", Min index: " << result.minIndex << endl;
    }

    return 0;
}
