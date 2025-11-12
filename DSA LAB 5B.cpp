#include <iostream>
using namespace std;

struct Node {
    float rainfall;
    Node* prev;
    Node* next;
};

// Head pointer
Node* head = nullptr;

// Function to insert rainfall data at end
void insertRainfall(float value) {
    Node* newNode = new Node;
    newNode->rainfall = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display rainfall data
void displayList() {
    Node* temp = head;
    int day = 1;
    cout << "\nRainfall Data:\n";
    while (temp != nullptr) {
        cout << "Day " << day++ << ": " << temp->rainfall << " mm\n";
        temp = temp->next;
    }
}

// Function to calculate total rainfall
float totalRainfall() {
    Node* temp = head;
    float total = 0;
    while (temp != nullptr) {
        total += temp->rainfall;
        temp = temp->next;
    }
    return total;
}

// Function to find average rainfall
float averageRainfall(float total, int days) {
    return total / days;
}

// Function to find highest and lowest rainfall
void findHighLow() {
    if (head == nullptr) {
        cout << "\nNo data available.\n";
        return;
    }

    Node* temp = head;
    float highest = temp->rainfall;
    float lowest = temp->rainfall;
    int highDay = 1, lowDay = 1, day = 1;

    while (temp != nullptr) {
        if (temp->rainfall > highest) {
            highest = temp->rainfall;
            highDay = day;
        }
        if (temp->rainfall < lowest) {
            lowest = temp->rainfall;
            lowDay = day;
        }
        temp = temp->next;
        day++;
    }

    cout << "\nHighest rainfall: " << highest << " mm on Day " << highDay;
    cout << "\nLowest rainfall: " << lowest << " mm on Day " << lowDay << endl;
}

// Function to display rainfall of day after 5th node
void rainfallAfterFifth() {
    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < 6) { // Move to 6th node
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
        cout << "\nThere is no day after the 5th node (list too short)." << endl;
    else
        cout << "\nRainfall of day after 5th node (Day 6): " << temp->rainfall << " mm" << endl;
}

int main() {
    const int DAYS = 7;
    float rainfallInput;

    cout << "Enter rainfall data for 7 days (in mm):\n";

    for (int i = 1; i <= DAYS; i++) {
        do {
            cout << "Day " << i << ": ";
            cin >> rainfallInput;
            if (rainfallInput < 0)
                cout << "Invalid input! Rainfall cannot be negative.\n";
        } while (rainfallInput < 0);

        insertRainfall(rainfallInput);
    }

    displayList();

    float total = totalRainfall();
    float average = averageRainfall(total, DAYS);

    cout << "\nTotal rainfall for the week: " << total << " mm";
    cout << "\nAverage weekly rainfall: " << average << " mm";

    findHighLow();
    rainfallAfterFifth();

    return 0;
}


