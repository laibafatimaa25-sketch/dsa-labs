
#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    int score;
    Player* prev;
    Player* next;
};

Player* head = nullptr;  


Player* createNode(string name, int score) {
    Player* newNode = new Player;
    newNode->name = name;
    newNode->score = score;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void addPlayer(string name, int score) {
    Player* newNode = createNode(name, score);

    if (head == nullptr) {
        head = newNode;
        cout << "Player added successfully!\n";
        return;
    }

    Player* temp = head;

    if (score < head->score) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "Player added successfully!\n";
        return;
    }

   
    while (temp->next != nullptr && temp->next->score <= score) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;

    cout << "Player added successfully!\n";
}
void deletePlayer(string name) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Player* temp = head;

    while (temp != nullptr && temp->name != name)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Player not found!\n";
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;  

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    cout << "Player " << temp->name << " deleted successfully!\n";
    delete temp;
}

void displayAll() {
    if (head == nullptr) {
        cout << "No players in the list.\n";
        return;
    }

    cout << "\n--- Player Scores (Ascending Order) ---\n";
    Player* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << " | Score: " << temp->score << endl;
        temp = temp->next;
    }
    cout << "--------------------------------------\n";
}


void displayLowestScore() {
    if (head == nullptr) {
        cout << "No players in the list.\n";
        return;
    }

    cout << "\nPlayer with lowest score:\n";
    cout << "Name: " << head->name << " | Score: " << head->score << endl;
}

void displaySameScore(int score) {
    if (head == nullptr) {
        cout << "No players in the list.\n";
        return;
    }

    bool found = false;
    Player* temp = head;
    cout << "\nPlayers with score " << score << ":\n";
    while (temp != nullptr) {
        if (temp->score == score) {
            cout << "Name: " << temp->name << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
        cout << "No players found with that score.\n";
}

void displayBackwardFrom(string name) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Player* temp = head;

    while (temp != nullptr && temp->name != name)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Player not found.\n";
        return;
    }

    cout << "\nDisplaying backward from player " << temp->name << ":\n";
    while (temp != nullptr) {
        cout << "Name: " << temp->name << " | Score: " << temp->score << endl;
        temp = temp->prev;
    }
}


void displayDescending() {
    if (head == nullptr) {
        cout << "No players in the list.\n";
        return;
    }

    Player* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    cout << "\n--- Player Scores (Descending Order) ---\n";
    while (temp != nullptr) {
        cout << "Name: " << temp->name << " | Score: " << temp->score << endl;
        temp = temp->prev;
    }
    cout << "----------------------------------------\n";
}

int main() {
    int choice;
    string name;
    int score;

    do {
        cout << "\n========= Golf Tournament Menu =========\n";
        cout << "1. Add new player\n";
        cout << "2. Delete a player\n";
        cout << "3. Display all players (ascending)\n";
        cout << "4. Display all players (descending)\n";
        cout << "5. Display player with lowest score\n";
        cout << "6. Display players with same score\n";
        cout << "7. Display backward from a player\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter player name: ";
            cin >> name;
            cout << "Enter player score: ";
            cin >> score;
            addPlayer(name, score);
            break;

        case 2:
            cout << "Enter player name to delete: ";
            cin >> name;
            deletePlayer(name);
            break;

        case 3:
            displayAll();
            break;

        case 4:
            displayDescending();
            break;

        case 5:
            displayLowestScore();
            break;

        case 6:
            cout << "Enter score to search: ";
            cin >> score;
            displaySameScore(score);
            break;

        case 7:
            cout << "Enter player name to start from: ";
            cin >> name;
            displayBackwardFrom(name);
            break;

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}