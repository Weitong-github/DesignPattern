#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

template<typename T>
class Singleton {
private:
    // Singleton(const T& other){}
    static atomic<T*> m_instance;
    static std::mutex m_mutex;
    Singleton(){}
    friend class Foo;  //  new T 会先调用父类的构造函数，但子类无法调用个父类的构造函数，所以要加一个友元
public:
    
    static T* getInstance();
    // Singleton(T&&) = delete;
    // Singleton(const T&) = delete;
    // void operator = (const T&) = delete;
protected:
    virtual ~Singleton(){}
};

// static修饰的
template<class T>
atomic<T*> Singleton<T>::m_instance;
template<class T>
std::mutex Singleton<T>::m_mutex;

template<typename T>
T* Singleton<T>::getInstance() {
    T* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if(tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if(tmp == nullptr) {
            tmp = new T();  // new T() ? ?
            std::atomic_thread_fence(std::memory_order_release);
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return m_instance;
}

class Foo : public Singleton<Foo> {
private:
    int m_a = 0;
    int m_b = 0;
public:
    void getA(){
        cout<< m_a<<endl;
    }
};

void SingletonTest() {

    // // 测试方法1
    Foo* f1 = nullptr;
    f1 = f1->getInstance();
    Foo* f2 = nullptr;
    f2 = f2->getInstance();

    thread t1(&Foo::getA, f1);    
    thread t2(&Foo::getA, f2);
    t1.join();
    t2.join();

    // 测试方法1，错的，没有调用单例，所以没有地址
    // Foo* f1;
    // Foo* f2;
    // thread t1(&Foo::getA, f1);    
    // thread t2(&Foo::getA, f2);
    // t1.join();
    // t2.join();

    // // 测试方法2
    // Foo* f3 = nullptr;
    // f3->getInstance()->getA();
    // Foo* f4 = nullptr;
    // f4->getInstance()->getA();
}


int main() {
    SingletonTest();
    return 0;
}