#include<iostream>
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
        if (choice == 1)
        {
            std ::cout <<"Enter the Name : " ;
            std ::cout << std::endl;
            std::cout << "Enter the PhoneNumber :"
            std::string name, phonenumber , email;
            std::cin >> name;
        }
    }



}