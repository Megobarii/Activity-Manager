//utility2.cpp
#include <iostream>
#include "../include/utility.hpp"
#include <fstream>
#include <string>
#include <conio.h>

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cstdlib>

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


//normalize
std::string normalize(std::string word){
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


void show_todays_activities(std::vector<std::string> file_content){
	std::cout<<"this is the content of today's activity: \n";
	for(int i=0; i<file_content.size(); i++){
		std::cout<<i+1<<")"<<file_content[i]<<"\n";
	}
}

bool is_valid_input(const std::string& input, int max) {
    try {
        int value = std::stoi(input);
        return value >= 1 && value <= max;
    } catch (...) {
        return false;
    }
}

void ask_user_input(std::string& user_input, std::vector<std::string>& file_content){
	//asks user input and checks validity, returns only when is valid
	do {
		std::getline(std::cin, user_input);
		user_input = normalize(user_input);

		if (!is_valid_input(user_input, file_content.size())) {
			clear_screen();
			std::cout << "this is the content of today's activity:\n";
			for (int i = 0; i < file_content.size(); i++) {
				std::cout << i+1 << ")" << file_content[i] << "\n";
			}
			std::cout << "your input is invalid, please answer again: ";
		}

	} while (!is_valid_input(user_input, file_content.size()));
}

std::vector<std::string> get_file_content(std::ifstream& readFile, std::vector<std::string>& file_content){
	std::string line;
	while (std::getline(readFile, line)) {
		file_content.push_back(line);
	}
	return file_content;
}


void show_tasks(){
	clear_screen();
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
