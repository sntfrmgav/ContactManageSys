# Contact Management System

A command-line contact management application written in C++.

## Features
- Add contacts with name, gender, and age
- Display all stored contacts
- Search for a contact by name
- Modify an existing contact's details
- Delete a single contact
- Clear all contacts

## Design
- Contacts are stored using a `Contacts` struct and organized in an `AddressBook` struct backed by a fixed-size array.
- Core operations (add, search, delete, modify, display) are implemented as standalone functions operating on an `AddressBook` pointer, following OOP-style organization of data and behavior.
- Input validation is used for fields like gender selection.

## Build & Run
```bash
g++ -o contacts main.cpp
./contacts
```

## Usage
Run the program and choose an option from the menu:
```
==== Contacts Management System ====
1. Add Contact
2. Display Contacts
3. Delete Contact
4. Search for a Contact
5. Modify Contact (by name)
6. Clear All Contacts
0. Exit
```

## Author
Gavin Quinn
