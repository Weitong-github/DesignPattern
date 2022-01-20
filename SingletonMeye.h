#include <string>
#include <iostream>
using namespace std;

class Person;

template<typename T>
class Singleton
{
public:
    static T& GetInstance()
    {
        static T instance;  // bss
        return instance;
    }

    Singleton(T&&) = delete;
    Singleton(const T&) = delete;
    void operator= (const T&) = delete;

protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};

class Person : public Singleton<Person>{
private:
    string m_name = "liujin";
    int m_age = 100;
    Person(){}
public:
    void getName() {
        cout<<m_name<<endl;
    }
    void setName(string& n) {
        m_name = n; 
    }
    void setAge(int& n) {
        m_age = n; 
    }
};

int main() {
    Person* chinese = nullptr;
    cout << &(chinese->GetInstance())<<endl;
    Person* american = nullptr;
    cout << &(american->GetInstance())<<endl;

    return 0;

    // chinese.GetInstance().getName();
    // Singleton<Person> chinese("liujin", 12);
}
