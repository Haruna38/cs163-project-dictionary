#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Character;

struct partOfSpeechDataset {
    public:
        string getFullNameOf (string abbr) {
            if (abbr == "n") return "Noun";
            if (abbr == "adj") return "Adjective";
            if (abbr == "adv") return "Adverb";
            if (abbr == "v") return "Verb";
            return "";
        }
};

partOfSpeechDataset *pOFDataset = new partOfSpeechDataset();

class Charset {
    public:
        char key;
        Character *data;
        Charset *left, *right;
        Charset(char k, Character* value): key(k), data(value), left(NULL), right(NULL) {}

        // ~Charset ();
};

class CharsetTree {
    public:
        Charset* add (char key, Character* &value);
        Charset* find (char key);

        bool isEmpty();

        // ~CharsetTree ();
    private:
        Charset *data = NULL;
};

class Character {
    public:
        Character *parent;
        CharsetTree* nextCharacters = new CharsetTree();
        bool isLastCharacter;
        string partOfSpeech = "", definition = "", topic = "";
        Character () {};
        Character (Character *parent, string pOF, string def, string tpc): parent(parent), partOfSpeech(pOF), definition("* " + def), topic(tpc), isLastCharacter(true) {};
        Character (Character *parent): parent(parent), partOfSpeech(""), definition(""), topic(""), isLastCharacter(false) {};

        void display ();

        Character* next (char f);

        // ~Character ();
};

class Dictionary {
    public:
        string name = "";

        void add (string word, string partOfSpeech, string definition, string topic) {
            Character *node = data;
            int len = word.length();
            for (int i = 0; i < len; ++i) {
                int key = word[i];
                Character* nextChar;
                if (i < len - 1) nextChar = new Character(node);
                else nextChar = new Character(node, partOfSpeech, definition, topic);
                node = node->nextCharacters->add(key, nextChar)->data;
            }
            node->isLastCharacter = true;
        }

        void remove(string word) {
            Character *node = data;
            for (int i = 0; i < word.length(); ++i) {
                node = node->next(word[i]);
                if (node == NULL) return;
            }
            if (!node->isLastCharacter) return;
            // traverse back
            bool lastWordDeleted = false;
            while (node->parent != data) {
                Character* cur = node;
                node = node->parent;
                if (!lastWordDeleted) {
                    lastWordDeleted = true;
                    cur->isLastCharacter = false;
                }
                if (cur->isLastCharacter || !cur->nextCharacters->isEmpty()) return;
                delete cur;
            }
        }

        Character* find(string word) {
            Character *node = data;
            for (int i = 0; i < word.length(); ++i) {
                node = node->next(word[i]);
                if (node == NULL) return NULL;
            }
            if (!node->isLastCharacter) return NULL;
            return node;
        }

        bool wordExists (string word) {
            return find(word) != NULL;
        }

        void display (string word) {
            Character *result = find(word);
            if (result == NULL) cout << "No results found for the word '" << word << "'. Maybe you wish to add it as a custom word?" << endl;
            else {
                cout << "Definition of the word '" << word << "':" << endl;
                result->display();
            }
        }

        bool import (string pathToFile, char discriminator, bool repeatable, bool ignoreFirstLine) {
            ifstream fin(pathToFile);
            if (fin.fail()) {
                fin.close();
                cout << "Import failed for the dictionary '" << name << "'." << endl;
                return false;
            }
            string word = "", definition = "";
            int count = 0;
            while (!fin.eof() || word != "") {
                int i = 0;
                string temp = "", data = "";
                if (!fin.eof()) {
                    getline(fin, data);
                    if (data == "") continue;
                    if (ignoreFirstLine) {
                        ignoreFirstLine = false;
                        continue;
                    }
                    bool reac = false;
                    for (; i < data.length(); ++i) {
                        if (data[i] == discriminator) {
                            reac = true;
                            ++i;
                            if (repeatable) while (data[i] == discriminator) ++i;
                            break;
                        }
                        temp += data[i];
                    }
                    if (!reac) {
                        definition += (definition == "" ? "" : "\n");
                        definition += "* " + temp;
                        continue;
                    }
                }
                else temp = "";

                if (word != "") {
                    ++count;
                    add(word, "", definition, "");
                }

                word = temp;

                definition = "";

                if (!fin.eof()) for (; i < data.length(); ++i) definition += data[i];
            }

            fin.close();

            cout << "Imported " << count << " word(s) to the dictionary '" << name << "'." << endl; 

            return true;
        }

        Dictionary (string namae): name(namae) {};

        ~Dictionary () {
            delete data;
        }
    private:
        Character *data = new Character(NULL);
};

// Charset::~Charset () {
//     delete data;
//     if (left != NULL) delete left;
//     if (right != NULL) delete right;
// };

Charset* CharsetTree::add (char key, Character* &value) {
    Charset *newNode = new Charset(key, value);
    if (data == NULL) return data = newNode;
    Charset *prev = NULL, *cur = data;
    while (cur != NULL) {
        if (key == cur->key) {
            if (value->isLastCharacter) {
                cur->data->isLastCharacter = true;
                cur->data->definition += (cur->data->definition == "" ? "" : "\n");
                cur->data->definition += "* " + value->definition;
                cur->data->topic += (cur->data->topic == "" ? "" : ", ")  + value->topic;
            }
            delete newNode;
            return cur;
        }
        prev = cur;
        if (key < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    if (key < prev->key) return prev->left = newNode;
    return prev->right = newNode;
};

Charset* CharsetTree::find (char key) {
    Charset *cur = data;
    while (cur != NULL) {
        if (key < cur->key) cur = cur->left;
        else if (key > cur->key) cur = cur->right;
        else break;
    }
    return cur;
};

bool CharsetTree::isEmpty () {
    return data == NULL;
}

// CharsetTree::~CharsetTree () {
//     if (data != NULL) delete data;
// };

void Character::display () {
    cout << "Part Of Speech: (" << partOfSpeech << ") " << pOFDataset->getFullNameOf(partOfSpeech) << endl;
    cout << "Definition:" << endl << definition << endl;
    cout << "Topic/Field: " << topic << endl; 
};

Character* Character::next (char f) {
    Charset* found = nextCharacters->find(f);
    if (found == NULL) return NULL;
    return found->data;
};

// Character::~Character () {
//     delete nextCharacters;
// }