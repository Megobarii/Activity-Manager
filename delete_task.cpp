//delete task .cpp
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>
//custom headers
#include "utility.h"
#include "delete_task.h"

//TODO: modularize this massive shit of code --DONE-- inside utility header
//BUG: when there is only one task, the task can't be deleted!!! --FIXED-- index error


//----------------------------------------

void delete_task(){
	std::string filename = get_current_time_for_filename();
	std::ifstream todaysActivity;
	todaysActivity.open(filename);
	std::vector<std::string> file_content;
	
	if(todaysActivity.is_open() == false){
		//todo: add some proper error handling
		std::cout<<"there has been some error opening the file...";
	}else{
		//the file is open
		file_content = get_file_content(todaysActivity, file_content);
	}
	system("cls");
	show_todays_activities(file_content);
	std::cout<<"\nplease specify the line to be deleted. Inser '0' to not delete any.\nYour answer: ";
	std::string user_input;
	ask_user_input(user_input, file_content);
	
	
	
	delete_task(file_content, user_input);
	//close file
	todaysActivity.close();
	//reopen in output mode
	std::ofstream writeFile;
	writeFile.open(filename);
	write_to_file(writeFile, file_content);
	writeFile.close();
}