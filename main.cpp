#include<iostream>
#include<fstream>
#include<string>
void show_content();
void show_menu();
void show_header();
using namespace std;
int main() {
    cout << "Content-type: text/html; charset=Windows-1251\n\n";
    ifstream f("_index.html");
    if (f.is_open()) {
        auto sz = 65536;
        auto buf = new char[sz];
        while (!f.eof()) {
            f.getline(buf, sz);
            if (strcmp(buf, "<!--content-->") == 0) {
                show_content();  //дополнительный текст
            }
            else if (!strcmp(buf, "<!--menu-->")) {
                show_menu();
            }
            else if (!strcmp(buf, "<!--HEADER-->")) {
                show_header();
            }
            cout << buf;
        }
        delete[] buf;
        f.close();
    }
    else {
        cout << "Не удалось открыть страницу :( ";
    }
}
void show_header() {
    cout << "Вторая страница(задание 1)";
}
void show_menu() {
    ifstream f("menu.html");
    if (f.is_open()) {
        auto sz = 1024;
        auto buf = new char[sz];
        while (!f.eof()) {
            f.getline(buf, sz);
            char* name;
            char* addrr = strtok_s(buf, " ", &name);
            cout << "<div class='menu.html'>"
                "<a href='" << addrr << "'> " <<
                name << "</a>"
                "</div>";
        }
    }
}
struct task
{
    char val; 
    task* next = nullptr; 
    int num;
};
void push(task*& stack, char val, int num) 
{
    task* newt = new task;
    newt->val = val;
    newt->num = num;
    if (!stack) 
    { 
        stack = newt;  
        return;
    }
    newt->next = stack;
    stack = newt;
} 
bool pop(task*& stack, int& num) 
{
    if (!stack) {
        return false;
    }
    task* newt = stack; 
    num = stack->num;
    stack = stack->next; 
    delete newt;
    return true;
}
char* peek(task* stack) {
    if (!stack) return nullptr;
    return &stack->val;
}

void show_content() {
    cout << "Это дополнительный текстна второй  странице";
}
