#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(struct Node* root) 
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) 
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) 
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct Node* search(struct Node* root, int value) 
{
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}
struct Node* findMin(struct Node* root) 
{
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
struct Node* findMax(struct Node* root) 
{
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
int main() {
    struct Node* root = NULL;
    int n, value, searchValue;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
    	
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n\nEnter value to search: ");
    scanf("%d", &searchValue);
    if (search(root, searchValue) != NULL) {
        printf("Value %d found in the tree.\n", searchValue);
    } else {
        printf("Value %d not found in the tree.\n", searchValue);
    }
    struct Node* minNode = findMin(root);
    if (minNode != NULL) {
        printf("Minimum value: %d\n", minNode->data);
    }
    struct Node* maxNode = findMax(root);
    if (maxNode != NULL) {
        printf("Maximum value: %d\n", maxNode->data);
    }
    return 0;
}