// https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ 

// C++ program to convert sorted
// array to BST.
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *sortedArrayToBST(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return nullptr;

    // create the root node.
    int mid = (n - 1) / 2;
    Node *root = new Node(arr[mid]);

    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, n - 1}});

    while (!q.empty()) {
        pair<Node *, pair<int, int>> front = q.front();
        q.pop();
        Node *curr = front.first;
        int s = front.second.first, e = front.second.second;
        int index = s + (e - s) / 2;

        // if left subtree exists
        if (s < index) {
            int mid = s + (index - 1 - s) / 2;
            Node *left = new Node(arr[mid]);
            curr->left = left;
            q.push({left, {s, index - 1}});
        }

        // if right subtree exists
        if (e > index) {
            int mid = index + 1 + (e - index - 1) / 2;
            Node *right = new Node(arr[mid]);
            curr->right = right;
            q.push({right, {index + 1, e}});
        }
    }
    return root;
}

void preOrder(Node *root) {
    if (root == nullptr) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    Node *root = sortedArrayToBST(arr);
    preOrder(root);
    return 0;
}