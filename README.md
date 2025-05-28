# Activity-Manager
A simple terminal app that lets you set your daily activities, delete them, complete them, see them. Future updates may add more features

----------------------------------------------------
This is my first github repository, so it might look a bit "raw", sorry for that. Btw if you have comments, suggestions or changes feel free to comunicate (i think there is a way to comunicate somehow)

----------------------------------------------------
FILES STRUCTURE:

daily.cpp is the "main" where everything is handled
utility.cpp and its header are the second most important part, basically all functions outside of menus are in there, future functions will probably end up there. add_menu, complete_menu and delete_task are all menus called inside the daily (wich, again, is the main) based on user input. 
[Note: there is a slight inconsistency because they are all called *_menu while delete_task ends with _task, there is no reason to it, will change it eventually, doesn't seem that important right now]

There are comments all over the files, there is some comments about what have been done and sometime even why, there are some empty functions in daily.cpp, they are functions that i want to add in the future.
