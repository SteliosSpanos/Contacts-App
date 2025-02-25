#include <iostream>
#include <fstream>
#include <string>
#include <map>

class PhoneBook{
private:
    std::map<std::string, std::string> Contacts;
public:
    PhoneBook() : Contacts() {}
    void addContact(const std::string& name, const std::string& number){
        Contacts.insert(std::pair<std::string, std::string>(name, number));
        std::cout << "Contact Added Successfully!" << std::endl;
    }
    void searchContact(const std::string& name) const{
        auto contact = Contacts.find(name);
        if (contact != Contacts.end()){
            std::cout << "Contact Found" << std::endl;
            std::cout << contact->first << " - " << contact->second << std::endl;
        }
        else{
            std::cout << "Contact Not Found" << std::endl;
        }
    }
    void displayContacts() const{
        for (const auto& pair : Contacts){
            std::cout << pair.first << " - " << pair.second << std::endl;
        }
    }
    void deleteContact(const std::string& name){
        auto contact = Contacts.find(name);
        if (contact != Contacts.end()){
            std::cout << "Contact Deleted" << std::endl;
            Contacts.erase(contact->first);
        }
        else{
            std::cout << "Contact Not Found" << std::endl;
        }
    }
    void saveToFile(const std::string& filename) const{
        std::ofstream file(filename);
        if (!file){
            std::cerr << "Couldn't Open File" << std::endl;
            return;
        }
        for (const auto& pair : Contacts){
            file << pair.first << " " << pair.second << std::endl;
        }
        file.close();
        std::cout << "Contacts Saved" << std::endl;
    }
    void loadFromFile(const std::string& filename){
        std::ifstream file(filename);
        if (!file){
            std::cerr << "Couldn't Open File" << std::endl;
            return;
        }
        std::string name, number;
        while (file >> name >> number){
            Contacts[name] = number;
        }
        file.close();
        std::cout << "Contacts Loaded" << std::endl;
    }
    void updateNumber(const std::string& name, const std::string& new_number){
        std::cout << "Previous Number: " << Contacts[name] << std::endl;
        Contacts[name] = new_number;
        std::cout << "Updated Number: " << Contacts[name] << std::endl;
    }
};

int main()
{
    PhoneBook phonebook;
    int choice;
    std::cout << "******************************************" << std::endl;
    std::cout << "CONTACTS APPLICATION" << std::endl;
    std::cout << "******************************************" << std::endl;
    while(true){
        std::cout << "1 - Add New Contact" << std::endl;
        std::cout << "2 - Search Contact by Name" << std::endl;
        std::cout << "3 - Delete Contact" << std::endl;
        std::cout << "4 - Update Contact" << std::endl;
        std::cout << "5 - Load Contacts from File" << std::endl;
        std::cout << "6 - Display Contacts" << std::endl;
        std::cout << "7 - Save to File before Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        if(choice == 1){
            std::string name, number;
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Number: ";
            std::getline(std::cin, number);
            phonebook.addContact(name, number);
        }
        else if(choice == 2){
            std::string name;
            std::cout << "Enter Name you want to Search: ";
            std::getline(std::cin, name);
            phonebook.searchContact(name);
        }
        else if(choice == 3){
            std::string name;
            std::cout << "Enter Name you want to Delete: ";
            std::getline(std::cin, name);
            phonebook.deleteContact(name);
        }
        else if(choice == 4){
            std::string name, number;
            std::cout << "Enter Name of Contact: ";
            std::getline(std::cin, name);
            std::cout << "Enter Updated Number: ";
            std::getline(std::cin, number);
            phonebook.updateNumber(name, number);
        }
        else if(choice == 5){
            std::string filename;
            std::cout << "Enter the Name of the File: ";
            std::getline(std::cin, filename);
            phonebook.loadFromFile(filename);
        }
        else if(choice == 6){
            phonebook.displayContacts();
        }
        else if(choice == 7){
            std::string filename;
            std::cout << "Enter the Name of the File: ";
            std::getline(std::cin, filename);
            phonebook.saveToFile(filename);
            break;
        }
        else{
            std::cout << "Invalid Choice. Please Try Again" << std::endl;
        }
    }
    return 0;
}