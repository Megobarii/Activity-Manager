//utility2.cpp
#include<iostream>
#include "utility.h"

#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

#include<chrono>
#include<ctime>
#include<iomanip>
#include<sstream>
#include<vector>

//TODO: modularize this shit --DONE--
//TODO: pass file_content by reference for efficiency --DONE-- for all functions actually

//FUNCTIONS LIST at the end of file --TODO

//normalize
std::string normalize(std::string word){//TESTING: this should substitute trim and toLower functions, delete them after testing
	//trimming
	size_t start = word.find_first_not_of(" \t");
	size_t end = word.find_last_not_of(" \t");
	word = (start == std::string::npos) ? "" : word.substr(start, end - start + 1);
	
	//lowering
	for(int i = 0; i < word.size(); ++i){
		if(word[i] >= 'A' && word[i] <= 'Z'){
			word[i] = word[i] + ('a' - 'A'); //ASCII diff is 32
		}
	}
	return word;
}

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

/*NOTE: show tasks is different from show_todays_activities because it is called from menu and retrieves file name also, while show todays 
activities, gets file content from the vector, inside menus show_todays_activites is more efficient, but from the main menu, file_content
doesn't exist, so the show_tasks function has to get informations from file on its own*/
void show_tasks(){
	system("cls");
	std::string filename = get_current_time_for_filename();
	std::ifstream dailyTask;
	dailyTask.open(filename);
	std::cout<<"these are today's tasks: \n";
	std::vector<std::string> file_content;
	
	std::string line;
	while (std::getline(dailyTask, line)) {
		file_content.push_back(line);
	}
	
	for(int i=0; i<file_content.size(); i++){
		std::cout<<i+1<<") "<<file_content[i]<<"\n";
	}
	std::cout<<"\n\npress any key to continue...";
	getch();
}	

void complete_task(std::vector<std::string>& file_content, std::string user_input){
	//todo: change return type to bool and handle error better
	//at this point input is valid so convert to int without too much checking
	size_t index = static_cast<size_t>(stoi(user_input)-1);//stoi converts to int, then convert to size_t
	std::string line_content;
	if(index < file_content.size()){
		line_content = file_content[index] + "--TASK COMPLETED";
		file_content[index] = line_content;
	}else{
		if(user_input != "0"){
			std::cout<<"\nsorry, there has been some problem but i have no idea what...";
		}
	}
}

void delete_task(std::vector<std::string>& file_content, std::string user_input){
	//at this point input is valid so convert to int without too much checking
	size_t index = static_cast<size_t>(stoi(user_input)-1);//stoi converts to int, then convert to size_t
	if(index < file_content.size() && user_input != "0"){
		file_content.erase(file_content.begin() + index);
	}else{
		if(user_input != "0"){
			std::cout<<"\nsorry, there has been some problem but i have no idea what...";
		}
	}
}


void write_to_file(std::ofstream& writeFile, std::vector<std::string>& file_content){
	for(int i=0; i<file_content.size(); i++){
		writeFile<<file_content[i]<<"\n";
	}
}

//get date for filename
std::string get_current_time_for_filename() {//get current time
    // Get current time point
    auto now = std::chrono::system_clock::now();

    // Convert to time_t
    std::time_t time_t_now = std::chrono::system_clock::to_time_t(now);

    // Convert to tm (local time)
    std::tm tm_now;
#ifdef _WIN32
    localtime_s(&tm_now, &time_t_now); // Windows
#else
    localtime_r(&time_t_now, &tm_now); // POSIX
#endif

    // Format as string
    std::ostringstream oss;
    oss << std::put_time(&tm_now, "%Y-%m-%d");
    
	std::string filename = "log_" + oss.str() + ".txt";
	return filename;
}