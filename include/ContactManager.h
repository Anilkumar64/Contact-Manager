//
// Created by anilreddy on 30/06/26.
//

#ifndef CONTACT_MANAGER_CONTACTMANAGER_H
#define CONTACT_MANAGER_CONTACTMANAGER_H
#include "Contact.h"

class ContactManager
{
private:
    vector<Contact> &contacts;
public:
    void addContact(const Contact& contact);
    void removeContact(const Contact &contact);
    void listall() const;
    void savetoFile(const std::string &file_name) const;
    void loadFromFile(const std::string &file_name) const;

};

#endif //CONTACT_MANAGER_CONTACTMANAGER_H
