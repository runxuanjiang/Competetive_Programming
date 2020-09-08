#include <cstring>
#include <iostream>
#include <algorithm>

class String{
private:
    static const char null = '\0';
    char* str;
    size_t size;
    size_t allocated;

    void swap(String& other) {
        std::swap(str, other.str);
        std::swap(size, other.size);
        std::swap(allocated, other.allocated);
    }

public:
    String() {
        str = new char[1];
        size = 0;
        str[0] = null;
    }

    String(char* rhs) {
        size = strlen(rhs);
        allocated = size + 1;
        str = new char[allocated];
        strcpy(str, rhs);
    }

    String(const String &rhs) : size(rhs.size), allocated(rhs.size + 1) {
        str = new char[allocated];
        strcpy(str, rhs.str);
    }


    ~String() {
        delete[] str;
        str = nullptr;
    }

    String& operator= (String &rhs) {
        String temp(rhs);
        swap(temp);
        return *this;
    }

    String& operator= (char* rhs) {
        String temp(rhs);
        swap(temp);
        return *this;
    }

    char& operator[] (size_t i) {
        return str[i];
    }

    const char& operator[] (size_t i) const {
        return str[i];
    }
    
    bool operator== (String &rhs) {
        if (size != rhs.size) return false;
        for (size_t i = 0; i <= size; ++i) {
            if (str[i] != rhs.str[i]) return false;
        }
        return true;
    }

    bool operator!= (String &rhs) {
        return !(*this == rhs);
    }

    String& operator+= (char i) {
        size_t newSize = size + 1;
        if (newSize + 1 > allocated) {
            allocated = 2*(newSize + 1);
            char* newStr = new char[allocated];
            strcpy(newStr, str);
            delete[] str;
            str = newStr;
        }
        str[size] = i;
        size = newSize;
        str[size] = null;
        return *this;
    }

    String& operator+= (char* rhs) {
        size_t newSize = size + strlen(rhs);
        if (newSize + 1 > allocated) {
            allocated = 2*(newSize + 1);
            char* newStr = new char[allocated];
            strcpy(newStr, str);
            delete[] str;
            str = newStr;
        }
        strcpy(str + size, rhs);
        size = newSize;
        return *this;
    }

    String& operator+= (String &i) {
        String copy(i);
        *this += (copy.str);
        return *this;
    }

    String& erase(size_t pos, size_t len) {
        for (size_t i = 0; i < (size - pos - len + 1); ++i) {
            str[pos + i] = str[pos + i + len];
        }
        size -= len;
        return *this;
    }

    size_t length() {
        return size;
    }

    void push_back(char c) {
        *this += c;
    }

    String substr(size_t pos, size_t len) {
        char cstr[len+1];
        for (size_t i = 0; i < len; ++i) {
            cstr[i] = str[pos+i];
        }
        cstr[len] = null;
        String res(cstr);
        return res;
    }

    const char* c_str() {
        return str;
    }

};

std::ostream& operator<<(std::ostream& os, String string) {
    os << string.c_str();
    return os;
}