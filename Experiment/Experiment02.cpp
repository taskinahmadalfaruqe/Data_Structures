template <class T>
struct BiNode
{
    T data;
    BiNode<T> *lchild;
    BiNode<T> *rchild;
};

#include <iostream>
using namespace std;

template <class T>
class BiTree
{
private:
    BiNode<T> *root;

public:
    BiTree()
    {
        root = NULL;
    }

    // Create binary tree (preorder input, '#' represents NULL)
    void Create(BiNode<T> *&node)
    {
        T ch;
        cin >> ch;
        if (ch == '#')
        {
            node = NULL;
        }
        else
        {
            node = new BiNode<T>;
            node->data = ch;
            Create(node->lchild);
            Create(node->rchild);
        }
    }

    void CreateTree()
    {
        Create(root);
    }

    // Count leaf nodes
    int CountLeaf(BiNode<T> *node, int &count)
    {
        if (node != NULL)
        {
            if (node->lchild == NULL && node->rchild == NULL)
                count++;
            CountLeaf(node->lchild, count);
            CountLeaf(node->rchild, count);
        }
        return count;
    }

    // Get height of binary tree
    int Height(BiNode<T> *node)
    {
        if (node == NULL)
            return 0;
        int L = Height(node->lchild);
        int R = Height(node->rchild);
        return (L > R) ? L + 1 : R + 1;
    }

    // Interfaces
    int LeafNumber()
    {
        int count = 0;
        return CountLeaf(root, count);
    }

    int TreeHeight()
    {
        return Height(root);
    }
};
int main()
{
    BiTree<char> T;

    cout << "Input binary tree (preorder, # for NULL):\n";
    T.CreateTree();

    cout << "Number of leaf nodes: " << T.LeafNumber() << endl;
    cout << "Height of binary tree: " << T.TreeHeight() << endl;

    return 0;
}