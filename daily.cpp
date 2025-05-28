#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>
//custom headers
#include "utility.h"
#include "add_menu.h"
#include "complete_menu.h"
#include "delete_task.h"
	
//plan activity
void plan_activity(){
	//todo: complete this and add to main
	/*this function makes you plan an activity for a different day than today*/
}	

//see streak
void see_streak(){
	//todo: complete this and add to main
	/*this requires some other functions as well, but there should be register of days where it is registered how many of the activities
	were completed in the past days*/
}

//hardcoded activities
void add_hardcoded_activities(){
	//todo: complete this and add to main
	/*this function allows the user to put a set of activities that are added automatically when the day is started
	for example if one studies chemistry everyday, doesn't have to add it everyday, when access the app for the first time of the day
	the activity is added automatically (unless manually deleted [this exception will be a pain])*/
}
	
int main(){
	bool running = true;
	
	while(running){
		//menu here
		system("cls");
		std::cout<<"choose one of the following options: ";
		std::cout<<"\n1)add today's activity";
		std::cout<<"\n2)complete an activity";
		std::cout<<"\n3)delete an activity";
		std::cout<<"\n4)show activities";
		std::cout<<"\n5)exit";
		std::string user_input;
		std::cout<<"\nYour answer: ";
		//---------GET INPUT-------------
		std::getline(std::cin, user_input);
		user_input = normalize(user_input);
		//----------CHECK INPUT----------
		while(user_input != "5" && user_input != "show" && user_input != "4" && user_input != "delete" && user_input != "1" && user_input != "2" && user_input != "3" && user_input != "exit" && user_input != "add" && user_input != "complete"){
			system("cls");
			std::cout<<"invalid answer...\n";
			std::cout<<"choose one of the following options: ";
			std::cout<<"\n1)add today's activity";
			std::cout<<"\n2)complete an activity";
			std::cout<<"\n3)delete activiry";
			std::cout<<"\n4)show activities";
			std::cout<<"\n5)exit";
			std::cout<<"\nYour answer: ";
			std::getline(std::cin, user_input);
			user_input = normalize(user_input);
		}
		
		//----------------MENU------------------------
		//todo: add "delete task" option
		if(user_input == "1" || user_input == "add"){
			//add
			add_menu();
		}else if(user_input == "2" || user_input == "complete"){
			//complete
			complete_menu();
		}else if(user_input == "3" || user_input == "delete"){
			//delete task from today
			delete_task();
		}else if(user_input == "4" || user_input == "show"){
			show_tasks();
		}else{
			//exit
			running = false;
		}
	}
	
	
	return 0;
}