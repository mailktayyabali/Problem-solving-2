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
                cout << name << " got a penalty! Turn will be skipped next round.\n";
                return;
            }
            temp = temp->next;
        } while (temp != current);
        cout << "Player not found: " << name << endl;
    }
    void reverseDirection() {
        clockwise = !clockwise;
        cout << "Turn direction reversed! (" << (clockwise ? "Clockwise" : "Counterclockwise") << ")\n";
    }
   void specialCard(string type) {
        if (type == "skip") {
            cout << "Special Card: Next player's turn skipped!\n";
            nextTurn(true);
        } else if (type == "reverse") { 
            reverseDirection();
        } else {
            cout << "No effect card.\n";
        }
    }
    void nextTurn(bool skipNext = false) {
        if (!current) return;

        cout << "\n=== Turn System ===\n";
        Player* nextPlayer = current;

        do {
            if (clockwise)
                nextPlayer = nextPlayer->next;
            else {
                Player* temp = nextPlayer;
                while (temp->next != nextPlayer) temp = temp->next;
                nextPlayer = temp;
            }
            if (nextPlayer->inPenalty) {
                cout << nextPlayer->name << " is in penalty. Skipping their turn.\n";
                nextPlayer->inPenalty = false; // clear penalty after skipping
                continue;
            }

            if (skipNext) {
                cout << nextPlayer->name << " was skipped due to special card!\n";
                skipNext = false;
                continue;
            }

            current = nextPlayer;
            cout << "It's " << current->name << "'s turn!\n";
            return;

        } while (nextPlayer != current);

        cout << "No valid player found (all in penalty?).\n";
    }
    void showPlayers() {
        if (!current) {
            cout << "No players in the game.\n";
            return;
        }
        cout << "\n--- Current Players ---\n";
        Player* temp = current;
        do {
            cout << temp->name;
            if (temp == current) cout << "  <-- current turn";
            cout << endl;
            temp = temp->next;
        } while (temp != current);
    }
};
int main() {
    Game game;
    game.addPlayer("Ali");
    game.addPlayer("Sara");
    game.addPlayer("Bilal");
    game.addPlayer("Tayyab");
    game.showPlayers();
    game.nextTurn();
    game.nextTurn();
    game.givePenalty("Sara");
    game.nextTurn();
    game.reverseDirection();
    game.specialCard("skip");
    game.nextTurn();
    game.removePlayer("Bilal");
    game.showPlayers();

    return 0;
}
