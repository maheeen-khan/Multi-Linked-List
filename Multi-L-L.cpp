//Multi Linked List

#include <iostream>
using namespace std;

struct InnerNode {
    int data;
    InnerNode* next;
};

struct OuterNode {
    InnerNode* innerHead;
    OuterNode* next;
};

OuterNode* createOuterNode() {
    OuterNode* newNode = new OuterNode;
    newNode->innerHead = NULL;
    newNode->next = NULL;
    return newNode;
}

InnerNode* createInnerNode(int value) {
    InnerNode* newNode = new InnerNode;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertInnerNode(OuterNode* outerHead, int value) {
    if (outerHead == NULL) {
        cout << "Error: Outer head node is null." << endl;
        return;
    }
    InnerNode* newNode = createInnerNode(value);
    newNode->next = outerHead->innerHead;
    outerHead->innerHead = newNode;
}

void displayList(OuterNode* outerHead) {
    OuterNode* outerTemp = outerHead;
    while (outerTemp != NULL) {
        InnerNode* innerTemp = outerTemp->innerHead;
       
        while (innerTemp != NULL) {
            cout << innerTemp->data << " -> ";
            innerTemp = innerTemp->next;
        }
        cout<<"NULL";
        cout << endl;
        outerTemp = outerTemp->next;
        
    }
}

int main() {
    OuterNode* outerHead = createOuterNode();
    insertInnerNode(outerHead, 1);
    insertInnerNode(outerHead, 2);
    insertInnerNode(outerHead, 3);

    OuterNode* outerHead2 = createOuterNode();
    insertInnerNode(outerHead2, 4);
    insertInnerNode(outerHead2, 5);
    insertInnerNode(outerHead2, 6);
    insertInnerNode(outerHead2, 7);

    outerHead->next = outerHead2;

    displayList(outerHead);

    return 0;
}

