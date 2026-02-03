//
// Created by amirziya on 1/21/26.
//

#include "BSTLog.h"

#include <climits>
#include <iostream>
#include <ostream>


void BSTLog::insertEvent(Event e) {
    root = insertEvent(root, e);
}

Node *BSTLog::insertEvent(Node * r,Event e) {
    if (!r) {
        Event newEvent(e.getId(), e.getTimestamp(), e.getCategory(), e.getDescription());
        return new Node(newEvent);
    }
    if (e.getTimestamp() > r->data.getTimestamp()) {
        r->right = insertEvent(r->right, e);
    }else {
        r->left = insertEvent(r->left,e);
    }
    return r;
}

void BSTLog::searchEventByTimestamp(int timeStamp) {
    const Node* result = searchEventByTimestamp(root, timeStamp);
   if (result == nullptr) {
       cout << "Event with " << timeStamp << " does not exist" << endl;
   }else {
       Event find = result->data;
       cout << "Event with: " << timeStamp << " {" << "ID: " <<  find.getId() << " category: " << find.getCategory() << " description: " << find.getDescription() << "} " << " founded ! "<< endl;
   }

}

Node * BSTLog::searchEventByTimestamp(Node * r, int timeStamp) {
    if (r == nullptr || r->data.getTimestamp() == timeStamp) {
        return r;
    }
    if (timeStamp > r->data.getTimestamp()) {
        return searchEventByTimestamp(r->right, timeStamp);
    }else {
        return searchEventByTimestamp(r->left, timeStamp);
    }
}

void BSTLog::displayAllEvents() {
    inorder(root);
}

void BSTLog::inorder(Node * r) {

    if (r == NULL) {
        return ;
    }
    inorder(r->left);
    cout << " EventID: " <<  r->data.getId() << " Time: "  << r->data.getTimestamp()  << " Category: " << r->data.getCategory() << " Description: " << r->data.getDescription() << endl;
    inorder(r->right);
}

void BSTLog::deleteEvent(int timestamp) {
    root = deleteEvent(root,timestamp);
    if (deleteEvent(root,timestamp) == nullptr) {
        cout << "Event Timestamp " << timestamp << " does not exist" << endl;
    }else {
        cout << "Event Timestamp " << timestamp << " deleted" << endl;
    }
    root = deleteEvent(root, timestamp);
}

Node* BSTLog::deleteEvent(Node * r, int timestamp) {
    if (!r) return r;

    if (timestamp < r->data.getTimestamp())
        r->left = deleteEvent(r->left, timestamp);
    else if (timestamp > r->data.getTimestamp())
        r->right = deleteEvent(r->right, timestamp);
    else {
        if (r->left == nullptr) {
            Node* temp = r->right;
            delete r;
            return temp;
        } else if (r->right == nullptr) {
            Node* temp = r->left;
            delete r;
            return temp;
        }
        Node* temp = minValueNode(r->right);
        r->data = temp->data;
        r->right = deleteEvent(r->right, temp->data.getTimestamp());
    }
    return r;
}
Node *BSTLog::minValueNode(Node *r) {
    Node* curr = r;
    while (curr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}
int BSTLog::getHeight(Node *r) {
    if (r == nullptr) return 0;
    return 1 + max(getHeight(r->right),getHeight(r->left)) ;
}

void BSTLog::getEventsBetween(int t1, int t2) {
    int count = 0;
    getEventsBetween(root, t1, t2,count);
    cout << ">>> Comparisons made for range search: " << count << endl;
}

void BSTLog::findClosestEvent(int t) {
    Node* current = root;
    Node* cloes = nullptr;
    int count = 0;
    long long minDiff = LLONG_MAX;
    while (current != nullptr) {
        count++;
        long long currentDiff = abs((long long)current->data.getTimestamp() - t);
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            cloes = current;
        }

        if (t < current->data.getTimestamp())
            current = current->left;
        else if (t > current->data.getTimestamp())
            current = current->right;
        else break;
    }

    if (cloes) {
        cout << "Closest Event: ID " << cloes->data.getId() << " at Time " << cloes->data.getTimestamp() << endl;
    }
    cout << ">>> Comparisons made for closest search: " << count << endl;
}


void BSTLog::getEventsBetween(Node * r,int t1,int t2,int& count) {
    if (r == nullptr) return;

    count++;
    if ( t1 < r->data.getTimestamp()) {
        getEventsBetween(r->left, t1, t2,count);
    }
    if (t1 <= r->data.getTimestamp() && t2 >= r->data.getTimestamp()) {
        cout << "Event " << r->data.getId() << " at " << r->data.getTimestamp() << endl;
    }
    if (t2 > r->data.getTimestamp()) {
        getEventsBetween(r->right, t1, t2,count);
    }
}

void BSTLog::countCategories(int t1, int t2) {
    map<string, int> counts;
    int queryCount = 0;
    collectCategories(root, t1, t2, counts,queryCount);

    cout << "Category counts between " << t1 << " and " << t2 << ":" << endl;
    if (counts.empty()) {
        cout << "No events found in this range." << endl;
    } else {
        for (auto const& [name, count] : counts) {
            cout << "- " << name << ": " << count << endl;
        }
    }
    cout << ">>> Comparisons made for category counting: " << queryCount << endl;
}

void BSTLog::collectCategories(Node* r, int t1, int t2, map<string, int>& counts,int& count) {
    if (r == nullptr) return;

    count++;

    if (t1 < r->data.getTimestamp())
        collectCategories(r->left, t1, t2, counts,count);

    if (r->data.getTimestamp() >= t1 && r->data.getTimestamp() <= t2)
        counts[r->data.getCategory()]++;

    if (t2 > r->data.getTimestamp())
        collectCategories(r->right, t1, t2, counts,count);
}

int BSTLog::getTotalDepth(int currentDepth) {
    getTotalDepth(root,currentDepth);
}
int BSTLog::getTotalDepth(Node * r, int currentDepth) {
    if (r == nullptr) {
        return 0;
    }
    return 1+currentDepth+getTotalDepth(r->left,currentDepth+1) + getTotalDepth(r->right,currentDepth+1);
}
int BSTLog::countNodes() {
   return  countNodes(root);
}
int BSTLog::countNodes(Node * r) {
    if (r == nullptr) {
        return 0;
    }
    return 1 + countNodes(r->left) + countNodes(r->right);
}


void BSTLog::showStatistics() {
    int n = countNodes();
    int h = getHeight(root);
    cout << "\n--- TreeAnalysis ---" << endl;
    cout << "Total Events: " << n << endl;
    cout << "Tree Height: " << h << endl;
    if (n > 0 ) {
        const double avgDepth = static_cast<double>(getTotalDepth(root, 0)) / n;
        cout << "Average Node Depth: " << avgDepth << endl;
    }
}