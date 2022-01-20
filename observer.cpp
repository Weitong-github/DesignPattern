#include "observer_mystring.h"

int main() {
    std::string a = "aaabbbcccdddeeeff";
    MyString m_s;
    m_s.split(a,3);
    return 0;
}

