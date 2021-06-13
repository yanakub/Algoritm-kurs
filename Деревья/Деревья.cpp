#include <stdlib.h>
#include <iostream>


using namespace std;
typedef int T;

#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))

typedef struct Node {
    T data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;


Node* getFreeNode(T value, Node* parent) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}


void insert(Node** head, int value) {
    Node* tmp = NULL;
    Node* ins = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp) {
        if (CMP_GT(value, tmp->data)) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            }
            else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (CMP_LT(value, tmp->data)) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            }
            else {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else {
            exit(2);
        }
    }
}


Node* getMaxNode(Node* root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}


Node* getMinNode(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}


Node* search(Node* root, T value) {
    while (root) {
        if (CMP_GT(root->data, value)) {
            root = root->left;
            continue;
        }
        else if (CMP_LT(root->data, value)) {
            root = root->right;
            continue;
        }
        else {
            return root;
        }
    }
    return NULL;
}



void removeNode(Node* target) {
    if (target->left && target->right) {
        Node* localMax = getMaxNode(target->left);
        target->data = localMax->data;
        removeNode(localMax);
        return;
    }
    else if (target->left) {
        if (target == target->parent->left) {
            target->parent->left = target->left;
        }
        else {
            target->parent->right = target->left;
        }
    }
    else if (target->right) {
        if (target == target->parent->right) {
            target->parent->right = target->right;
        }
        else {
            target->parent->left = target->right;
        }
    }
    else {
        if (target == target->parent->left) {
            target->parent->left = NULL;
        }
        else {
            target->parent->right = NULL;
        }
    }
    free(target);
}


void remove(Node* root, T value) {
    Node* target = search(root, value);
    removeNode(target);
}


void print(Node* root, const char* dir, int level) {
    if (root) {
        printf("lvl %d %s = %d\n", level, dir, root->data);
        print(root->left, "left", level + 1);
        print(root->right, "right", level + 1);
    }
}



void main() {
    setlocale(LC_ALL, "Russian");
    Node* root = NULL;

    cout << "Дерево (рис.1):" << endl;

    insert(&root, 6);
    insert(&root, 10);
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 8);
    insert(&root, 1);
    insert(&root, 11);
    print(root, "root", 0);

    cout << "Находим элемент 1 и 10:" << endl;
    cout << "Родитель элемента 1: " << search(root, 1)->parent->data << endl;
    cout << "Родитель элемента 10: " << search(root, 10)->parent->data << endl;
    cout << "\nУдаляем элемент 1. Теперь дерево выглядит так (рис.2):" << endl;
    remove(root, 1);
    print(root, "root", 0);

    cout << "\nУдаляем элемент 10. Теперь дерево выглядит так (рис.3):" << endl;
    remove(root, 10);
    print(root, "root", 0);

    cout << "\nДобавляем элемент 10. Теперь дерево выглядит так (рис.4):" << endl;
    insert(&root, 10);
    print(root, "root", 0);


    cout << "Находим элемент 10:" << endl;
    cout << "Родитель элемента 10: " << search(root, 10)->parent->data << endl;

}