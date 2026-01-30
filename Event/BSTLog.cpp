//
// Created by amirziya on 1/21/26.
//

#include "BSTLog.h"

#include <iostream>
#include <ostream>


void BSTLog::insertEvent(int _id, int _timeStamp, string _category, string _description) {
    root = insertEvent(root, _id, _timeStamp, _category, _description);
}

Node *BSTLog::insertEvent(Node * r, int _id, int _timeStamp, string _category, string _description) {
    if (!r) {
        Event newEvent(_id, _timeStamp, _category, _description);
        return new Node(newEvent);
    }
    if (_timeStamp > r->data.getTimestamp()) {
        r->right = insertEvent(r->right, _id, _timeStamp, _category, _description);
    }else {
        r->left = insertEvent(r->left, _id, _timeStamp, _category, _description);
    }
    return r;
}

Event BSTLog::searchEvent(int timeStamp) {
    root = searchEvent(root, timeStamp);
    return root->data;
}

Node * BSTLog::searchEvent(Node * r, int timeStamp) {
    if (r == nullptr || r->data.getTimestamp() == timeStamp) {
        return r;
    }
    if (timeStamp > r->data.getTimestamp()) {
        return searchEvent(r->right, timeStamp);
    }else {
        return searchEvent(r->left, timeStamp);
    }
}

void BSTLog::inorder() {
    inorder(root);
}

void BSTLog::inorder(Node * r) {

    if (!r) {
        return ;
    }
    inorder(r->left);
    cout << " EventID: " <<  r->data.getId() << " TimeStapm: "  << r->data.getTimestamp()  << " Category: " << r->data.getCategory() << " Description: " << r->data.getDescription() << endl;
    inorder(r->right);
}

void BSTLog::deleteByEventID(int id) {
    root = deleteByEventID(root, id);
}

Node* BSTLog::deleteByEventID(Node * r, int id) {
    if (!r) {
        return r;
    }

   if (r->data.getId() == id) {
           // one or zero child
           if (r->left == nullptr) {
               Node* temp = r->right;
               delete r;
               return temp;
           }if (r->right == nullptr) {
               Node* temp = r->left;
               delete r;
               return temp;
           }
           // two childe
           Node* temp = minValueNode(r->right);
           r->data = temp->data;
           r->right = deleteByEventID(r->right,temp->data.getId());
           return r;
   }

    r->right = deleteByEventID(r->right, id);
    r->left = deleteByEventID(r->left, id);

    return r;
}
Node *BSTLog::minValueNode(Node *r) {
    Node* curr = r;
    while (curr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}
