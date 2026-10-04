#include <iostream>
#include <string>
using namespace std;

// Task 3: Inventory management system
// Store -> Sections -> Items (each level is a linked list)
struct Item    { string name; Item* next; };
struct Section { string name; Item* items; Section* next; };
struct Store   { string name; string city; Section* secs; Store* next; };
Store* stores = NULL;

// Add a new store
void addStore(string name, string city) {
    stores = new Store{name, city, NULL, stores};
}

// Find a store by name
Store* getStore(string s) {
    Store* t = stores;
    while (t && t->name != s) t = t->next;
    return t;
}

// Find a section of a given store
Section* getSec(string store, string sec) {
    Store* st = getStore(store);
    if (!st) return NULL;
    Section* t = st->secs;
    while (t && t->name != sec) t = t->next;
    return t;
}

// Add a new section in a store
void addSection(string store, string sec) {
    Store* st = getStore(store);
    if (st) st->secs = new Section{sec, NULL, st->secs};
    else cout << "Store not found" << endl;
}

// Store an item in a section of a store
void addItem(string store, string sec, string item) {
    Section* s = getSec(store, sec);
    if (s) s->items = new Item{item, s->items};
    else cout << "Store or section not found" << endl;
}

// Remove an item from a section of a store
void removeItem(string store, string sec, string item) {
    Section* s = getSec(store, sec);
    if (!s) { cout << "Store or section not found" << endl; return; }
    Item *prev = NULL, *t = s->items;
    while (t && t->name != item) { prev = t; t = t->next; }
    if (!t) { cout << "Item not found" << endl; return; }
    if (prev) prev->next = t->next; else s->items = t->next;
    delete t;
}

// Display all items of a section
void showSection(string store, string sec) {
    Section* s = getSec(store, sec);
    if (!s) { cout << "Store or section not found" << endl; return; }
    cout << sec << ": ";
    for (Item* i = s->items; i; i = i->next) cout << i->name << " ";
    cout << endl;
}

// Display all items of a store
void showStore(string store) {
    Store* st = getStore(store);
    if (!st) { cout << "Store not found" << endl; return; }
    cout << "Store " << st->name << " (" << st->city << "):" << endl;
    for (Section* s = st->secs; s; s = s->next) showSection(store, s->name);
}

int main() {
    addStore("StoreA", "Islamabad");
    addStore("StoreB", "Lahore");

    addSection("StoreA", "Toys");
    addSection("StoreA", "Grocery");
    addSection("StoreB", "Fruits");

    addItem("StoreA", "Toys", "Car");
    addItem("StoreA", "Toys", "Doll");
    addItem("StoreA", "Grocery", "Rice");
    addItem("StoreB", "Fruits", "Apple");

    cout << "Items of Toys in StoreA:" << endl;
    showSection("StoreA", "Toys");

    removeItem("StoreA", "Toys", "Car");
    cout << "After removing Car:" << endl;
    showSection("StoreA", "Toys");

    cout << "All items of StoreA:" << endl;
    showStore("StoreA");
    return 0;
}