#include<iostream>
#include <string>
#include "include/Contact.h"
#include "include/ContactManager.h"
int main()
{
    ContactManager manager;
    int choice{0};
    while (choice !=6)
    {
        std::cout << "\n--- Contact Manager ---\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Remove Contact\n";
        std::cout << "3. List All Contacts\n";
        std::cout << "4. Save to File\n";
        std::cout << "5. Load from File\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1)
        {
            std ::string name ,email, phonenumber;
            std::cout << "Adding the Contact " << std::endl;
            std::cout << "Enter the name : ";
            std::getline(std::cin, name);
            std::cout << "Enter the email : ";
            std::getline(std::cin, email);
            std::cout << "Enter Phone number : ";
            std::getline(std::cin, phonenumber);
            Contact ct(name , phonenumber,email);
            manager.addContact(ct);
            std::cout << "Contact Added Successfullly" << std::endl;
        }

        else if (choice == 2)
        {
            std::string name;
            std::cout << "Enter the name to remove contact : ";
            std::getline(std::cin, name);

            if (manager.removeContact(name))
                std::cout  << "contact removed successfully " << std::endl;
            else
                std::cout << "contact not found"  << std::endl;
        }
        else if (choice == 3)
        {
            manager.listall();
        }
        else if (choice == 4)
        {
            std::string filename;
            std::cout << "Enter the file name to save all the data :";
            std::getline(std::cin,filename);
            manager.savetoFile(filename);
        }
        else if (choice == 5)
        {
            std::string filename;
            std::cout << "Enter the file name to  load the data :";
            std::getline(std::cin,filename);
            manager.loadFromFile(filename);
        }
        else if (choice == 6)
        {
            std::cout << "Goodbye!\n";
        }
        else
        {
            std::cout << "Invalid choice, please enter 1-6\n";
        }
    }




}