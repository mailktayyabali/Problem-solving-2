#include <iostream>
using namespace std;

const int MAX_POSTS = 100;

// Represents a single post
struct Post {
    int id;
    char content[100];
    bool pinned;
};

// NewsFeed class using ONLY arrays
class NewsFeed {
private:
    Post posts[MAX_POSTS];
    int size;

public:
    NewsFeed() {
        size = 0;
    }

    // Add new post at beginning
    void addPost(int id, const char content[], bool pinned = false) {
        if (size >= MAX_POSTS) {
            cout << "Feed is full.\n";
            return;
        }

        // Shift posts to the right
        for (int i = size; i > 0; i--) {
            posts[i] = posts[i - 1];
        }

        // Insert new post at index 0
        posts[0].id = id;
        posts[0].pinned = pinned;

        int i = 0;
        while (content[i] != '\0') {
            posts[0].content[i] = content[i];
            i++;
        }
        posts[0].content[i] = '\0';

        size++;

        reorderPinnedPosts();
    }

    // Remove post by ID
    void removePost(int id) {
        int index = -1;

        // Find post index
        for (int i = 0; i < size; i++) {
            if (posts[i].id == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Post not found.\n";
            return;
        }

        // Shift left to delete
        for (int i = index; i < size - 1; i++) {
            posts[i] = posts[i + 1];
        }
        size--;
    }

    // Pin a post (move to top section)
    void pinPost(int id) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (posts[i].id == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Post not found.\n";
            return;
        }

        posts[index].pinned = true;
        reorderPinnedPosts();
    }

    // Ensures pinned posts stay at top
    void reorderPinnedPosts() {
        // Simple stable partition using array
        Post temp[MAX_POSTS];
        int tempIndex = 0;

        // First copy pinned
        for (int i = 0; i < size; i++) {
            if (posts[i].pinned) {
                temp[tempIndex++] = posts[i];
            }
        }

        // Then copy non-pinned
        for (int i = 0; i < size; i++) {
            if (!posts[i].pinned) {
                temp[tempIndex++] = posts[i];
            }
        }

        // Move back to original array
        for (int i = 0; i < size; i++) {
            posts[i] = temp[i];
        }
    }

    // Infinite scroll loader (loads n posts at a time)
    void loadMore(int count) {
        cout << "Loading next " << count << " posts:\n";

        for (int i = 0; i < count && i < size; i++) {
            cout << "Post ID: " << posts[i].id
                 << (posts[i].pinned ? " (PINNED)" : "") << "\n";
            cout << "Content: " << posts[i].content << "\n\n";
        }
    }

    // Display full feed
    void displayFeed() {
        cout << "\n--- FULL NEWS FEED ---\n";
        for (int i = 0; i < size; i++) {
            cout << "Post ID: " << posts[i].id
                 << (posts[i].pinned ? " (PINNED)" : "") << "\n";
            cout << "Content: " << posts[i].content << "\n\n";
        }
    }
};

int main() {
    NewsFeed feed;

    feed.addPost(1, "Hello World!");
    feed.addPost(2, "Second Post!");
    feed.addPost(3, "Breaking News!");
    feed.pinPost(2);

    feed.displayFeed();

    cout << "\nRemoving Post ID 1...\n";
    feed.removePost(1);

    feed.displayFeed();

    cout << "\nInfinite Scroll Load (2 posts):\n";
    feed.loadMore(2);

    return 0;
}
