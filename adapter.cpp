// 目标接口（新接口）
class ITarget {
public:
    virtual void process() = 0;
};
// 遗留接口（老接口）
class IAdaptee {
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

// 遗留类型仍符合老的接口
class OldClass : public IAdaptee {
public:
    virtual void foo(int data) {
        // ...
    }
    virtual int bar() {
        // ...
    }
};
// 对象适配器
class Adapter : public ITarget {
protected:
    IAdaptee* pAdaptee;
public:
    Adapter (IAdaptee* pAdaptee) : pAdaptee(pAdaptee){}
    virtual void process() {
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }
};
 
// 类适配器（不太好）
class Adapter : public ITarget, protected IAdaptee { // 多继承

};

int main() {
    IAdaptee* pAdaptee = new OldClass();
    // ITarget* pTarget = new Adapter(pAdaptee);  // ？？？？
    // pTarget->process();
    return 0;
}