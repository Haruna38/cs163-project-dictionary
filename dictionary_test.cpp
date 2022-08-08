#include "structure.h"
#include "main.h"
#include "Console.h"
#include "functions.h"
int main()
{
    resizeConsole(ConsoleWidth, ConsoleHeight); //Kich thuoc man hinh console
    SetConsoleTitle(TEXT("Dictionary")); // Tieu de tu dien
    Dictionary *dict = new Dictionary("English - Vietnamese");
    dict->add("name", "n", "Tên gọi", "A topic");
    dict->display("name");
    dict->display("nam");
    delete dict;
    return 0;
}