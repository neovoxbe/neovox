#include "NeoVox.h"

std::string NeoVox::getAnswer() {
    double* leak = new double[20];
    leak[2]=42.;
    return "42";
}
