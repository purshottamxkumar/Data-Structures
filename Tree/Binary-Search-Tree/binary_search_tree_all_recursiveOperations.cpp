// This is a perfectly working program it is menu based/driven program, user has to enter the choice to perform any kind of the operation!
// This program is about BST(Binary Search Tree)!
// All functions in the program are the Recursive Functions!
// Made by Purshottam Kumar (purshottamxkumar  <--  GithubID)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int key) {
        data = key;
        left = right = NULL;
    }
};

Node* insertion(Node *root, int key) {
    if(root == NULL) {
        root = new Node(key);
    } else if(root->data > key) {
        root->left = insertion(root->left, key);
    } else if(root->data < key) {
        root->right = insertion(root->right, key);
    } else {
        cout << "\n## Key already present in Tree.\n";
    }
    return root;
}

Node *deletion(Node *root, int key) {
    if(root == NULL) {
        cout << "\n## Key not present in the Tree\n";
    } else if(root->data > key) {
        root->left = deletion(root->left, key);
    } else if(root->data < key) {
        root->right = deletion(root->right, key);
    } else {
        // element found
        if(root->right == NULL && root->left == NULL) {
            delete root;
            return NULL;
        } else if(root->left == NULL || root->right == NULL) {
            if(root->left == NULL) {
                Node *currNode = root;
                currNode = currNode->right;
                delete root;
                return currNode;
            } else if(root->right == NULL) {
                Node *currNode = root;
                currNode = currNode->left;
                delete root;
                return currNode;
            }
        } else if(root->left != NULL && root->right != NULL) {
            Node *tmp = root->right;
            while(tmp->left != NULL) {
                tmp = tmp->left;
            }
            swap(tmp->data, root->data);
            root->right = deletion(root, tmp->data);
        }
    }
    return root;
}

int countKeys(Node *root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + countKeys(root->left) + countKeys(root->right);
}

bool searchKey(Node *root, int key) {
    if(root == NULL) {
        return false;
    } else if(key < root->data) {
        return searchKey(root->left, key);
    } else if(key > root->data) {
        return searchKey(root->right, key);
    } return true;
}

void inorder(Node *root) {
    if(root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root) {
    if(root == NULL) {
        return ;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if(root == NULL) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(Node *root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

void maxKey(Node *root, int &maxi) {
    if(root == NULL) {
        return ;
    }
    if(root->data > maxi) {
        maxi = root->data;
    }
    maxKey(root->left, maxi);
    maxKey(root->right, maxi);
}

void minKey(Node *root, int &mini) {
    if(root == NULL) {
        return ;
    }
    if(root->data < mini) {
        mini = root->data;
    }
    minKey(root->left, mini);
    minKey(root->right, mini);
}

int main() {
    Node *root = NULL;
    int choice, key;
    while(1) {
        cout << "\nThese are the choices: ";
        cout << "\n0.Exit";
        cout << "\n1.Insertion";
        cout << "\n2.Deletion";
        cout << "\n3.Inorder";
        cout << "\n4.Preorder";
        cout << "\n5.Postorder";
        cout << "\n6.Total Keys in the Tree";
        cout << "\n7.Search Key in the Tree";
        cout << "\n8.Height of the Tree";
        cout << "\n9.Maximum Key in the Tree";
        cout << "\n10.Minimum Key in the Tree";
        cout << "\nEnter the choice: ";
        cin >> choice;

        switch(choice) {
            case 0: goto finalstatement;

            case 1: cout << "\nEnter the key to insert: ";
            cin >> key;
            root = insertion(root, key);
            break;

            case 2: cout << "\nEnter the key to delete: ";
            cin >> key;
            root = deletion(root, key);
            break;

            case 3: if(root == NULL) {
                cout << "\n## No keys are present in the Binary Search Tree\n";
            } else {
                cout << "\nInorder Traversal of the Binary Search Tree:\n";
                inorder(root);
                cout << "\n";
            }
            break;

            case 4: if(root == NULL) {
                cout << "\n## No keys are present in the Binary Search Tree\n";
            } else {
                cout << "\nPreorder Traversal of the Binary Search Tree:\n";
                preorder(root);
                cout << "\n";
            }
            break;

            case 5: if(root == NULL) {
                cout << "\n## No keys are present in the Binary Search Tree\n";
            } else {
                cout << "\nPostorder Traversal of the Binary Search Tree:\n";
                postorder(root);
                cout << "\n";
            }
            break;

            case 6: cout << "\nTotal Keys in the Tree: " << countKeys(root) << "\n";
            break;

            case 7: cout << "\nEnter the key to search in the Binary Search Tree: ";
            cin >> key;
            if(searchKey(root, key)) {
                cout << "\n## Key Present in the Binary Search Tree\n";
            } else cout << "\n## Key Not Present in the Binary Search Tree\n";
            break;

            case 8: cout << "\nHeight of the Binary Search Tree is: " << height(root) << "\n";
            break;

            case 9: key = INT_MIN;
            maxKey(root, key);
            cout << "\nMaximum Key in the Tree is: " << key << "\n";
            break;

            case 10: key = INT_MAX;
            minKey(root, key);
            cout << "\nMinimum Key in the Tree is: " << key << "\n";
            break;

            default:
            cout << "\n## Wrong Choice\n";
        }
    }
    finalstatement: cout << "\nHappy Coding!!!\n";
    return 0;
} // Termination of the program!