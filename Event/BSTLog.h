//
// Created by amirziya on 1/21/26.
//

#ifndef EVENTLOGERBST_BSTLOG_H
#define EVENTLOGERBST_BSTLOG_H
#include <map>

#include "Node.h"


class BSTLog {
    private:
    Node* root = NULL;
    void inorder(Node*);
    Node* insertEvent(Node*,int,int,string,string);
    Node* searchEvent(Node*,int);
    Node* deleteByEventID(Node*,int);
    Node* minValueNode(Node*);
    void getEventsBetween(Node*,int,int);
    void countCategories(Node*,int ,int , map<string,int>&);
    public:
    void insertEvent(int,int,string,string);
    Event searchEvent(int);
    void displayAllEvents();
    void deleteByEventID(int);
    int getHeight(Node*);
    void getEventsBetween(int,int);
    void findClosestEvent(int);
    void showStatistics();
    void countCategories(int ,int);
};


#endif //EVENTLOGERBST_BSTLOG_H