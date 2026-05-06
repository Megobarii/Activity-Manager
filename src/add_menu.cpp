//add menu.cpp
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>
//custom headers
#include "../include/utility.hpp"
#include "../include/add_menu.hpp"


void add_menu(){
	clear_screen();
	std::ofstream todaysLog;
	todaysLog.open(get_current_time_for_filename(), std::ios::app);
	std::string user_input = "";
	while(user_input != "quit"){
		std::cout<<"if you input 'quit' you will exit this menu\n\n";
		std::cout<<"please insert name of the task: ";
		std::getline(std::cin, user_input);
		user_input = normalize(user_input);
		clear_screen();
		if(user_input != "quit" && user_input.size() > 0){//don't add 'quit' or '' as a task
			todaysLog << user_input << "\n";
		}
	}
}
