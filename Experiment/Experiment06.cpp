#include <iostream>
using namespace std;

// BST node structure
struct BSTNode {
    int key;
    BSTNode *lchild;
    BSTNode *rchild;
};

// Insert a key into BST
void InsertBST(BSTNode* &root, int key) {
    if (root == NULL) {
        root = new BSTNode;
        root->key = key;
        root->lchild = root->rchild = NULL;
    } else if (key < root->key) {
        InsertBST(root->lchild, key);
    } else {
        InsertBST(root->rchild, key);
    }
}

// Search a key in BST
BSTNode* SearchBST(BSTNode* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return SearchBST(root->lchild, key);
    else
        return SearchBST(root->rchild, key);
}

// Delete a leaf node
bool DeleteLeaf(BSTNode* &root, int key) {
    if (root == NULL)
        return false;

    if (root->key == key) {
        if (root->lchild == NULL && root->rchild == NULL) {
            delete root;
            root = NULL;
            return true;
        } else {
            cout << "Node is not a leaf.\n";
            return false;
        }
    }

    if (key < root->key)
        return DeleteLeaf(root->lchild, key);
    else
        return DeleteLeaf(root->rchild, key);
}

// In-order traversal
void InOrder(BSTNode* root) {
    if (root != NULL) {
        InOrder(root->lchild);
        cout << root->key << " ";
        InOrder(root->rchild);
    }
}

int main() {
    BSTNode* root = NULL;
    int data[] = {45, 24, 53, 12, 37, 90};
    int n = 6;

    // (1) Construct BST
    for (int i = 0; i < n; i++)
        InsertBST(root, data[i]);

    cout << "In-order traversal: ";
    InOrder(root);
    cout << endl;

    // (2) Insert a key
    InsertBST(root, 30);
    cout << "After inserting 30: ";
    InOrder(root);
    cout << endl;

    // (4) Search a key
    int key = 37;
    if (SearchBST(root, key))
        cout << "Key " << key << " found.\n";
    else
        cout << "Key " << key << " not found.\n";

    // (3) Delete a leaf
    DeleteLeaf(root, 12);
    cout << "After deleting leaf 12: ";
    InOrder(root);
    cout << endl;

    return 0;
}
