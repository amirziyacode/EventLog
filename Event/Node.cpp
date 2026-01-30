//
// Created by amirziya on 1/21/26.
//

#include "Node.h"
#include "Event.h"



Node::Node(Event _data) : data(_data) {
    left = right = NULL;
}
