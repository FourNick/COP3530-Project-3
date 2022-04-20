#include <iostream>
#include <queue>
#include "NGO.h"
#include "RedBlackTree.h"
using namespace std;

RedBlackTree::RedBlackTree() { // initialize basic values

    size = 0;
    head = nullptr;

}

Node* RedBlackTree::getHead() { // returns head pointer

    return head;


}

void RedBlackTree::insert(NGO* toBeInserted) {

    Node* node = new Node; // construct new node according to input NGO
    node->val = toBeInserted->getIncome();
    node->isRed = true;
    node->left = nullptr;
    node->right = nullptr;

    Node* currentParent = nullptr;
    Node* currentNode = head;

    while (currentNode != nullptr) { // cycle through tree until correct spot to insert is found

        currentParent = currentNode;

        if (node->val < currentNode->val)
            currentNode = currentNode->left;
        else if (node->val > currentNode->val)
            currentNode = currentNode->right;
        else { // a nonprofit already exists with this income value, append to existing node and end

            currentNode->nonprofits.push_back(toBeInserted);
            return;

        }
    }

    size++;
    node->nonprofits.push_back(toBeInserted);
    node->parent = currentParent;

    if (currentParent == nullptr) { // handle case w/ empty tree
        head = node;
        node->isRed = false;
        return;
    }
    else if (node->val < currentParent->val) // assign parent pointer properly
        currentParent->left = node;
    else
        currentParent->right = node;

    if (node->parent->parent == nullptr) // no grandparent, no need to continue
        return;
    else
        insertHelper(node); // if grandparent is present, there may have to be recoloring/rotations

}

void RedBlackTree::insertHelper(Node* node) {

    Node* uncle;

    while (getRed(node->parent)) { // continue until no red parents (red-black property is restored)
        if (!isLeftChild(node->parent)) {
            uncle = getUncle(node);
            if (getRed(uncle)) { // red uncle and right parent case
                uncle->isRed = false;
                node->parent->isRed = false;
                getGrandparent(node)->isRed = true;
                node = getGrandparent(node);
            }
            else {
                if (isLeftChild(node)) { // red uncle and left child case
                    node = node->parent;
                    rotateRight(node);

                }
                node->parent->isRed = false; // red uncle and right child case
                getGrandparent(node)->isRed = true;
                rotateLeft(getGrandparent(node));

            }
        }
        else {
            uncle = getUncle(node);
            if (getRed(uncle)) { // black uncle and left parent case
                uncle->isRed = false;
                node->parent->isRed = false;
                getGrandparent(node)->isRed = true;
                node = getGrandparent(node);

            }
            else {
                if (!isLeftChild(node)) { // black uncle and right child case
                    node = node->parent;
                    rotateLeft(node);

                }
                node->parent->isRed = false; // black uncle and left child case
                getGrandparent(node)->isRed = true;
                rotateRight(getGrandparent(node));

            }

        }
        if (node == head) // stop once we ascend all the way through tree
            break;
    }

    head->isRed = false; // ensure that head is never red

}

void RedBlackTree::rotateRight(Node* node) { // basic right rotation operation

    Node* leftSubtree = node->left;
    node->left = leftSubtree->right;

    if (leftSubtree->right != nullptr)
        leftSubtree->right->parent = node;

    leftSubtree->parent = node->parent;

    if (node->parent == nullptr)
        head = leftSubtree;
    else if (isLeftChild(node))
        node->parent->left = leftSubtree;
    else
        node->parent->right = leftSubtree;

    leftSubtree->right = node;
    node->parent = leftSubtree;

}

void RedBlackTree::rotateLeft(Node* node) { // basic left rotation operation

    Node* rightSubtree = node->right;
    node->right = rightSubtree->left;

    if (rightSubtree->left != nullptr)
        rightSubtree->left->parent = node;

    rightSubtree->parent = node->parent;

    if (node->parent == nullptr)
        head = rightSubtree;
    else if (isLeftChild(node))
        node->parent->left = rightSubtree;
    else
        node->parent->right = rightSubtree;

    rightSubtree->left = node;
    node->parent = rightSubtree;

}


bool RedBlackTree::getRed(Node* node) { // get red status of node. nulls are black

    if (node == nullptr)
        return false;
    else
        return node->isRed;

}

Node* RedBlackTree::getGrandparent(Node* node) { // get grandparent node, can return nullptr if grandparent does not exist

    if (node->parent == nullptr)
        return nullptr;
    else
        return node->parent->parent;

}

Node* RedBlackTree::getUncle(Node* node) { // get uncle, can return nullptr if uncle does not exist

    if (node->parent == nullptr)
        return nullptr;
    else if (isLeftChild(node->parent)) {
        if (getGrandparent(node) != nullptr) {
            return getGrandparent(node)->right;
        }
    }
    else {
        if (getGrandparent(node) != nullptr) {
            return getGrandparent(node)->left;
        }
    }
    return nullptr;

}

bool RedBlackTree::isLeftChild(Node* node) { // check if node is a left child. returns false if it is a right child

    if (node->parent == nullptr)
        return false;
    if (node->parent->left != nullptr)
        return (node == node->parent->left);
    else
        return false;

}

vector<NGO*> RedBlackTree::search(unsigned long int income) { // find all matches of substring within the tree

    vector<NGO*> matches;
    queue<Node*> q;
    q.push(head);
    while (!q.empty()) { // BFS

        if (q.front()->left != nullptr)
            q.push(q.front()->left);
        if (q.front()->right != nullptr)
            q.push(q.front()->right);

        for (NGO* nonprofit : q.front()->nonprofits) {

            if (nonprofit->getIncome() == income)
                matches.push_back(nonprofit);

        }

        q.pop();

    }
    return matches;

}

Node* RedBlackTree::searchNode(unsigned long int income) {

    return searchNodeHelper(income, head);

}

Node* RedBlackTree::searchNodeHelper(unsigned long int income, Node* node) {
    if (income == node->val)
    {
        return node;
    }
    else if (income < node->val)
    {
        return searchNodeHelper(income, node->left);
    }
    else if (income > node->val)
    {
        return searchNodeHelper(income, node->right);
    }
}

vector<NGO*> RedBlackTree::flatten(Node* node, unsigned long int min, unsigned long int max) {

    vector<NGO*> matches;
    flattenHelper(head, matches, min, max); // pass vector by reference so everything can get added with recursion
    return matches;

}

void RedBlackTree::flattenHelper(Node* node, vector<NGO*>& vect, unsigned long int min, unsigned long int max) { // helper function for flatten, uses inorder traversal to maintain sorted vector for easier future operations


    if (node->val < min )
    {
        return;
    }

    if (node->left != nullptr)
        flattenHelper(node->left, vect, min, max);
    if (node->val > max)
    {
        return;
    }
    for (NGO* nonprofit : node->nonprofits) {
        if (nonprofit->getIncome() > min && nonprofit->getIncome() < max) {

            vect.push_back(nonprofit);

        }

    }


    if (node->right != nullptr)
        flattenHelper(node->right, vect, min, max);

}
