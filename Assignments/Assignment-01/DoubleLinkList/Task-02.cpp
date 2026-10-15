#include <iostream>
#include <string>
using namespace std;

struct DNode { string data; DNode *prev, *next; };

// Helper: returns the last node
DNode* tailOf(DNode* h) {
    while (h->next) h = h->next;
    return h;
}

// Helper: prints the list forward
void showD(DNode* h) {
    for (; h; h = h->next) cout << h->data << " ";
    cout << endl;
}

// Task 2: music playlist (navigate forward and backward)

// Add a song at the end of the playlist
void addSong(DNode*& h, string name) {
    DNode* t = new DNode{name, NULL, NULL};
    if (!h) { h = t; return; }
    DNode* last = tailOf(h);
    last->next = t;
    t->prev = last;
}

// Move to next song
DNode* playNext(DNode* cur) {
    if (cur->next) return cur->next;
    return cur;                              // already last song
}

// Move to previous song
DNode* playPrev(DNode* cur) {
    if (cur->prev) return cur->prev;
    return cur;                              // already first song
}

// Display playlist from last song to first song
void showBackward(DNode* h) {
    for (DNode* t = tailOf(h); t; t = t->prev) cout << t->data << " ";
    cout << endl;
}

// Remove a song by name
void removeSong(DNode*& h, string name) {
    DNode* t = h;
    while (t && t->data != name) t = t->next;
    if (!t) { cout << "Song not found" << endl; return; }
    if (t->prev) t->prev->next = t->next; else h = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

int main() {
    DNode* pl = NULL;
    addSong(pl, "Song1");
    addSong(pl, "Song2");
    addSong(pl, "Song3");
    cout << "Forward: "; showD(pl);
    cout << "Backward: "; showBackward(pl);

    DNode* playing = pl;
    cout << "Now playing: " << playing->data << endl;
    playing = playNext(playing);
    cout << "Next song: " << playing->data << endl;
    playing = playPrev(playing);
    cout << "Previous song: " << playing->data << endl;

    removeSong(pl, "Song2");
    cout << "After removing Song2: "; showD(pl);
    return 0;
}