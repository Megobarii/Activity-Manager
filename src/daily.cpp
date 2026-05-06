#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
//custom headers
#include "../include/utility.hpp"
#include "../include/add_menu.hpp"
#include "../include/complete_menu.hpp"
#include "../include/delete_task.hpp"

int main() {
    bool running = true;

    while (running) {
        // -------- MENU --------
        clear_screen();
        std::cout << "choose one of the following options: ";
        std::cout << "\n1)add today's activity";
        std::cout << "\n2)complete an activity";
        std::cout << "\n3)delete an activity";
        std::cout << "\n4)show activities";
        std::cout << "\n5)exit";

        std::string user_input;
        std::cout << "\nYour answer: ";

        // -------- GET INPUT --------
        std::getline(std::cin, user_input);
        user_input = normalize(user_input);

        // -------- CHECK INPUT --------
        while (
            user_input != "1" && user_input != "2" && user_input != "3" &&
            user_input != "4" && user_input != "5" &&
            user_input != "add" && user_input != "complete" &&
            user_input != "delete" && user_input != "show" &&
            user_input != "exit"
        ) {
            clear_screen();
            std::cout << "invalid answer...\n";
            std::cout << "choose one of the following options: ";
            std::cout << "\n1)add today's activity";
            std::cout << "\n2)complete an activity";
            std::cout << "\n3)delete an activity";
            std::cout << "\n4)show activities";
            std::cout << "\n5)exit";
            std::cout << "\nYour answer: ";

            std::getline(std::cin, user_input);
            user_input = normalize(user_input);
        }

        // -------- MENU ACTIONS --------
        if (user_input == "1" || user_input == "add") {
            add_menu();

        } else if (user_input == "2" || user_input == "complete") {
            try {
                complete_menu();
            } catch (const std::runtime_error& e) {
                std::cout << "there was an error: " << e.what() << std::endl;
            }

        } else if (user_input == "3" || user_input == "delete") {
            try {
                delete_task();
            } catch (const std::runtime_error& e) {
                std::cout << "there was an error: " << e.what() << std::endl;
            }

        } else if (user_input == "4" || user_input == "show") {
            show_tasks();

        } else {
            // exit
            running = false;
        }
    }

    return 0;
}
