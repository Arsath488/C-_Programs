#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache {
public:
    // Constructor to initialize capacity and pointers
    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }

    // Move a node to the front (Most Recently Used)
    void moveToHead(Node* node) {
        if (node == head) return;
        
        // Detach from current position
        if (node == tail) {
            tail = tail->prev;
            if (tail) tail->next = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        
        // Insert at head
        node->next = head;
        node->prev = NULL;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = head;
    }

    void set(int k, int v) override {
        // Case 1: Key already exists - update value and move to head
        if (mp.find(k) != mp.end()) {
            mp[k]->value = v;
            moveToHead(mp[k]);
        } 
        // Case 2: New key
        else {
            Node* newNode = new Node(k, v);
            
            // Insert at head
            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            mp[k] = newNode;

            // Evict the tail if over capacity
            if (mp.size() > cp) {
                mp.erase(tail->key);
                Node* temp = tail;
                tail = tail->prev;
                if (tail) tail->next = NULL;
                delete temp;
            }
        }
    }

    int get(int k) override {
        if (mp.find(k) != mp.end()) {
            moveToHead(mp[k]); // Mark as recently used
            return mp[k]->value;
        }
        return -1; // Cache miss
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
