#ifndef _TEMPLATE_METHOD_

#include <iostream>


class library {
public:
    void run() {
        step1();
        if (step2()) {
            step3();
        }

        for(int i = 0; i<4; i++) {
            step4();
        }
        step5();
    }

    virtual ~library(){}

protected:
    void step1(){}
    void step3(){
        std::cout <<"step2 is true"<<std::endl;
    }
    void step5(){
        std::cout<<"right answer"<<std::endl;
    }

    virtual bool step2() = 0;
    virtual void step4() = 0;
};

class application : public library {
protected:
    virtual bool step2() {
        return true;
    }
    virtual void step4() {
        std::cout<<"should repeat 4 times"<<std::endl;
    }
};

#endif 