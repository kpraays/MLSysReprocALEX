#include <iostream>
#include <string>
#include "stx/btree_map.h"

int main() {
    // Define the B-tree type
    using MyBTree = stx::btree_map<int, std::string>;

    // Create an instance of the B-tree
    MyBTree myBTree;

    // Insert some key-value pairs
    myBTree.insert({3, "Three"});
    myBTree.insert({1, "One"});
    myBTree.insert({4, "Four"});
    myBTree.insert({2, "Two"});

    // Print the contents of the B-tree
    std::cout << "B-tree contents:" << std::endl;
    for (const auto& pair : myBTree) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Perform a lookup
    int keyToFind = 2;
    auto it = myBTree.find(keyToFind);
    if (it != myBTree.end()) {
        std::cout << "Value for key " << keyToFind << ": " << it->second << std::endl;
    } else {
        std::cout << "Key " << keyToFind << " not found" << std::endl;
    }

    return 0;
}
