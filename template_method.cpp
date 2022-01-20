#include "template_method.h"

int main() {
    library* lib = new application();
    lib->run();
    delete lib;
    return 0;
}
