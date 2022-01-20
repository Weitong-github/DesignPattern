class ISplitter {
public:
    virtual void split() = 0;
    virtual ISplitter* Clone() = 0; // 通过克隆自己创建对象

    virtual ~ISplitter(){}
};

class BinarySplitter : public ISplitter {
public:
    virtual void split() {
        
    }
    virtual ISplitter* Clone() {
        return new BinarySplitter(*this);
    }
};

class MainForm {
    ISplitter* prototype;
public:
    MainForm(ISplitter* prototype) {this->prototype = prototype;}
    void Button_Click() {
        ISplitter* splitter = prototype->Clone();
        splitter->split();
    }
};

void func() {
    BinarySplitter* a = new BinarySplitter();
    MainForm* m = new MainForm(a);
    m->Button_Click();
}