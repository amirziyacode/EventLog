//
// Created by amirziya on 1/21/26.
//

#include "Event.h"

Event::Event() {
    id = 0;
    timestamp = 0;
    category = "";
    description = "";
}

Event::Event(int _id, int _timeStamp, string _category, string _description) {
    if (_id > 0) {
        id = _id;
    }
    if (_timeStamp > 0) {
        timestamp = _timeStamp;
    }
    if (!_category.empty()) {
        category = _category;
    }
    if (!_description.empty()) {
        description = _description;
    }
}
