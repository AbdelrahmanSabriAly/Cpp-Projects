# Signup Application

## Overview

The Signup Application is a simple console-based program written in C++ that allows users to add and fetch records from a database. The application provides a menu for the user to either add new user records, fetch existing records by their ID, or quit the application.

## Features

- *Add Record*: Allows the user to add a new record by entering a user's name and age.
- *Fetch Record*: Enables the user to retrieve a record by providing the user's ID.
- *Quit*: Exits the application.

## Usage

### Menu Options

When you run the application, you will be presented with the following menu options:

1. ADD RECORD: Add a new user record.
2. FETCH RECORD: Fetch an existing user record by ID.
3. QUIT: Exit the application.

### Adding a Record

To add a record, select option 1 from the menu and then enter the user's name and age when prompted. The record will be stored in the database with a unique ID.

### Fetching a Record

To fetch a record, select option 2 from the menu and then enter the user's ID. If the ID is valid, the application will display the user's name and age.

### Exiting the Application

To exit the application, select option 3 from the menu.

## Code Structure

### Constants

- MAX_SIZE: Maximum number of records the database can hold.
- USER_ID: Global counter for user IDs.

### Enums

- OPTIONS: Enum for menu options (ADD, FETCH, QUIT).

### Classes

- USER: Class to represent a user with a USER_NAME and USER_AGE.

### Functions

- PRINT_OPTIONS(): Prints the menu options.
- ADD_RECORD(const std::string &name, int age): Adds a new record to the database.
- FETCH_RECORD(int ID): Fetches a record by its ID.
- CHECK_ENTERED_ID(int ID): Checks if the entered ID is valid.

### Main Function

The main() function contains the main loop of the application, which continuously prompts the user to select a menu option until the user chooses to quit.

## Compilation and Execution

To compile the program, use a C++ compiler such as g++:

sh
g++ -o main.cpp signup_application.cpp


To run the compiled program:

sh
./signup_application


## Example Interaction


==================================================================================
User Sign-up Application
Select a choice:
1: ADD RECORD
2: FETCH RECORD
3: QUIT

Entered choice: 1
---------------------------------------------------------------------
Please enter user name and age
Name: John
Age: 30
==================================================================================
==================================================================================
Select a choice:
1: ADD RECORD
2: FETCH RECORD
3: QUIT

Entered choice: 2
---------------------------------------------------------------------
please Enter ID
ID: 0
User name: John
User age: 30
==================================================================================
==================================================================================
Select a choice:
1: ADD RECORD
2: FETCH RECORD
3: QUIT

Entered choice: 3
---------------------------------------------------------------------
EXITING....
==================================================================================


## Limitations

- The database size is fixed at 100 records.
- No validation for user input (e.g., non-integer age values).
- No error handling for invalid menu options beyond simple re-prompting.