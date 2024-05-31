#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int ch, num;

    while (1) {
        printf("\n\tMAIN MENU\n1. Insert\n2. Search\n3. Preorder traversal\n4. Inorder traversal\n5. Postorder traversal\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &num);
                root = insert(root, num);
                break;

            case 2:
                printf("\nEnter number: ");
                scanf("%d", &num);
                struct Node* result = search(root, num);
                if (result != NULL) {
                    printf("Key %d found in the tree.\n", num);
                } else {
                    printf("Key %d not found in the tree.\n", num);
                }
                break;

            case 3:
                printf("\nPreorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nInorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("\nPostorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid input");
                break;
        }
    }

    return 0;
}
