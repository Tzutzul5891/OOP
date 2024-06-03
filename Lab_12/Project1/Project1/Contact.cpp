#include "Contact.h"

Contact::Contact(const string& s) {
	this->name = s;
}

string Contact::getName() const {
	return name;
}

Friend::Friend(const string& s, const string& d, const string& p, const string& a) {
	this->name = s;
	this->dob = d;
	this->address = a;
	this->phone = p;
}



string Friend::getDOB() const {
	return this->dob;
}

string Friend::getPhone() const {
	return this->phone;
}

string Friend::getAddress() const {
	return this->address;
}

Acquaintance::Acquaintance(const string& s, const string& p) {
	this->name = s;
	this->phone = p;
}

ContactType Acquaintance::getType() const {
	return ContactType::Acquaintance;
}

string Acquaintance::getPhone() const {
	return this->phone;
}

Colleague::Colleague(const string& s, const string& p, const string& c, const string& a) {
	this->name = s;
	this->phone = p;
	this->company = c;
	this->address = a;
}

ContactType Colleague::getType() const {
	return ContactType::Colleague;
}

string Colleague::getPhone() const {
	return this->phone;
}

string Colleague::getCompany() const {
	return this->company;
}

string Colleague::getAddress() const {
	return this->address;
}

AddressBook::~AddressBook() {
	for (auto& contact : contacts)
		delete contact;
}

void AddressBook::addContact(Contact* contact) {
	contacts.push_back(contact);
}

Contact* AddressBook::searchByName(const string& s) {
	for (auto& contact : contacts) {
		if (contact->getName() == s)
			return contact;
	}
	return nullptr;
}

vector<Friend*> AddressBook::getFriends() {
	std::vector<Friend*> friends;
	for (auto& contact : contacts) {
		if (contact->getType() == ContactType::Friend)
			friends.push_back(static_cast<Friend*>(contact));
	}
	return friends;
}

void AddressBook::deleteContact(const std::string& s) {
	for (auto it = contacts.begin(); it != contacts.end(); ++it) {
		if ((*it)->getName() == s) {
			delete* it;
			contacts.erase(it);
			break;
		}
	}
}