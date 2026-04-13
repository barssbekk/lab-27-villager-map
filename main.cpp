// COMSC-210 | Lab 27 | Barsbek
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerData["Audie"] = make_tuple(5, "Dog", "Yuuu");
    villagerData["Raymond"] = make_tuple(8, "Bear", "Duu");
    villagerData.insert({"Marshal", make_tuple(9, "Cat", "Wuu")});

    // access the map using a range-based for loop
    cout << "Villagers (range-based for loop):" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": "
             << "Friendship = " << get<0>(pair.second) << ", "
             << "Species = " << get<1>(pair.second) << ", "
             << "Catchphrase = " << get<2>(pair.second) << '\n';
    }

    // access the map using iterators
    cout << "\nVillagers (iterators):" << endl;
    for (auto& it : villagerData) {
        cout << it.first << ": "
             << "Friendship = " << get<0>(it.second) << ", "
             << "Species = " << get<1>(it.second) << ", "
             << "Catchphrase = " << get<2>(it.second) << '\n';
    }

    // delete an element /
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    // string searchKey = "Audie";
    // auto it = villagerData.find(searchKey);
    // if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
    //                                    // if searchKey is not found
    //     cout << "\nFound " << searchKey << "'s favorite colors: ";
    //     for (auto color : it->second)  // range loop to traverse the value/vector
    //         cout << color << " ";
    //     cout << endl;
    // } else
    //     cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}