#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

void numbered_list() {
    std::string todoList;
    int i = 0;
    std::ifstream file("todo.txt"); 
    while(std::getline(file, todoList)) { 
    std::cout << ++i << ". " << todoList << std::endl;
    }
}

void error_msg(int argc, char** argv) {
    if (std::string(argv[1]) != "delete" && std::string(argv[1]) != "view" && std::string(argv[1]) != "add") {
        std::cout << "Error: enter delete, view, or add\n";
    }
}

void view_list(int argc, char** argv) {
int i = 0;
std::ifstream file("todo.txt"); 
std::string todoList;
    if (std::string(argv[1]) == "view" && argc == 2) {
        numbered_list();
        file.close();
    }
}

void add_task(int argc, char** argv) {
    if (std::string(argv[1]) == "add" && argc == 3) {
        std::ofstream file;
        file.open("todo.txt", std::ios::app); 
        file << argv[2] << "\n"; 
        file.close();
    }
}

void delete_task(int argc, char** argv) {
    int i = 0, todo_delete;
    if (std::string(argv[1]) == "delete" && argc == 2) {
        std::ifstream file("todo.txt"); 
        numbered_list();
        std::cout << "Enter a line number to delete: ";
        std::cin >> todo_delete;
        std::string cmd = "sed -i.bak -e '" + std::to_string(todo_delete) + "d' todo.txt; rm todo.txt.bak";
        system(cmd.c_str());
        file.close();
    }
}

int main(int argc, char** argv) {
    view_list(argc, argv);
    add_task(argc, argv);
    delete_task(argc, argv);
    error_msg(argc, argv);

    return 0;
}



