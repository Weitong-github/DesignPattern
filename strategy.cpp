#include "strategy.h"

int main() {
    Context cn(10,10);
    Context us(10,10);

    // TaxStrategy* a = new CNTax();
    // a->calculate(cn);
    // delete a;

    TaxStrategy* b = new USTax();
    aut c(b, cn);
    // b->calculate(us);
    delete b;
    
    // aut* c = new aut();
    // c->run();
    // delete c;
    

    return 0;
}