#ifndef _STRATEGY_

#include <iostream>
#include <memory>
struct Context {
    int month;
    double base;
    Context(int m, double b):month(m),base(b){}
};

class TaxStrategy {
public:
    virtual double calculate(Context& context) = 0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy {
public:
    virtual double calculate(Context& context) {
        // month*base*0.05
        double interest = context.base*context.month*0.05;
        std::cout<<"China's interest is "<<interest<<std::endl;
        return interest;
    }
};

class USTax : public TaxStrategy {
public:
    virtual double calculate(Context& context) {
        // month*base*0.04
        double interest = context.base*context.month*0.04;
        std::cout<<"US's interest is "<<interest<<std::endl;
        return interest;
    }   
};

// // 想再封装一层，失败
// 工厂模式之后再来

// class aut {
// private:
//     TaxStrategy* tax;
// public:
//     double run(Context& context) {
//         return tax->calculate(context);
//     }
// };


class aut{
 private:
    TaxStrategy* tax;
 public:
    aut(TaxStrategy* tax_t, Context& content) {
        tax = tax_t;
        double a = tax->calculate(content);
        std::cout<<"here" << a<<std::endl;
    }
    ~aut(){delete tax;}
};

#endif