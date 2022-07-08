#ifdef _WIN32
#define NOMINMAX
#include "Windows.h" // sleep() function
#else
#include "unistd.h" // sleep() function
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <string_view>
#include <optional>

// function prototypes
void start_menu();
void main_menu();
void sign_up();
void access_main(std::string_view, std::string_view,
                 std::optional<std::string_view> f_username = "",
                 std::optional<std::string_view> f_password = "");
int control_user_input(int);
void instructions();
void progress_bar();

/*
Handles receiving the username and password from the user.
return:
    - structure with the username and password
*/
auto log_in()
{
    std::string username, password;

    struct user_data
    {
        std::string username, password;
    };

    std::cout << "Type your username: ";
    std::cin.ignore();
    std::getline(std::cin, username);

    std::cout << "Type your password: ";
    std::cin.ignore(-1);
    std::getline(std::cin, password);

    return user_data{username, password};
}

int main()
{
    int menu_choice{}, main_menu_choice{};
    std::fstream in_data("user_credentials.txt", std::ios::in);
    std::string f_username, f_password; // file data
}

/*
Shows a simple menu with two options: Sign Up or Log In.
*/
void start_menu()
{
    std::cout << "\nWelcome to the Port Management System"
              << std::endl;
    std::cout << "1. PROGRAM INSTRUCTIONS Up \n2. Sign Up "
              << "\n3. Log In \n4. Exit" << std::endl;
}

/*
Shows the main menu of the application.
*/
void main_menu()
{
    std::cout << "\nMAIN MENU" << std::endl;
    std::cout << "1. Container Types \n2. Ship Types"
              << "\n3. Port Types \n4. Load Container to Ship"
              << "\n5. Unload Container from Ship"
              << "\n6. Sail to new Port \n7. Refuel Ship"
              << "\n8.Exit program " << std::endl;
}

void sign_up()
{
    std::fstream out_data;
    std::string username, password;
    int age;

    out_data.open("user_credentials.txt", std::ios::out);

    if (!out_data)
        std::cout << "File not found or created." << std::endl;
    else
    {
        std::cout << "Type your username: ";
        std::cin.ignore();
        std::getline(std::cin, username);

        std::cout << "Type your age: ";
        std::cin >> age;

        std::cout << "Type your password: ";
        std::cin.ignore();
        std::getline(std::cin, password);

        // writing data into the file
        out_data << username << std::endl
                 << password << std::endl
                 << age;
    }
}

void access_main(std::string_view username,
                 std::string_view password,
                 std::optional<std::string_view> f_username,
                 std::optional<std::string_view> f_password)
{
}

/*
Controls what the user types. Used in menu() and main_menu()
user prompts.
*/
int control_user_input(int choice)
{
    while (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');

        std::cout << "Invalid Entry. Try again: ";
    }

    return choice;
}

/*
Shows the program instructions to the user.
*/
void instructions()
{
    std::cout << "\nProgram instructions." << std::endl;
    std::cout << "If it is your first time with the program, please"
              << " choose \"Sign Up\" first and then \"Log In\" in "
              << "order to access all the programs functionality."
              << "If it's not your first time, your credentials are "
              << "already saved up, so please \"Log In\"."
              << std::endl;
}

/*
Creates a progress bar as a visual indicator to the user. Based on
How to display a progress indicator in pure C/C++
(cout/printf)? (2013, January 26). Stack Overflow.
https://stackoverflow.com/questions/14539867/how-to-display-a-progress-indicator-in-pure-c-c-cout-printf
*/
void progress_bar()
{
    float progress = 0.0;

    while (progress <= 1.0)
    {
        int bar_width = 70;
        std::cout << "[";

        int pos = bar_width * progress;

        for (int i = 0; i < bar_width; ++i)
        {
            if (i < pos)
                std::cout << "-";
            else
                std::cout << " ";
        }

        std::cout << "]" << static_cast<int>(progress * 100.0)
                  << "%\r";
        std::cout.flush();

        progress += 0.5;
    }
}