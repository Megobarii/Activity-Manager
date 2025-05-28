//add menu.cpp
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>
//custom headers
#include "utility.h"
#include "add_menu.h"

//FUNCTIONS LIST AT THE END OF FILE

void add_menu(){
	system("cls");
	std::ofstream todaysLog;
	todaysLog.open(get_current_time_for_filename(), std::ios::app);
	std::string user_input = "";
	while(user_input != "quit"){
		std::cout<<"if you input 'quit' you will exit this menu\n\n";
		std::cout<<"please insert name of the task: ";
		std::getline(std::cin, user_input);
		user_input = normalize(user_input);
		system("cls");
		if(user_input != "quit" && user_input.size() > 0){//don't add 'quit' or '' as a task
			todaysLog << user_input << "\n";
		}
	}
}

/*FUNCTIONS LIST:

add_menu: line 13 --> this functions let the user add a task to the tasks of today
*/