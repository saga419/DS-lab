#include <stdio.h>
#include <stdlib.h>

/* Structure of BST node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new node */
struct node *createNode(int item) {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    return p;
}

/* Insert a node in BST */
struct node *insert(struct node *root, int item) {
    if (root == NULL)
        return createNode(item);

    if (item < root->data)
        root->left = insert(root->left, item);
    else if (item > root->data)
        root->right = insert(root->right, item);

    return root;
}

/* In-order traversal */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Pre-order traversal */
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Post-order traversal */
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Main function */
int main() {
    struct node *root = NULL;
    int n, i, item;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &item);
        root = insert(root, item);
    }

    printf("\nIn-order Traversal: ");
    inorder(root);

    printf("\nPre-order Traversal: ");
    preorder(root);

    printf("\nPost-order Traversal: ");
    postorder(root);

    return 0;
}
