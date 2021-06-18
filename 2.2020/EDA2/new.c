#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
        return getNewNode(val);

    if (root->key < val)
        root->right = insert(root->right, val);

    else if (root->key > val)
        root->left = insert(root->left, val);

    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}

int main()
{
    int num;
    struct node *root = NULL;
    while (scanf("%d", &num) != EOF)
    {
        root = insert(root, num);
    }

    preorder(root);
    printf(" .");
    printf("\n");

    inorder(root);
    printf(" .");
    printf("\n");

    postorder(root);
    printf(" .");
    printf("\n");

    return 0;
}