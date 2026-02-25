#include <iostream>
#include "ItemTracker.h"

using namespace std; 

//the menu shown to the user
void DisplayMenu() {
    cout << "\n--- Corner Grocer Tracking System ---" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose one of the numbers: ";
}

int main() {
    //initialize the item tracker and automatically creates the backup file
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");
    tracker.SaveBackupFile("frequency.dat");

    int choice = 0;
    string searchItem;

    //starts a loop until the user chooses 4
    while (choice != 4) {
        DisplayMenu();

        //input validation for if the user enters a non number value
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1-4." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        switch (choice) {
            //choice one to search for item frequency
        case 1:
            cout << "Enter the item name: ";
            cin >> searchItem;
            cout << searchItem << " frequency: " << tracker.GetItemFrequency(searchItem) << endl;
            break;
        case 2:
            tracker.PrintAllFrequencies(); //prints the frequencies
            break;
        case 3:
            tracker.PrintHistogram(); //prints the histogram
            break;
        case 4:
            cout << "Exiting program..." << endl; //exit message before ending loop
            break;
        default:
            cout << "Invalid option please try again." << endl; //notifies the user of an invalid number option
        }
    }

    return 0;
}