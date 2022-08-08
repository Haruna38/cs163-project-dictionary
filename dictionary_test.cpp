#include "structure.h"

int main () {
    // Dictionary *dict = new Dictionary("English - Vietnamese");
    // dict->add("name", "n", "Tên gọi", "A topic");
    // dict->display("name");
    // dict->display("nam");
    
    Dictionary *dict = new Dictionary("Emotional");
    dict->import("emotional.txt", '\t', true, false);

    dict->display("4U");

    dict->remove("4U");

    dict->display("4U");

    dict->display(":-)");

    delete dict;

    Dictionary *dict2 = new Dictionary("Slangs");
    dict2->import("slang.txt", '`', false, true);

    dict2->display("ALPHA");

    dict->remove("ALPHA");

    dict->display("ALPHA");

    dict->display("AMD");

    delete dict2;

    return 0;
}