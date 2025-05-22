#include "UI.hpp"

int main() {

    run_container();
    if (!container_num) {
        delete container;
        delete mut_sequence;
        delete immut_sequence;
        return 0;
    }

    run_method();
    if (!method) {
        delete container;
        delete mut_sequence;
        delete immut_sequence;
        return 0;
    }
}