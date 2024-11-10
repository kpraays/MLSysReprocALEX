#include <iostream>
#include <string>
#include "stx/btree_map.h"
#include <random>

// the data type for values in key-value pair is chosen as int.
#define KEY_TYPE int
#define PAYLOAD_TYPE int

int main(int, char**) {
    // Create some synthetic data: keys are dense integers between 0 and 99, and
    // payloads are random values
    const int num_keys = 100;
    std::pair<KEY_TYPE, PAYLOAD_TYPE> values[num_keys];
    std::mt19937_64 gen(std::random_device{}());
    std::uniform_int_distribution<PAYLOAD_TYPE> dis;
    for (int i = 0; i < num_keys; i++) {
        values[i].first = i;
        values[i].second = dis(gen);
    }

    // Instantiate the B-tree with duplicates allowed
    // Directly use the btree template instead of special multi-map.
    using MyBTree = stx::btree<KEY_TYPE, PAYLOAD_TYPE, std::pair<KEY_TYPE, PAYLOAD_TYPE>, std::less<KEY_TYPE>, stx::btree_default_map_traits<KEY_TYPE, PAYLOAD_TYPE>, true>;

    // Create an instance of the B-tree
    MyBTree myBTree;

    // Bulk load the keys [0, 100)
    // when bulk loading, give the pointer to the location of the values array
    // and ending till one element past the last one.
    myBTree.bulk_load(values, values + num_keys);

    // Insert the keys [100, 200). Now there are 200 keys.
    for (int i = num_keys; i < 2 * num_keys; i++) {
        KEY_TYPE new_key = i;
        PAYLOAD_TYPE new_payload = dis(gen);
        //used btree with duplicates enabled so insert handles it accordingly.
        myBTree.insert(new_key, new_payload);
    }

    // Erase the keys [0, 10). Now there are 190 keys.
    for (int i = 0; i < 10; i++) {
        myBTree.erase(i);
    }

    // Iterate through all entries in the index and update their payload if the
    // key is even
    int num_entries = 0;
    for (auto it = myBTree.begin(); it != myBTree.end(); it++) {
        // access items through key() and data() calls
        if (it.key() % 2 == 0) {  // it.key() is equivalent to (*it).first
        it.data() = dis(gen);
        }
        num_entries++;
    }
    if (num_entries != 190) {
        std::cout << "Error! There should be 190 entries in the index."
                << std::endl;
    }


    // Iterate through all entries with keys between 50 (inclusive) and 100
    // (exclusive)
    num_entries = 0;
    // Search the B+ tree and return an iterator to the first pair
    // equal to or greater than key, or end() if all keys are smaller.
    for (auto it = myBTree.lower_bound(50); it != myBTree.lower_bound(100); it++) {
        num_entries++;
    }
    if (num_entries != 50) {
        std::cout
            << "Error! There should be 50 entries with keys in the range [50, 100)."
            << std::endl;
    }    

    // Equivalent way of iterating through all entries with keys between 50
    // (inclusive) and 100 (exclusive)
    num_entries = 0;
    auto it = myBTree.lower_bound(50);
    while (it.key() < 100 && it != myBTree.end()) {
        num_entries++;
        it++;
    }
    if (num_entries != 50) {
        std::cout
            << "Error! There should be 50 entries with keys in the range [50, 100)."
            << std::endl;
    }


    // Insert 9 more keys with value 42. Now there are 199 keys.
    // duplicates allowed so this test passes.
    for (int i = 0; i < 9; i++) {
        KEY_TYPE new_key = 42;
        PAYLOAD_TYPE new_payload = dis(gen);
        myBTree.insert(new_key, new_payload);
    }

    // Iterate through all 10 entries with keys of value 42
    int num_duplicates = 0;
    for (auto it = myBTree.lower_bound(42); it != myBTree.upper_bound(42); it++) {
        num_duplicates++;
    }
    if (num_duplicates != 10) {
       std::cout << "Error! There should be 10 entries with key of value 42, but found "
                << num_duplicates << " entries." << std::endl;
    }

    // Check if a non-existent key exists
    it = myBTree.find(1337);
    if (it != myBTree.end()) {
        std::cout << "Error! Key with value 1337 should not exist." << std::endl;
    }


    // Look at some stats
    auto stats = myBTree.get_stats();
    // source structure - btree class --> tree_stats structure
    std::cout << "Number of items in the B+ tree: " << stats.itemcount
                << std::endl;  // expected: 199
    std::cout << "Number of leaves in the B+ tree: " << stats.leaves
                << std::endl;
    std::cout << "Number of inner nodes in the B+ tree: " <<stats.innernodes
                << std::endl;     

}
