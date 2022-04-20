#pragma once
#include "NGO.h"
#include <vector>
using namespace std;


struct Node {

    unsigned long int val; // node's value (income belonging to all nonprofits)
    Node* left;
    Node* right;
    Node* parent;
    bool isRed = false; // false if black, true if red
    vector<NGO*> nonprofits; // vector storing all nonprofits that belong to unique profit node

};

class RedBlackTree {

private:
    Node* head; // head of red-black tree
    int size; // number of unique NODES, not number of nonprofits (multiple nonprofits can belong to same node)

public:
    RedBlackTree(); // constructor
    Node* getHead(); // get head of red-black tree
    void insert(NGO* toBeInserted); // insert nonprofit
    void insertHelper(Node* node); // insertion helper
    void rotateRight(Node* node); // right rotation helper
    void rotateLeft(Node* node); // left rotation helper
    bool getRed(Node* node); //returns true if node is red, false if black
    Node* getGrandparent(Node* node); // get grandparent of node
    Node* getUncle(Node* node); // get uncle of node
    bool isLeftChild(Node* node); // returns true if node is a left child, false if it's a right child
    vector<NGO*> search(unsigned long int income); // search by name
    vector<NGO*> flatten(Node* node, unsigned long int min, unsigned long int max); // convert all nonprofits into sorted vector
    void flattenHelper(Node* node, vector<NGO*>& vect, unsigned long int min, unsigned long int max); // helper for flatten
    Node* searchNode(unsigned long int income); // Get the node with key income
    Node* searchNodeHelper(unsigned long int income, Node* node); // Helper for searchNode

};