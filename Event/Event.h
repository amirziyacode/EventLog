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
    Event();
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
    void setId(int _id) {
        id = _id;
    };
    void setTimestamp(int _timestamp) {
        timestamp = _timestamp;
    }
    void setCategory(string _category) {
        category = _category;
    }
    void setDescription(string _description) {
        description = _description;
    }
};


#endif //EVENTLOGERBST_EVENT_H