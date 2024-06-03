#include "Contact.h"

int main() {
    AddressBook addressBook;

    addressBook.addContact(new Friend("Alex", "1.01.2000", "0751223332", "Strda Mare"));
    addressBook.addContact(new Acquaintance("Anderi", "0711222333"));
    addressBook.addContact(new Colleague("Maria", "0799888777", "Amazon", "Strada Mica"));

    Contact* Alex = addressBook.searchByName("Alex");
    if (Alex)
        cout << "Found Bob's contact: " << Alex->getName() << endl;
    else
        cout << "Bob not found in the address book." << endl;

    vector<Friend*> friends = addressBook.getFriends();
    cout << "Friends list:" << endl;
    for (auto& friend : friends) {
        cout << friend->getName() << endl;
    }

    addressBook.deleteContact("Charlie");
    cout << "Deleted Charlie's contact." << endl;

    return 0;
}