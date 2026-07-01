//
// Created by anilreddy on 30/06/26.
//

#ifndef CONTACT_MANAGER_CONTACTMANAGER_H
#define CONTACT_MANAGER_CONTACTMANAGER_H

#include "Contact.h"
#include <vector>
#include <mysql/mysql.h>
class ContactManager{

private:
    std::vector<Contact> contacts;
public:
    ContactManager() = default;
    void addContact(const Contact& contact);
    bool removeContact(std::string &name);
    void listall() const;
    void savetoFile(const std::string &file_name) const;
    void loadFromFile(const std::string &file_name) ;

};

#endif //CONTACT_MANAGER_CONTACTMANAGER_H
