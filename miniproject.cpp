#include <iostream>
#include <string>

using namespace std;

struct Contact
{
    string name;
    string phone;
};

void addContact(Contact *&contacts, int &size, int &capacity);
void deleteContact(Contact *&contacts, int &size);
void searchContact(Contact *contacts, int size);
void displayContacts(Contact *contacts, int size);

int main()
{
    int size = 0;
    int capacity = 2;
    Contact *contactList = new Contact[capacity];
    int choice;

    do
    {
        cout << "\nContact List Application" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Display All Contacts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addContact(contactList, size, capacity);
            break;
        case 2:
            deleteContact(contactList, size);
            break;
        case 3:
            searchContact(contactList, size);
            break;
        case 4:
            displayContacts(contactList, size);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    delete[] contactList;
    return 0;
}

void addContact(Contact *&contacts, int &size, int &capacity)
{
    if (size == capacity)
    {
        capacity *= 2;
        Contact *newContacts = new Contact[capacity];
        for (int i = 0; i < size; i++)
        {
            newContacts[i] = contacts[i];
        }
        delete[] contacts;
        contacts = newContacts;
    }

    cout << "Enter name: ";
    cin >> contacts[size].name;
    cout << "Enter phone: ";
    cin >> contacts[size].phone;
    size++;
    cout << "Contact added successfully!" << endl;
}

void deleteContact(Contact *&contacts, int &size)
{
    if (size == 0)
    {
        cout << "Contact list is empty!" << endl;
        return;
    }

    string name;
    cout << "Enter the name of the contact to delete: ";
    cin >> name;

    for (int i = 0; i < size; i++)
    {
        if (contacts[i].name == name)
        {
            for (int j = i; j < size - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }
            size--;
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

void searchContact(Contact *contacts, int size)
{
    if (size == 0)
    {
        cout << "Contact list is empty!" << endl;
        return;
    }
    
    string name;
    cout << "Enter the name of the contact to search: ";
    cin >> name;
    
    for (int i = 0; i < size; i++)
    {
        if (contacts[i].name == name)
        {
            cout << "Contact found:" << endl;
            cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

void displayContacts(Contact *contacts, int size)
{
    if (size == 0)
    {
        cout << "Contact list is empty!" << endl;
        return;
    }
    
    cout << "All Contacts:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << endl;
    }
}