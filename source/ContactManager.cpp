#include "../include/ContactManager.h"
#include "../include/Contact.h"
#include <iostream>
#include <mysql/mysql.h>
#include <fstream>
#include <vector>

// ContactManager::ContactManager()
// {
//     connection = mysql_init(nullptr);
//     if (!connection)
//     {
//         std::cout << "Mysql Connection Failed" << std::endl;
//         return;
//     }
// }

void ContactManager::addContact(const Contact& contact)
{
    for (std::size_t i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].getName() == contact.getName())
        {
            std::cout << "Contact with this name already exists.\n";
            return;
        }
    }
    contacts.push_back(contact);
}

bool ContactManager::removeContact(std::string& name)
{
    for (std::size_t i = 0;i<contacts.size();i++)
    {
        if (contacts[i].getName() == name )
        {
            contacts.erase(contacts.begin()+i);
            return true;
        }
    }
    return false;
}

void ContactManager::listall() const
{
    if (contacts.empty())
    {
        std::cout << "No contacts found.\n";
        return;
    }

    for (std::size_t i = 0; i < contacts.size(); i++)
    {
        std::cout << "\n[" << i + 1 << "] ";
        std::cout << "Name         : " << contacts[i].getName()  << '\n';
        std::cout << "    Phone Number : " << contacts[i].getPhone() << '\n';
        std::cout << "    Email        : " << contacts[i].getEmail() << '\n';
    }
    std::cout << "\nTotal contacts: " << contacts.size() << '\n';
}

void ContactManager::savetoFile(const std::string& file_name) const
{
    std::ofstream outlet(file_name);
    if (!outlet)
    {
        std::cout << "Error unable to open the file for writing "  << std::endl;
        return;
    }
    for (std::size_t i = 0;i<contacts.size();i++)
    {
        outlet << "Name         : " << contacts[i].getName() << '\n';
        outlet << "Phone Number : " << contacts[i].getPhone() << '\n';
        outlet << "Email        : " << contacts[i].getEmail() << '\n';
        outlet << "--------------------------------\n";
    }
    std::cout << "Data Successfullly Saved in the file - "<< file_name << std::endl;
}

void ContactManager::loadFromFile(const std::string& file_name)
{
    std::ifstream inFile(file_name);
    if (!inFile)
    {
        std::cout << "Couldn't open the file for reading" << std::endl;
        return;
    }
    contacts.clear();
    std::string name;
    std::string phone;
    std::string email;

    while (std::getline(inFile, name) &&
           std::getline(inFile, phone) &&
           std::getline(inFile, email))
    {
        Contact c(name, phone, email);
        contacts.push_back(c);
    }

    inFile.close();

}
