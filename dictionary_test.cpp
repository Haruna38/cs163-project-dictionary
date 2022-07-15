#include "structure.h"

int main () {
    Dictionary *dict = new Dictionary("English - Vietnamese");
    dict->add("name", "n", "Tên gọi", "A topic");
    dict->display("name");
    dict->display("nam");
    delete dict;
    return 0;
}