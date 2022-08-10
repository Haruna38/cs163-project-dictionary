#include "structure.h"
#include "main.h"
#include "Console.h"
#include "function.h"

int dictionary()
{
    // Dictionary *dict = new Dictionary("English - Vietnamese");
    // dict->add("name", "n", "Tên gọi", "A topic");
    // dict->display("name");
    // dict->display("nam");

    Dictionary* dict = new Dictionary("Emotional");
    dict->import("emotional.txt", '\t', true, false);

    dict->display("4U");

    dict->remove("4U");

    dict->display("4U");

    dict->display(":-)");

    delete dict;

    Dictionary* dict2 = new Dictionary("Slangs");
    dict2->import("slang.txt", '`', false, true);

    dict2->display("ALPHA");

    dict2->remove("ALPHA");

    dict2->display("ALPHA");

    dict2->display("AMD");

    dict2->display("AMA");

    dict2->remove("AMA");

    dict2->display("AMA");

    delete dict2;

    return 0;
}

int main () {

    resizeConsole(ConsoleWidth, ConsoleHeight); // Console size
    SetConsoleTitle(TEXT("Dictionary")); // Dictionary Title
    veTieuDeTuDien();
    //dictionary();
    
}