
#ifndef CONTACT_MANAGER_CONTACT_H
#define CONTACT_MANAGER_CONTACT_H
#include <string>

#include <array>
class Contact
{
private:
    std::string Name_;
    std::string PhoneNumber_;
    std::string Email_;
public:
    Contact(std::string Name,std::string P_No,std::string Email):Name_(Name),PhoneNumber_(P_No),Email_(Email){};
    std::string getName () const
    {
        return Name_;
    }
    std::string getPhone() const
    {
        return PhoneNumber_;
    }
    std::string getEmail() const
    {
        return Email_;
    }

};

#endif //CONTACT_MANAGER_CONTACT_H
