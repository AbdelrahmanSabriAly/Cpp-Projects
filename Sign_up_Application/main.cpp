#include <iostream>
#include <array>
#include <string>
#include <unordered_map>

// Constants
constexpr int MAX_SIZE = 100;  // Maximum size of the database
int USER_ID = 0;               // Global user ID counter

// Enum for menu options
enum class OPTIONS
{
    ADD_OPTION = 1,
    FETCH_OPTION = 2,
    QUIT_OPTION = 3
};

// Mapping options to their string representation
std::unordered_map<OPTIONS, std::string> OPTIONS_STRING_MAP{
    {OPTIONS::ADD_OPTION, "1: ADD RECORD"},
    {OPTIONS::FETCH_OPTION, "2: FETCH RECORD"},
    {OPTIONS::QUIT_OPTION, "3: QUIT"}};

// Class to represent a user
class USER
{
public:
    std::string USER_NAME;  // User's name
    int USER_AGE;           // User's age
};

// Database to store user records
std::array<USER, MAX_SIZE> DATABASE;

/**
 * @brief Overloaded output stream operator for OPTIONS enum
 * @param os: Output stream
 * @param data: OPTIONS enum value
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, OPTIONS data)
{
    os << OPTIONS_STRING_MAP.at(data);
    return os;
}

/**
 * @brief Overloaded input stream operator for OPTIONS enum
 * @param is: Input stream
 * @param data: OPTIONS enum value reference
 * @return std::istream&
 */
std::istream &operator>>(std::istream &is, OPTIONS &data)
{
    int input_data;
    is >> input_data;
    data = static_cast<OPTIONS>(input_data);
    return is;
}

/**
 * @brief Function to print the menu options
 */
void PRINT_OPTIONS(void)
{
    std::cout << "Select a choice:\n";
    std::cout << OPTIONS::ADD_OPTION << "\n";
    std::cout << OPTIONS::FETCH_OPTION << "\n";
    std::cout << OPTIONS::QUIT_OPTION << "\n";
    std::cout << "\nEntered choice: ";
}

/**
 * @brief Function to add a record to the database
 * @param name: User's name
 * @param age: User's age
 */
void ADD_RECORD(const std::string &name, int age)
{
    USER new_user;
    new_user.USER_NAME = name;
    new_user.USER_AGE = age;
    DATABASE[USER_ID++] = new_user;
}

/**
 * @brief Function to fetch a record by its ID
 * @param ID: User's ID
 */
void FETCH_RECORD(int ID)
{
    std::cout << "User name: " << DATABASE.at(ID).USER_NAME << "\n";
    std::cout << "User age: " << DATABASE.at(ID).USER_AGE << "\n";
}

/**
 * @brief Function to check if the entered ID is valid
 * @param ID: User's ID
 * @return true if the ID is valid, false otherwise
 */
bool CHECK_ENTERED_ID(int ID)
{
    if (ID < 0 || ID >= USER_ID)
    {
        std::cout << "Invalid ID, please try again with ID between 0 and " << USER_ID - 1 << "\n";
        return false;
    }
    return true;
}

/**
 * @brief Main function
 * @return int
 */
int main()
{
    constexpr OPTIONS DEFAULT_OPTION = OPTIONS::ADD_OPTION;
    bool LOOP_STATE = true;
    std::string Name;
    int Age, id;
    OPTIONS Entered_option = DEFAULT_OPTION;

    std::cout << "==================================================================================\n";
    std::cout << "\nUser Sign-up Application\n";
    while (LOOP_STATE)
    {
        PRINT_OPTIONS();
        std::cin >> Entered_option;

        switch (Entered_option)
        {
        case OPTIONS::ADD_OPTION:
            if (USER_ID == MAX_SIZE)
                std::cout << "DATABASE is full\n";
            else
            {
                std::cout<<"---------------------------------------------------------------------\n\n";
                std::cout << "Please enter user name and age\n";
                std::cout << "Name: ";
                std::cin >> Name;
                std::cout << "Age: ";
                std::cin >> Age;
                ADD_RECORD(Name, Age);
            }
            break;

        case OPTIONS::FETCH_OPTION:
            std::cout<<"---------------------------------------------------------------------\n\n";
            std::cout << "please Enter ID\n";
            std::cout << "ID: ";
            std::cin >> id;
            if (CHECK_ENTERED_ID(id))
                FETCH_RECORD(id);
            break;

        case OPTIONS::QUIT_OPTION:
            std::cout<<"---------------------------------------------------------------------\n\n";
            std::cout<<"EXITING....\n";
            LOOP_STATE = false;
            break;

        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }

        std::cout << "==================================================================================\n";
        std::cout << "==================================================================================\n";
    }

    std::cout << "==================================================================================\n";
    return 0;
}