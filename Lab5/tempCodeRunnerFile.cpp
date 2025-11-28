#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    bool inPenalty;
    Player* next;

    Player(string n) {
        name = n;
        inPenalty = false;
        next = nullptr;
    }
};

class Game {
private:
    Player* current; 
    bool clockwise;  
public:
    Game() {
        current = nullptr;
        clockwise = true;
    }
    void addPlayer(string name) {
        Player* newPlayer = new Player(name);
        if (!current) {
            current = newPlayer;
            newPlayer->next = newPlayer; 
        } else {
            Player* temp = current;
            while (temp->next != current)
                temp = temp->next;
            temp->next = newPlayer;
            newPlayer->next = current;
        }
        cout << "Added player: " << name << endl;
    }
    void removePlayer(string name) {
        if (!current) return;

        Player* temp = current;
        Player* prev = nullptr;
        do {
            if (temp->name == name) {
                if (prev) prev->next = temp->next;
                else {
                    Player* last = current;
                    while (last->next != current) last = last->next;
                    last->next = temp->next;
                    current = temp->next;
                }

                cout << name << " has quit the game.\n";
                delete temp;
                if (current == current->next) current->next = current;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != current);

        cout << "Player not found: " << name << endl;
    }

    void givePenalty(string name) {
        if (!current) return;
        Player* temp = current;
        do {
            if (temp->name == name) {
                temp->inPenalty = true;
                cout << name << " got a pen