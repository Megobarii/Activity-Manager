//utility2.h
#ifndef UTILITY2_H
#define UTILITY2_H

#include<iostream>

#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

#include<chrono>
#include<ctime>
#include<iomanip>
#include<sstream>
#include<vector>

void ask_user_input(std::string& user_input, std::vector<std::string>& file_content);
std::vector<std::string> get_file_content(std::ifstream& readFile, std::vector<std::string>& file_content);
void show_todays_activities(std::vector<std::string> file_content);
void show_tasks();
void complete_task(std::vector<std::string>& file_content, std::string user_input);
void delete_task(std::vector<std::string>& file_content, std::string user_input);
void write_to_file(std::ofstream& writeFile, std::vector<std::string>& file_content);


std::string normalize(std::string word);
std::string get_current_time_for_filename();

#endif