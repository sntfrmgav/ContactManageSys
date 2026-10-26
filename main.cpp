//
//  main.cpp
//   Contacts Management System
//
//  Created by Gavin Q on 3/16/26.
//

#include <iostream>
using namespace std;
struct Contacts
{
    string name;
    int gender;
    int age;
    string phoneNum;
    string address;
};
struct AddressBook
{
    Contacts contactsArray[1000];
    int size;
};

void addContact(AddressBook * addb){
    
    if(addb -> size == 1000){
        cout << "The Address Book is Full.";
        return;
    }
    else{
        // assignments for name, gender age...........
        // 1. Name:
        
        string name;
        cout << "Name: " << endl;
        cin >> name;
        addb -> contactsArray[addb->size].name = name;
        
        // 2. Gender:
        cout << "Gender: " << endl;
        cout << "1 for Male, 2 for Female: " ;
        int gender = 0;
        
        
        while(true){
            cin >> gender;
            
            if(gender == 1 || gender == 2){
                addb -> contactsArray[addb->size].gender = gender;
                break;
            }
            cout << "Please try again..... ";
        }
            // 3. Age
        int age;
        cout << "Age: ";
        cin >> age;
        addb -> contactsArray[addb->size].age = age;

        
        cout << "Successfully added";
        addb -> size++;
    }
}

void displayContacts(AddressBook * addb){
    if (addb-> size == 0)
    {
        cout << "No Contacts Found";
    }
    else {
        for(int i = 0; i < addb->size; i++){
            cout << "Name: "<< addb->contactsArray[i].name <<"\t";
           // cout << "Gender: " << addb->contactsArray[i].gender;
            //( condition ? option1: option2)
            cout << "Gender: "<<(addb ->contactsArray[i].gender == 1 ? "Male": "Female")<<"\t";
            cout << "Age : " << addb ->contactsArray[i].age;
        }
    }
}
int isExists(AddressBook * addb, string name)
{
    for (int i = 0; i < addb->size; i++)
    {
        if (addb->contactsArray[i].name == name)
        {
            return i;
        }
    }
    return -1;

    
};

void deleteContact(AddressBook * addb)
{
    cout << "Enter the name of the contact to be deleted:  ";
    string name;
    cin >> name;
    
    int ret = isExists(addb, name);
    if (ret != -1){
        for(int i = ret; i < addb->size-1; i++)
        {
            addb-> contactsArray[i] = addb->contactsArray[i+1];
        }
        addb->size--;
        cout<<"Contact deleted successfully......"<< endl;
    }
    else{
        cout << "No Contact found...."<<endl;
    }
}
    
void searchContacts(AddressBook * addb){
    string name;
    cin >> name;
    int ret = isExists(addb, name);
    
    if (ret!=-1){
        cout << "Contact Found: "<< endl;
        cout << "Name: " << addb->contactsArray[ret].name << "\t";
               cout << "Gender: " << (addb->contactsArray[ret].gender == 1 ? "Male" : "Female") << "\t";
               cout << "Age: " << addb->contactsArray[ret].age << "\t";
               cout << "Phone: " << addb->contactsArray[ret].phoneNum << "\t";
               cout << "Address: " << addb->contactsArray[ret].address << endl;
           }
           else{
               cout << "No Contact found...." << endl;
           }
    }
    


void modifyContact(AddressBook * addb){
    
    cout << "Enter the name of the contact to be modified:  ";
    string name;
    cin >> name;
    int ret = isExists(addb, name);
    if (ret != -1){
        for(int i = ret; i < addb->size; i++)
        {
            string name;
            cout << "Name:  " << endl;
            cin >> name;
            addb -> contactsArray[i].name = name;
            
            // 2. Gender:
            cout << "Gender: " << endl;
            cout << "1 for Male, 2 for Female: " ;
            int gender = 0;
            while(true){
                cin >> gender;
                
                if(gender == 1 || gender == 2){
                    addb -> contactsArray[addb->size].gender = gender;
                    break;
                    //3. Age
                    int ages;
                    cout << "Age: ";
                    cin >> ages;
                    addb->contactsArray[ret].age = ages;
    
                    
                    //4. Phone Number
                string phone;
                    cout << "Phone Number: ";
                    cin >> phone;
                    addb->contactsArray[ret].phoneNum = phone;
    
                    
                    
                    
                    //5. Address
                    string address;
                           cout << "Address: ";
                           cin >> address;
                           addb->contactsArray[ret].address = address;
                    cout << "Contact modified successfully......" << endl;
                }
                else{
                    
                }
                cout << "Please try again..... ";
            }
        }
        cout<<"Contact modified successfully......"<< endl;
    }
    else{
        cout << "No Contact found...."<<endl;
    }
}
void cleanContacts (AddressBook * addb){
    int choices;
    cout << "Are you sure? Y/N? ";
    cin >> choices;
    if(choices == 'Y'||choices == 'y'){
        addb -> size=0;
        cout << "Contact Deleted....";
    }
    else{
        cout << "Operation cancelled....";
    }
}
    void showMenu(){
        cout << " ==== Contacts Management System ==== ";
        cout << "\n1. Add Contact ";
        cout << "\n2. Display Contacts ";
        cout << "\n3. Delete Contact";
        cout << "\n4. Search for a Contact";
        cout << "\n5. Modify Contact (by name)";
        cout << "\n6. Clear All Contacts";
        cout << "\n0. Exit";
        cout << " ===================================== ";
        
        cout << "\nEnter your choice: ";
    }
    int main()
    {
        //Create a Funtion to display the menu. Void showMenu()
        // Call the menu function in main().
        int select = 0;
        
        AddressBook addb;
        addb.size = 0;
        
        
        
        while(true){
            showMenu();
            cin >> select;
            
            // Will keep running as long as a input is entered that isnt 0.
            switch(select)
            {
                case 1:
                    addContact(&addb);
                    break;
                case 2:
                    displayContacts(&addb);
                    break;
                case 3:
                    deleteContact(&addb);
                    break;
                case 4:
                    searchContacts(&addb);
                    break;
                case 5:
                    modifyContact(&addb);
                    break;
                case 6:
                    cleanContacts(&addb);
                    break;
                case 0:
                {
                    char choice;
                    cout<< "Are you sure you want to exit program? (Yes/No)";
                    cin >> choice;
                    
                    if (choice == 'Y'|| choice == 'y'){
                        cout << "Exiting program...";
                        return 0;
                    }
                    break;
                    
                }
                    return 0;
                    break;
            }
        }
        
        return 0;
        
    }

