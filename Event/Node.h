//
// Created by amirziya on 1/21/26.
//

#ifndef EVENTLOGERBST_NODE_H
#define EVENTLOGERBST_NODE_H
#include "Event.h"


class Node {


    public:
    Node(Event _data);
    Event data;
    Node* left;
    Node* right;
};


#endif //EVENTLOGERBST_NODE_H