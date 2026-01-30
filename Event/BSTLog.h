//
// Created by amirziya on 1/21/26.
//

#ifndef EVENTLOGERBST_BSTLOG_H
#define EVENTLOGERBST_BSTLOG_H
#include "Node.h"


class BSTLog {
    private:
    Node* root = NULL;
    void inorder(Node*);
    Node* insertEvent(Node*,int,int,string,string);
    Node* searchEvent(Node*,int);
    Node* deleteByEventID(Node*,int);
    Node* minValueNode(Node*);
    public:
    void insertEvent(int,int,string,string);
    Event searchEvent(int);
    void inorder();
    void deleteByEventID(int);
};


#endif //EVENTLOGERBST_BSTLOG_H