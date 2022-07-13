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

#include "src/heavy_container.cpp"

// function prototypes
void start_menu();
void main_menu();
void sign_up();

int control_user_input(int);
void progress_bar();

/*
Handles receiving the username and password from the user.
return:
    - structure with the username and password
*/
auto log_in()
{
    struct user_data
    {
        std::string username{}, password{};
    };

    std::string username{}, password{};

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
    int start_choice{}, main_menu_choice{};
    std::fstream in_data("user_credentials.txt", std::ios::in);
    std::string f_username, f_password; // file data
    bool running{false};

    Heavy_container container(3000.0, 150.0, 5000, HEAVY);

    start_menu();
    std::cout << "Type the choice you wish to do: ";
    start_choice = control_user_input(start_choice);

    if (start_choice == 1)
    {
        sign_up();
        running = true;
    }

    else if (start_choice == 2)
    {
        auto [username, password] = log_in();
        in_data >> f_username >> f_password;

        if (username == f_username &&
            password == f_password)
            running = true;
    }

    else
    {
        std::cout << "Program Closed" << std::endl;
        return 0;
    }

    // main program
    while (running)
    {
        main_menu();
        std::cout << "Type the choice you wish to do: ";
        main_menu_choice = control_user_input(main_menu_choice);

        switch (main_menu_choice)
        {
        case 1:
            std::cout << container.show_container_data();

            break;

        case 8:
            std::cout << "Shutting down system. " << std::endl;
            std::cout << "Signing out. " << std::endl;

            sleep(1);
            progress_bar();
            sleep(0.25);

            std::cout << "\nExit Complete" << std::endl;
            running = false;
            break;

        default:
            break;
        } // end of switch
    }     // end of while loop
}

/*
Shows a simple menu with two options: Sign Up or Log In.
*/
void start_menu()
{
    std::cout << "Welcome to the Port's Management System."
              << "\nIf you already have an account, \"Log In\""
              << std::endl;
    std::cout << "1. Sign Up \n2. Log In \n3. Exit" << std::endl;
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
              << "\n8. Exit program " << std::endl;
}

void sign_up()
{
    std::fstream out_data("user_credentials.txt", std::ios::out);
    std::string username{}, password{}, email{}, position{}, pass_check{};
    int age{};

    std::cout << "Type your email: ";
    std::cin.ignore();
    std::getline(std::cin, email);

    std::cout << "Type your username: ";
    std::cin.ignore(-1);
    std::getline(std::cin, username);

    std::cout << "Type your age: ";
    age = control_user_input(age);

    std::cout << "Type your job position: ";
    std::cin.ignore();
    std::getline(std::cin, position);

    std::cout << "Type your password: ";
    std::cin.ignore(-1);
    std::getline(std::cin, password);

    std::cout << "Re-type your password: ";
    std::cin.ignore(-1);
    std::getline(std::cin, pass_check);

    while (password != pass_check)
    {
        std::cout << "Password's did not match. Try again" << std::endl;

        std::cout << "Type your password: ";
        std::cin.ignore(-1);
        std::getline(std::cin, password);

        std::cout << "Re-type your password: ";
        std::cin.ignore(-1);
        std::getline(std::cin, pass_check);
    }

    // saving data to file
    if (!out_data)
    {
        std::cout << "\nUnable to acces file." << std::endl;
    }
    else
    {
        out_data << username << std::endl
                 << password << std::endl
                 << "Email: " << email << std::endl
                 << "Age: " << age << std::endl
                 << "Position: " << position;

        out_data.close();
    }
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