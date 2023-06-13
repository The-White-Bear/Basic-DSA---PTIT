#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void insert(Node *root, int a, int b, char c)
{
    if (root == NULL)
    {
        return;
    }

    if (root->val == a)
    {
        if (c == 'L')
        {
            root->left = new Node(b);
        }
        if (c == 'R')
        {
            root->right = new Node(b);
        }
    }
    else
    {
        insert(root->left, a, b, c);
        insert(root->right, a, b, c);
    }
}

bool check_same_level(Node *root)
{
    if (root == NULL)
        return true;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int nodeCount = q.size();
        bool foundLeaf = false;

        while (nodeCount > 0)
        {
            Node *currentNode = q.front();
            q.pop();

            if (currentNode->left == NULL && currentNode->right == NULL)
            {
                if (foundLeaf)
                {
                    return false;
                }
                foundLeaf = true;
            }

            if (currentNode->left != NULL)
            {
                q.push(currentNode->left);
            }

            if (currentNode->right != NULL)
            {
                q.push(currentNode->right);
            }

            nodeCount--;
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    Node *root = NULL;

    while (n--)
    {
        int u, v;
        char x;
        cin >> u >> v >> x;

        if (root == NULL)
        {
            root = new Node(u);
            if (x == 'L')
            {
                root->left = new Node(v);
            }
            if (x == 'R')
            {
                root->right = new Node(v);
            }
        }
        else
        {
            insert(root, u, v, x);
        }
    }

    if (check_same_level(root))
    {
        cout << "Cung muc";
    }
    else
    {
        cout << "Khong cung muc";
    }

    return 0;
}
