//complete_menu.cpp
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>
//custom headers
#include "utility.h"

//TODO: modularize this shit --DONE--needs testing
//TODO: pass file_content by reference for efficiency

//FUNCTIONS LIST at the end of file
	
void complete_menu(){
	system("cls");
	std::string filename = get_current_time_for_filename();
	std::ifstream readFile;
	std::ofstream writeFile;
	readFile.open(filename);
	
	//todo: add checking file being correctly open
	
	std::vector<std::string> file_content;
	
	//get file content into a vector
	if(readFile.is_open() == false){
		//todo: add some proper error handling
		std::cout<<"there has been some error opening the file...";
	}else{
		//the file is open
		file_content = get_file_content(readFile, file_content);
		
	}
	
	system("cls");
	show_todays_activities(file_content);
	std::cout<<"\nplease specify the line number of the task to be completed. Insert '0' to not delete any.\nYour answer: ";
	std::string user_input;
	ask_user_input(user_input, file_content);
	
	if(user_input != "0"){
		complete_task(file_content, user_input);
		writeFile.open(filename);
	
		write_to_file(writeFile, file_content);
	
		writeFile.close();
	}
	//----
	
	
	
	
	
	//close file
	readFile.close();
	//reopen in output mode
	
	
}

/*
FUNCTIONS LIST:
ask_user_input: line 14 --> takes user input, checks validity, if not valid ask again, if valid return user_input
------------------------------------
get_file_content: line 46 --> takes ifstream file, reads lines into a vector and return the vector
------------------------------------
show_todays_activities: line 54 --> shows the vector containing lines of the file
------------------------------------
complete_task: line 61 --> adds at the end of one of the vector's line --COMPLETED and return the vector
------------------------------------
write_to_file: line 73 --> writes to file the given vector
------------------------------------
MAIN FUNCTION:

complete_menu: line 79 --> main function, it handles the logic of the menu responsable for setting tasks as 
						   completed, uses the above functions
*/

/*OLD FUNCTIONS TO BE DELETED WHEN EVERYTHING WORKS

void ask_user_input(std::string& user_input, std::vector<std::string>& file_content){
	//asks user input and checks validity, returns only when is valid
	std::getline(std::cin, user_input);
	user_input = normalize(user_input);
	//check if user input makes sense
	bool user_input_valid = false;
	for(int i=0; i<file_content.size()+1; i++){
		if(user_input == std::to_string(i)){
			user_input_valid = true;
		}
	}
	//if invalid ask again
	while(user_input_valid == false){
		system("cls");
		std::cout<<"this is the content of today's activity: \n";
		for(int i=0; i<file_content.size(); i++){
			std::cout<<i+1<<")"<<file_content[i]<<"\n";
		}
		std::cout<<"your input doesn't make sense, please answer again: ";
		std::getline(std::cin, user_input);
		user_input = normalize(user_input);
		//check if user input makes sense
		user_input_valid = false;
		for(int i=0; i<file_content.size()+1; i++){
			if(user_input == std::to_string(i)){
				user_input_valid = true;
			}
		}
	}
}

std::vector<std::string> get_file_content(std::ifstream& readFile, std::vector<std::string>& file_content){
	std::string line;
	while (std::getline(readFile, line)) {
		file_content.push_back(line);
	}
	return file_content;
}

void show_todays_activities(std::vector<std::string> file_content){
	std::cout<<"this is the content of today's activity: \n";
	for(int i=0; i<file_content.size(); i++){
		std::cout<<i+1<<")"<<file_content[i]<<"\n";
	}
}

void complete_task(std::vector<std::string>& file_content, size_t index){
	//todo: change return type to bool and handle error better
	std::string line_content;
	if(index < file_content.size()){
		line_content = file_content[index] + "--TASK COMPLETED";
		file_content[index] = line_content;
	}else{
		std::cout<<"\nsorry, there has been some problem but i have no idea what...";
	}
}


void write_to_file(std::ofstream& writeFile, std::vector<std::string>& file_content){
	for(int i=0; i<file_content.size(); i++){
		writeFile<<file_content[i]<<"\n";
	}
}

*/