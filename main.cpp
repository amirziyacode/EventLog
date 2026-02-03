#include <iostream>

#include "Event/BSTLog.h"
#include "Event/Event.h"

int main() {
    BSTLog bstLog;
    int choice;
    while (1) {
        cout << "\n--- Event Management System ---" << endl;
        cout << "0. ShowAllEvents \n1. Insert Event\n2. Delete Event\n3. Search Event by timeStamp\n4. Search Range\n5. Find Closest\n6. countCategoriesByRange\n7. Tree Stats\n8. Exit\nChoice: ";
        cin >> choice;
        if (choice == 0) {
            bstLog.displayAllEvents();
        }
        else if (choice == 1) {

            int id,timeStamp;
            string category,description;
            cout << "ID, Timestamp, Category, Description: ";
            cin >> id >> timeStamp >> category >> description;
            Event newEvent;
            newEvent.setId(id);
            newEvent.setTimestamp(timeStamp);
            newEvent.setCategory(category);
            newEvent.setDescription(description);
            bstLog.insertEvent(newEvent);
        }
        else if (choice == 2) {
            int timeStamp;
            cout << "Enter Event TimeStamp: ";
            cin >> timeStamp;
            bstLog.deleteEvent(timeStamp);
        }else if (choice == 3) {
            int timestamp;
            cout << "Enter Event Timestamp: ";
            cin >> timestamp;
            bstLog.searchEventByTimestamp(timestamp);
        }else if (choice == 4) {
            int t1,t2;
            cout << "Enter range of your Event want to find it (t1,t2)!";
            cin >> t1 >> t2;
            bstLog.getEventsBetween(t1,t2);
        }else if (choice == 5) {
            int time;
            cout << "Enter Your TimeStamp: ";
            cin >> time;
            bstLog.findClosestEvent(time);
        }else if (choice == 6) {
            int t1,t2;
            cout << "Enter range of your Event want to find it (t1,t2)!";
            cin >> t1 >> t2;
            bstLog.countCategories(t1,t2);
        }else if (choice == 7) {
            bstLog.showStatistics();
        }else if (choice == 8) {
            cout << "Good Bye!" << endl;
            break;
        }
    }
    return 0;
}