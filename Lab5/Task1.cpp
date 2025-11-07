#include <iostream>
#include <string>
using namespace std;
struct Song {
    string title;
    string artist;
    int duration;
    Song* next;
};
Song* head = nullptr;
void addSong(string title, string artist, int duration) {
    Song* newSong = new Song;
    newSong->title = title;
    newSong->artist = artist;
    newSong->duration = duration;
    newSong->next = nullptr;
    if (head == nullptr) {
        head = newSong;
    } else {
        Song* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newSong;
    }
}
void removeSong(string title) {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }
    if (head->title == title) {
        Song* temp = head;
        head = head->next;
        delete temp;
        return;
    }
}
void searchSong(string artist) {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }
    Song* current = head;
    while (current != nullptr) {
        if (current->artist == artist) {
            cout << current->title << " - " << current->artist << " - " << current->duration << endl;
        }
        current = current->next;
    }
}
void reversePlaylist() {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }
    Song* current = head;
    Song* prev = nullptr;
    Song* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void calculateTotalDuration() {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }
    Song* current = head;
    int totalDuration = 0;
    while (current != nullptr) {
        totalDuration += current->duration;
        current = current->next;
    }
    cout << "Total duration of playlist: " << totalDuration << " seconds" << endl;
}
void displayPlaylist() {
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }
    Song* current = head;
    while (current != nullptr) {
        cout << current->title << " - " << current->artist << " - " << current->duration << endl;
        current = current->next;
    }
}
int main() {
    addSong("Song1", "Artist1", 210);
    addSong("Song2", "Artist2", 180);
    addSong("Song3", "Artist1", 240);
    cout << "Playlist:" << endl;
    displayPlaylist();
    cout << endl;

    cout << "Searching for songs by Artist1:" << endl;
    searchSong("Artist1");
    cout << endl;

    cout << "Total duration of playlist:" << endl;
    calculateTotalDuration();
    cout << endl;

    cout << "Reversing playlist:" << endl;
    reversePlaylist();
    displayPlaylist();
    cout << endl;

    cout << "Removing Song2 from playlist:" << endl;
    removeSong("Song2");
    displayPlaylist();
    cout << endl;

    return 0;
}