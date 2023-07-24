#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insertNode(struct Node* root, char data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void storePreOrder(struct Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }
    fprintf(file, "%c ", root->data);
    storePreOrder(root->left, file);
    storePreOrder(root->right, file);
}
void storeInOrder(struct Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }
    storeInOrder(root->left, file);
    fprintf(file, "%c ", root->data);
    storeInOrder(root->right, file);
}

void storePostOrder(struct Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }
    storePostOrder(root->left, file);
    storePostOrder(root->right, file);
    fprintf(file, "%c ", root->data);
}

int main() {
    struct Node* root = NULL;
    int i, count;
    char ch;

    printf("Enter the number of characters to generate: ");
    scanf("%d", &count);

    FILE* randomCharFile = fopen("random_characters.txt", "w");
    if (randomCharFile == NULL) {
        printf("Failed to open random_characters.txt\n");
        return 1;
    }
    srand(time(NULL));
    for (i = 0; i < count; i++) {
        ch = 'A' + (rand() % 26);
        fprintf(randomCharFile, "%c ", ch);
        root = insertNode(root, ch);
    }
    fclose(randomCharFile);
    printf("Random characters stored in random_characters.txt\n");

    FILE* preOrderFile = fopen("preorder.txt", "w");
    if (preOrderFile == NULL) {
        printf("Failed to open preorder.txt\n");
        return 1;
    }
    storePreOrder(root, preOrderFile);
    fclose(preOrderFile);
    printf("Pre-order traversal stored in preorder.txt\n");

    FILE* inOrderFile = fopen("inorder.txt", "w");
    if (inOrderFile == NULL) {
        printf("Failed to open inorder.txt\n");
        return 1;
    }
    storeInOrder(root, inOrderFile);
    fclose(inOrderFile);
    printf("In-order traversal stored in inorder.txt\n");

    FILE* postOrderFile = fopen("postorder.txt", "w");
    if (postOrderFile == NULL) {
        printf("Failed to open postorder.txt\n");
        return 1;
    }
    storePostOrder(root, postOrderFile);
    fclose(postOrderFile);
    printf("Post-order traversal stored in postorder.txt\n");

    return 0;
}
