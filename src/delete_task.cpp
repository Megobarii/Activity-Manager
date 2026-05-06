//delete task .cpp
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>
//custom headers
#include "../include/utility.hpp"
#include "../include/delete_task.hpp"


void delete_task(){
	std::string filename = get_current_time_for_filename();
	std::ifstream todaysActivity;
	todaysActivity.open(filename);
	std::vector<std::string> file_content;
	
	if(todaysActivity.is_open() == false){
		throw std::runtime_error("there has been some error opening the file...")
	}else{
		//the file is open
		file_content = get_file_content(todaysActivity, file_content);
	}
	clear_screen();
	show_todays_activities(file_content);
	std::cout<<"\nplease specify the line to be deleted. Inser '0' to not delete any.\nYour answer: ";
	std::string user_input;
	ask_user_input(user_input, file_content);

	//deletion happends here
	
	size_t index = static_cast<size_t>(stoi(user_input)-1);//stoi converts to int, then convert to size_t
	if(index < file_content.size() && user_input != "0"){
		file_content.erase(file_content.begin() + index);
	}else{
		if(user_input != "0"){
			throw std::runtime_error("invalid user_input value inside delete_task function")
		}
	}
	
	//close file
	todaysActivity.close();
	//reopen in output mode
	std::ofstream writeFile;
	writeFile.open(filename);
	write_to_file(writeFile, file_content);
	writeFile.close();
}
