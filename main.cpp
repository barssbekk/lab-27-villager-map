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
        cout << "Menu:\n" // main menu
             << "1. Add Villager\n"
             << "2. Delete Villager\n"
             << "3. Increase Friendship\n"
             << "4. Decrease Friendship\n"
             << "5. Search for Villager\n"
             << "6. Exit\n"
             << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 6) break; // exit

        switch (choice) {
            case 1: { // add a new villager
                string newName;
                string species;
                string phrase;
                int level = 0;

                cout << "Villager name: ";
                getline(cin, newName);

                cout << "Friendship level: ";
                cin >> level;
                cin.ignore();

                cout << "Species: ";
                getline(cin, species);

                cout << "Catchphrase: ";
                getline(cin, phrase);

                villagerData[newName] = make_tuple(level, species, phrase);
                cout << newName << " added.\n";
                break;
            }

            case 2: { // delete villager
                cout << "Enter villager name: ";
                getline(cin, name);

                if (villagerData.erase(name))
                    cout << name << " deleted.\n";
                else
                    cout << "Villager not found.\n";
                break;
            }

            case 3: { // ++friendship
                cout << "Enter villager name: ";
                getline(cin, name);

                auto it = villagerData.find(name);
                if (it == villagerData.end()) {
                    cout << "Villager not found.\n";
                    break;
                }

                get<0>(it->second)++;
                break;
            }

            case 4: { // --friendship
                cout << "Enter villager name: ";
                getline(cin, name);

                auto it = villagerData.find(name);
                if (it == villagerData.end()) {
                    cout << "Villager not found.\n";
                    break;
                }

                // prevent negative friendship
                int& friendship = get<0>(it->second);
                if (friendship > 0)
                    friendship--;
                break;
            }

            case 5: { // search by name
                cout << "Enter villager name: ";
                getline(cin, name);

                auto it = villagerData.find(name);
                if (it == villagerData.end()) {
                    cout << "Villager not found.\n";
                    break;
                }

                cout << "\nFound " << name << ": "
                     << "Friendship = " << get<0>(it->second) << ", "
                     << "Species = " << get<1>(it->second) << ", "
                     << "Catchphrase = " << get<2>(it->second) << '\n';
                break;
            }

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
    return 0;
}