#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

void print_numbered_list() {
    std::string line;
    int i = 0;
    std::ifstream file("todo.txt"); 
    while (std::getline(file, line)) { 
        std::cout << ++i << ". " << line << std::endl;
    }
}

void add_task(const char* newtask) {
    std::ofstream file;
    file.open("todo.txt", std::ios::app); 
    file << newtask << "\n"; 
    file.close();
}

bool ValidInputQ(int line_no) {
    std::string line;
    int lines = 0;
    std::ifstream file("todo.txt"); 
    while (std::getline(file, line)) { 
        lines++;
    }
    return lines >= line_no && line_no > 0;
}

int GetLineToDeleteX() {
    int line_no;
    std::cout << "Enter a line number to delete: ";
    std::cin >> line_no;
    if (!ValidInputQ(line_no)) {
        std::cout << "invalid input" << std::endl;
        exit(1);
    }
    return line_no;
}

void delete_task() {
    int i = 1;
    int line_no = GetLineToDeleteX();;
    std::ifstream ifs("todo.txt");
    std::ofstream ofs("temp.txt");
    std::string line;
    while (std::getline(ifs, line)) {
        if (i != line_no) {
            ofs << line << std::endl;
        }
        i++;
    }  

    ifs.close();
    ofs.close();
    ifs.open("temp.txt");
    ofs.open("todo.txt");
    while(std::getline(ifs, line)) {
        ofs << line << std::endl;   
    }
    ofs.close();
    ifs.close();
    remove("temp.txt");
}

int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    } if (argc == 2 && std::string(argv[1]) == "view") {
        print_numbered_list();
    } else if (argc == 2 && std::string(argv[1]) == "delete") {
        print_numbered_list();
        delete_task();
    } else if (argc == 3 && std::string(argv[1]) == "add") {
        add_task(argv[2]);
    }

    return 0;
}
