// IsBinaryTreeBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

bool AllSmaller(Node* pNode, Node* pLeft)
{
    if (pLeft == nullptr)
        return true;

    if (pLeft->data >= pNode->data)
        return false;

    return AllSmaller(pNode, pLeft->left) && AllSmaller(pNode, pLeft->right);
}

bool AllGreater(Node* pNode, Node* pRight)
{
    if (pRight == nullptr)
        return true;

    if (pRight->data < pNode->data)
        return false;

    return AllGreater(pNode, pRight->left) && AllGreater(pNode, pRight->right);
}

bool IsBST(Node* root)
{
    if (root == nullptr)
        return true;

    if (!AllSmaller(root, root->left) || !AllGreater(root, root->right))
        return false;

    return IsBST(root->left) && IsBST(root->right);
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in BST: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "The nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
        {
            std::cin >> v[i];
        }

        Node* pRoot = ArrayToTree(v);

        std::cout << "The tree is " << (IsBST(pRoot) ? "" : "not ") << "BST" << std::endl;

        FreeTree(pRoot);
    }
}
