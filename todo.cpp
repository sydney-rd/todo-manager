/*I want to be able to keep track of my to-do tasks for the app. 
I wanna be able to create a new to-do task like "fix phone verification bug" or "add database table for user transactions 
for private lessons" etc.
I also want to view all my to-do tasks and be able to delete one when I am finish working on it. task = str

For example, I am creating two new to-do tasks today, and I finish one of them in two days, so I delete it then, and 
I finish the other in a week and I delete it then. In the meantime I wanna be able to maybe create new ones and 
be able to view whatever existing to-do tasks are currently in progress or unfinished.

I want you to help me solve this problem as simple as possible. I wanna be able to do all that via the command line, 
inside my project's directory. Input is like writing something down, Output is reading, viewing it*/


/* int main() {

    return 0;
}
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

int main(int argc, char** argv) {
    std::ofstream file;
    std::string todoList;
    int i = 0;


    if (argc > 3) {
        std::cout << "Error, too many arguments." << std::endl;
    }

    if (std::string(argv[1]) == "view") {
        std::ifstream file("todo.txt");
        while(std::getline(file, todoList)) {
            std::cout << ++i << ". " << todoList << std::endl;
        }
        file.close();
    } else if (std::string(argv[1]) == "add" && argc == 3) {
        file.open("todo.txt", std::ios::app);
        file << argv[2] << "\n";
        file.close();

    } else if (std::string(argv[1]) == "delete") {
        int todo_delete;
        std::string line, deleteline;

        std::ifstream file("todo.txt");
        while (!file.eof()) {
            std::getline(file, todoList);
            std::cout << ++i << ". " << todoList << std::endl;
        }
        std::cout << "Please enter the number to delete: " << std::endl;
        std::cin >> todo_delete;
        while(getline(file, line)) {
            line.replace(line.find(deleteline), deleteline.length(),"");
            file << line << std::endl;
        }
       
        




    } else 
        std::cout << "Invalid input" << std::endl; //no command

    return 0;
}

// to do has to be in quotes 
// delete 
// view (two args)
// one main, 1 file, program is todo. Program -o file is todo
//if args c == 2 abd argv == "add, view" else/if 
//if second word is delete, delete code ask for user input
//if argc == 3 and argv 1 is add and argv 3 = "task" c
/* int main() {
    std::string user_task;
    std::cout << "Enter a to-do task: ";
    std::getline(std::cin, user_task);

    std::ofstream todo_list;
    todo_list.open("TO-DO LIST", std::ios::app);
    todo_list << user_task << "\n";
    todo_list.close();

    return 0;
}
*/

