//complete_menu.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
//custom headers
#include "../include/utility.hpp"
	
void complete_menu(){
	clear_screen();
	std::string filename = get_current_time_for_filename();
	std::ifstream readFile;
	std::ofstream writeFile;
	readFile.open(filename);
	
	std::vector<std::string> file_content;
	
	//get file content into a vector
	if(readFile.is_open() == false){
		throw std::runtime_error("there has been some error opening the file...")
	}else{
		//the file is open
		file_content = get_file_content(readFile, file_content);
		
	}
	
	clear_screen();
	show_todays_activities(file_content);
	std::cout<<"\nplease specify the line number of the task to be completed. Insert '0' to go back.\nYour answer: ";
	std::string user_input;
	ask_user_input(user_input, file_content);
	
	if(user_input != "0"){
		
		size_t index = static_cast<size_t>(stoi(user_input)-1);//stoi converts to int, then convert to size_t
		std::string line_content;
		if(index < file_content.size()){
			line_content = file_content[index] + "--TASK COMPLETED";
			file_content[index] = line_content;
		}else{
			if(user_input != "0"){
				throw std::runtime_error("invalid user_input value inside complete_menu() function");
			}
		}
		
		writeFile.open(filename);
	
		write_to_file(writeFile, file_content);
	
		writeFile.close();
	}

	
	//close file
	readFile.close();
}
