//
// Created by amirziya on 1/21/26.
//

#ifndef EVENTLOGERBST_EVENT_H
#define EVENTLOGERBST_EVENT_H
#include <string>
using  namespace std;

class Event {
private:
    int id;
    int timestamp;
    string category;
    string description;
    public:
    Event(int,int,string,string);
    int getId() {
        return id;
    };
    int getTimestamp() {
        return timestamp;
    }
    string getCategory() {
        return category;
    }
    string getDescription() {
        return description;
    }
};


#endif //EVENTLOGERBST_EVENT_H