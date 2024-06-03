#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class ContactType {
    Friend,
    Acquaintance,
    Colleague
};

class Contact {
protected:
	string name;
public:
	Contact(const string& s);
    Contact();
	virtual ~Contact() = default;
	virtual ContactType getType() const = 0;
	string getName() const;
};

class Friend : public Contact {
private:
    string dob;
    string phone;
    string address;

public:
	Friend(const string& s, const string& d, const string& p, const string& a);
    ContactType getType() const override;
    string getDOB() const;
    string getPhone() const;
    string getAddress() const;
};

class Acquaintance : public Contact {
private:
    string phone;

public:
    Acquaintance(const string& s, const string& p);
    ContactType getType() const override;
    string getPhone() const;
};

class Colleague : public Contact {
private:
    string phone;
    string company;
    string address;

public:
    Colleague(const string& s, const string& p, const string& c, const string& a);
    ContactType getType() const override;
    string getPhone() const;
    string getCompany() const;
    string getAddress() const;
};

class AddressBook {
private:
    vector<Contact*> contacts;
public:
    ~AddressBook();
    void addContact(Contact* contact);
    Contact* searchByName(const string& name);
    vector<Friend*> getFriends();
    void deleteContact(const string& name);
};