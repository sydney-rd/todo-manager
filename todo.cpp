#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

int main(int argc, char** argv) {

    if (argc > 3) {
        std::cout << "Error, too many arguments." << std::endl; //if argc exceeds 3 arguments, an error will display
    }

    if (argc == 2 && std::string(argv[1]) == "view") { // if index 1 is equal to view, this code will execute
        int i = 0;
        std::string todoList;
        std::ifstream file("todo.txt"); // opens a file called todo.txt
        while(std::getline(file, todoList)) { // adds number to each line
            std::cout << ++i << ". " << todoList << std::endl;
        }
        file.close();
    } else if (std::string(argv[1]) == "add" && argc == 3) { // if index one is equal to add or if the arg count is equal to 3
        std::ofstream file;
        file.open("todo.txt", std::ios::app); // opens file, appends 
        file << argv[2] << "\n"; // immediatly takes user input from cli (index 2)
        file.close();

    } else if (argc == 2 && std::string(argv[1]) == "delete") {
        
        std::ifstream file("todo.txt"); //ifstream open same?
        // while loop adds numbers to each line
        std::string todoList;
        int i = 0;
        while (std::getline(file, todoList)) {
            std::cout << ++i << ". " << todoList << std::endl;
        }

        // takes user input 
        int todo_delete; // user inputs line number to be deleted
        std::cout << "Delete task number: ";
        std::cin >> todo_delete;    

        // deletes line in txt file
        std::string cmd = "sed -i.bak -e '" + std::to_string(todo_delete) + "d' todo.txt; rm todo.txt.bak";
        system(cmd.c_str());


        std::ifstream file2("todo.txt");
        std::string todoline;
        int i = 1;
        std::ofstream temp;
        temp.open("temp.txt");
        while (std::getline(file2, todoline) {
            if (i != todo_delete) {
                temp << todoline << std::endl;
            }
            i++;
        }
        
        file.close();
    } else 
        std::cout << "Invalid input" << std::endl; //no command

    return 0;
}



