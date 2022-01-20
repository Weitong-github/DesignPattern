#include <mutex>
#include <atomic>
using namespace std;
class Singleton {
    // Singleton一定要把构造函数和复制构造函数写在private里边，因为系统会有磨人的构造函数和复制构造函数，我们要确保这两个函数不能被外部调用
private:
    Singleton();
    Singleton(const Singleton& other);
public:
    static Singleton* getInstance();
    static atomic<Singleton*> m_instance;  // c++11版本之后的跨平台实现（volatile）
    // static Singleton* m_instance; // 线程非安全版本 ||  双检查锁，但由于内存读写recorder不安全
    static std::mutex m_mutex;
};

// Singleton* Singleton::m_instance = nullptr;

// 线程非安全版本
Singleton* Singleton::getInstance() {
    if(m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

// 线程安全版本，但锁的代价过高
std::mutex mtx;
Singleton* Singleton::getInstance() {
    mtx.lock();
    if(m_instance == nullptr) {
        m_instance = new Singleton();
    }
    mtx.unlock();
    return m_instance;
}

// 双检查锁，但由于内存读写recorder不安全
Singleton* Singleton::getInstance() {
    if(m_instance = nullptr) {
        mtx.lock();
        if(m_instance == nullptr) {
            m_instance = new Singleton();
        }
        mtx.unlock();
    }
    return m_instance;
}

// c++11版本之后的跨平台实现（volatile）

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);// 本线程中，所有后续的读操作，必须在本条原子操作完成后执行。(本线程中，我先读，你们后读……)
    if(tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if(tmp == nullptr) {
            tmp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release); // 本线程中，所有之前的写操作完成后，才能执行本原子操作。（在本线程中，你们先写，我最后写……）
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return m_instance;
}
