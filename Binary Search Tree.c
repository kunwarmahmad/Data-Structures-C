/*DSA Assignment 3
        Created By
FA20-BSE-064(HAFIZ KUNWAR MUHAMMAD AHMAD)*/
#include<stdio.h>
#include<stdlib.h>

struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
};
struct bst *root = 0;

struct bst *insert(struct bst *root, int data)
{
    struct bst *temp;
    temp = (struct bst*) malloc(sizeof(struct bst));
    temp->data = data;
    temp->left = temp->right = 0;

    if(root==0) //For first Value
    {
        root = temp;
        return root;
    }

    if(data == root->data)  //For Duplicate Values
        return root;
    else if(data < root->data) //For Smaller Values
    {
        root->left = insert(root->left, data);
        return root;
    }
    else if(data > root->data) //For Greater Values
    {
        root->right = insert(root->right, data);
        return root;
    }

};

void preOrder(struct bst *root)
{
    struct bst *temp;
    temp = root;
    if(temp!=0)
    {
        printf("\t%d ", temp->data);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void inOrder(struct bst *root)
{
    struct bst *temp;
    temp = root;
    if(temp!=0)
    {
        inOrder(temp->left);
        printf("\t%d ", temp->data);
        inOrder(temp->right);
    }
}

void postOrder(struct bst *root)
{
    struct bst *temp;
    temp = root;
    if(temp!=0)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        printf("\t%d ", temp->data);
    }
}

int FindMin2(struct bst *root)
{
    struct bst *temp;
    temp = root;
    while(temp->left!=0)
        temp = temp->left;
    return temp;

}

void FindMax(struct bst *root)
{
    struct bst *temp;
    temp = root;
    while(temp->right!=0)
        temp = temp->right;
    printf("\nLargest Value : %d", temp->data);

}

struct bst *search(struct bst *root, int data)
{
     if(root==0) //if Value not Found
    {
        return NULL;
    }

    if(data == root->data)  //if Value Found
        return root;
    else if(data < root->data) //For Smaller Values
    {
        return search(root->left, data);
    }
    else //For Greater Values
    {
        return search(root->right, data);
    }
};

struct bst *deleteNode(struct bst *root, int data)
{
    //Search the node to be deleted
    if(root==0)
        return root;
    else if(data < root->data)
        root->left = deleteNode(root->left,data);
    else if(data > root->data)
        root->right = deleteNode(root->right,data);

    //Found the node to be deleted
    else
    {
        //Case 1 : No Child
        if(root->left == 0 && root->right == 0)
        {
            free(root);
            root = 0;
        }
        //Case 2 : 1 Child
        else if(root->left == 0)
        {
            struct bst *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == 0)
        {
            struct bst *temp = root;
            root = root->left;
            free(temp);
        }
        //Case 3 : 2 Children
        else
        {
            //In-order successor
            struct bst *temp = FindMin2(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    //Tree Creation using Insertion
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 65);
    root = insert(root, 25);
    root = insert(root, 90);
    root = insert(root, 5);
    root = insert(root, 34);
    printf("\n\nBST : ");
    preOrder(root);

    // a) Deleting nodes 25 and 65
    deleteNode(root, 25);
    deleteNode(root, 65);
    printf("\n\nBST after deleting 25 and 65 : \n");
    preOrder(root);

    // b) Traversing Tree using Pre order
    printf("\n\nPre Order Traversal : ");
    preOrder(root);

    //in order Traversal
    printf("\n\nIn Order Traversal : ");
    inOrder(root);

    //Post order Traversal
    printf("\n\nPost Order Traversal : ");
    postOrder(root);
    printf("\n\n");

    // c) Search any Value from BST
    root = search(root, 5);
    if(root!=0)
        printf("Value Found : %d", root->data);
    else
        printf("Value Not Found.");
    printf("\n\n");

    root = search(root, 15);
    if(root!=0)
        printf("Value Found : %d", root->data);
    else
        printf("Value Not Found.");
    printf("\n");


    // d) Insert 45 and 100
    root = insert(root, 45);
    root = insert(root, 100);

    // e) Find Largest Value from BST
    FindMax(root);
    printf("\n\n");

    return 0;
}
