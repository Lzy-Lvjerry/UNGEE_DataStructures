//
// Created by lvjer on 2019/11/24.
//

#ifndef UNGEE_DATASTRUCTURES_STRING_H
#define UNGEE_DATASTRUCTURES_STRING_H

#include <cstring>
#include "List.h"

class String {
public:
    String();

    ~String();

    String(const String &copy);

    String(const char *copy);

    String(List<char> &copy);

    void operator=(const String &copy);

    // conversion to C-style string
    const char *c_str() const;

protected:
    char *entries;
    int length;
};

bool operator==(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str());
}

bool operator>(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) > 0;
}

bool operator<(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) < 0;
}

bool operator>=(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) >= 0;
}

bool operator<=(const String &first, const String &second) {
    return strcmp(first.c_str(), second.c_str()) <= 0;
}

bool operator!=(const String &first, const String &second) {
    return false;
}

String::String() {
    length = 0;
    entries = nullptr;
}

String::~String() {
    delete[]entries;
}

String::String(const String &copy) {
    length = copy.length;
    entries = new char[length];
    strcpy(entries, copy.entries);
}

String::String(const char *copy) {
    length = strlen(copy);
    entries = new char[length + 1];
    strcpy(entries, copy);
}

String::String(List<char> &copy) {
    length = copy.size();
    entries = new char(length + 1);
    for (int i = 0; i < length; ++i) {
        copy.retrieve(entries[i], i);
    }
    entries[length] = '\0';
}

void String::operator=(const String &copy) {
    length = copy.length;
    entries = new char[length];
    strcpy(entries, copy.entries);
}

const char *String::c_str() const {
    return (const char *) entries;
}

void strcat(String &add_to, const String &add_on) {
    const char *cfirst = add_to.c_str();
    const char *csecond = add_on.c_str();
    char *copy = new char[strlen(cfirst) + strlen(csecond) + 1];
    strcpy(copy, cfirst);
    strcat(copy, csecond);
    add_to = copy;
    delete[]copy;
}

String read_in(std::istream &input) {
    List<char> temp;
    int size = 0;
    char c;
    while ((c = input.peek()) != EOF && (c = input.get()) != '\n') {
        temp.insert(size++, c);
    }
    String answer(temp);
    return answer;
}

void write(String &s) {
    std::cout << s.c_str() << std::endl;
}

void strcpy(String &copy, const String &original) {
    copy = original;
}

void strncpy(String &copy, const String &original, int n) {

}
int strstr(const String &text,const String &target);
#endif //UNGEE_DATASTRUCTURES_STRING_H
