#include <iostream>
#include <vector>
using namespace std;


class HashNode {
    public:
        int key;
        int value;
        HashNode* next;
        int hash_index;

        // constructor
        HashNode(int key, int value, int hash_index) :
            key(key), value(value), next(nullptr), hash_index(hash_index) {}

};

class HashTable {
    private:
        int tableSize;
        vector<HashNode*> table;

        // hash function to map values to key
        int hash(int key) {
            return key % tableSize;
        }

    public:
        // constructor
        HashTable(int tableSize) : tableSize(tableSize) {
            table.resize(tableSize, nullptr);
        }

        // insert key-value pair
        void insert(int key, int value) {
            int hash_index = hash(key);

            HashNode* hash_node = new HashNode(key, value, hash_index);

            // if no collision
            if (table[hash_index] == nullptr) {
                table[hash_index] = hash_node;
            }

            // if collision
            else {
                HashNode* temp = table[hash_index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = hash_node;
            }
        }


        // search key-value pair
        HashNode* search(int key) {
            int hash_index = hash(key);

            // if key is present in hash table
            if (table[hash_index] != nullptr) {
                HashNode* temp = table[hash_index];
                while (temp != nullptr) {
                    if (temp->key == key) {
                        return temp;
                    }
                    temp = temp->next;
                }
            }

            // if key is not present in hash table
            return nullptr;
        }

        // remove key-value pair
        int remove(int key) {
            int hash_index = hash(key);

            // if collision - possibility of key being present
            if (table[hash_index] != nullptr) {
                HashNode* temp = table[hash_index];
                HashNode* prev = nullptr;

                while (temp != nullptr) {
                    if (temp->key == key) {
                        if (prev == nullptr)
                            table[hash_index] = temp->next;
                        else
                            prev->next = temp->next;

                        delete temp;
                        return 1;
                    }
                    prev = temp;
                    temp = temp->next;
                }
            }

            // if key is not present in hash table
            return -1;
        }
};


int main() {
    HashTable hash_table(5);

    hash_table.insert(1, 10);
    hash_table.insert(2, 20);
    hash_table.insert(3, 30);
    hash_table.insert(4, 40);
    hash_table.insert(5, 50);
    hash_table.insert(6, 60);
    hash_table.insert(7, 70);
    hash_table.insert(8, 80);
    hash_table.insert(9, 90);
    hash_table.insert(10, 100);
    hash_table.insert(11, 110);
    hash_table.insert(12, 120);


    // seaching for a key
    int key = 9;
    HashNode* hash_node = hash_table.search(key);
    if (hash_node != nullptr)
        cout << "Key: " << hash_node->key << ", Value: " << hash_node->value << " at Index: " << hash_node->hash_index << endl;
    else
        cout << "Key: " << key << " not found" << endl;

    // removing a key
    key = 5;
    int status = hash_table.remove(key);
    if (status == 1)
        cout << "Key: " << key << " removed successfully" << endl;
    else
        cout << "Key: " << key << " not found" << endl;
    
    // confirming if key is removed
    hash_node = hash_table.search(key);
    if (hash_node != nullptr)
        cout << "Key: " << hash_node->key << ", Value: " << hash_node->value << " at Index: " << hash_node->hash_index << endl;
    else
        cout << "Key: " << key << " not found" << endl;
    
    return 0;
}