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

    int choice = 0;
    string name = "";
    while (true) {
        cout << "Menu:\n"
             << "1. Increase Friendship\n"
             << "2. Decrease Friendship\n"
             << "3. Search for Villager\n"
             << "4. Exit\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 4) break; // exit
        cout << "Enter villager name: ";
        getline(cin, name);

        auto it = villagerData.find(name);
        if (it == villagerData.end()) {
            cout << "Villager not found.\n";
            continue;
        }

        switch (choice) {
            case 1:
                get<0>(it->second)++;
                break;

            case 2:
                if (get<0>(it->second) > 0)
                    get<0>(it->second)--;
                break;

            case 3:
                cout << "\nFound " << name << ": "
                     << "Friendship = " << get<0>(it->second) << ", "
                     << "Species = " << get<1>(it->second) << ", "
                     << "Catchphrase = " << get<2>(it->second) << '\n';
                break;

            default:
                cout << "Invalid choice, try again.\n";
        }
        cout << "\nVillager details:\n";
        for (const auto& pair : villagerData) {  // output
            cout << pair.first << " ["
                 << get<0>(pair.second) << ", "
                 << get<1>(pair.second) << ", "
                 << get<2>(pair.second) << "]\n";
        }
    }

    // access the map using a range-based for loop
    // cout << "Villagers (range-based for loop):" << endl;
    // for (const auto& pair : villagerData) {
    //     cout << pair.first << ": "
    //          << "Friendship = " << get<0>(pair.second) << ", "
    //          << "Species = " << get<1>(pair.second) << ", "
    //          << "Catchphrase = " << get<2>(pair.second) << '\n';
    // }
    //
    // // access the map using iterators
    // cout << "\nVillagers: (iterators)" << endl;
    // for (auto it = villagerData.begin(); it != villagerData.end(); ++it) {
    //     cout << it->first << ": "
    //          << "Friendship = " << get<0>(it->second) << ", "
    //          << "Species = " << get<1>(it->second) << ", "
    //          << "Catchphrase = " << get<2>(it->second) << '\n';
    // }
    //
    // // delete an element /
    // villagerData.erase("Raymond");
    //
    // // search for an element using .find() to avoid errors
    // string searchKey = "Audie";
    // auto it = villagerData.find(searchKey);
    // if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
    //     cout << "\nFound " << searchKey << ": "
    //          << "Friendship = " << get<0>(it->second) << ", "
    //          << "Species = " << get<1>(it->second) << ", "
    //          << "Catchphrase = " << get<2>(it->second) << '\n';
    // } else
    //     cout << endl << searchKey << " not found." << endl;
    //
    // // report size, clear, report size again to confirm map operations
    // cout << "\nSize before clear: " << villagerData.size() << endl;
    // villagerData.clear();
    // cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}