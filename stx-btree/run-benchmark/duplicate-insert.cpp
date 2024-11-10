#include <iostream>
#include "stx/btree_map.h"

int main() {
    using KeyType = int;
    using ValueType = std::string;

    // Instantiate the B-tree with duplicates allowed
    using MyBTree = stx::btree<KeyType, ValueType, std::pair<KeyType, ValueType>, std::less<KeyType>, stx::btree_default_map_traits<KeyType, ValueType>, true>;

    // Create an instance of the B-tree
    MyBTree myBTree;

    // Insert key-value pairs with duplicate keys allowed
    myBTree.insert({1, "One"});
    myBTree.insert({2, "Two"});
    myBTree.insert({2, "Duplicate Two"});
    myBTree.insert({3, "Three"});
    myBTree.insert({3, "Another Three"});

    // Print the contents of the B-tree
    std::cout << "B-tree contents:" << std::endl;
    for (const auto& pair : myBTree) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
