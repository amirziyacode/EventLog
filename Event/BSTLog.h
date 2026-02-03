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
    Node* insertEvent(Node*,Event);
    Node* deleteEvent(Node*,int);
    Node* minValueNode(Node*);
    void getEventsBetween(Node*,int,int,int&);
    void countCategories(Node*,int ,int);
    int getTotalDepth(Node*,int);
    int countNodes(Node*);
    Node* searchEventByTimestamp(Node*,int);
    void collectCategories(Node*,int,int,map<string,int>&,int&);
    public:
    void insertEvent(Event);
    void searchEventByTimestamp(int);
    void displayAllEvents();
    void deleteEvent(int);
    int getHeight(Node*);
    void getEventsBetween(int,int);
    void findClosestEvent(int);
    void showStatistics();
    void countCategories(int ,int);
    int getTotalDepth(int);
    int countNodes();
};


#endif //EVENTLOGERBST_BSTLOG_H