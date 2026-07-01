#include "../include/ContactManager.h"
#include "../include/Contact.h"
#include <iostream>
#include <fstream>
#include <vector>
void ContactManager::addContact(const Contact& contact)
{
    contacts.push_back(contact);
}

bool ContactManager::removeContact(std::string name)
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
    for (std::size_t i = 0;i<contacts.size();i++)
    {
        std::cout << "Name         : " << contacts[i].getName() << std::endl;
        std::cout << "Phone Number : " << contacts[i].getPhone() << std::endl;
        std::cout << "Email        : " << contacts[i].getEmail() <<  std::endl;
     }
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
}

void ContactManager::loadFromFile(const std::string& file_name)
{
    std::ifstream inFile(file_name);
    if (!inFile)
    {
        std::cout << "Couldn't open the file for reading" << std::endl;
        return;
    }
    contacts.clear();std::string name;
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
