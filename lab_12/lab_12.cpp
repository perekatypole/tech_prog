#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;

int matrixSum(int matrix[][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void fillRandom(int matrix[][N]) {
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

struct Node {
    int key;
    int matrix[N][N];
    Node* left;
    Node* right;
};

Node* insert(Node* root, int key, int matrix[][N]) {
    if (!root) {
        root = new Node;
        root->key = key;
        root->left = root->right = NULL;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                root->matrix[i][j] = matrix[i][j];
            }
        }
        return root;
    }
    if (key < root->key) {
        root->left = insert(root->left, key, matrix);
    }
    else {
        root->right = insert(root->right, key, matrix);
    }
    return root;
}

void prefixTraversal(Node* root) {
    if (root) {
        cout << root->key << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << root->matrix[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        prefixTraversal(root->left);
        prefixTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int matrix[N][N];
    for (int i = 0; i < 10; i++) {
        fillRandom(matrix);
        root = insert(root, matrixSum(matrix), matrix);
    }
    prefixTraversal(root);
    return 0;
}
