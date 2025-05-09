#include "../include/opRandomMath.hpp"

double RandomMath::sigmoidExp(double x){
    return 1.0f / (1.0f + exp(-x));
}

double RandomMath::derOut_sigmoidExp(double ox){
    return ox * (1.0f - ox);
}

double RandomMath::der_sigmoidExp(double x){
    return sigmoidExp(x) * (1- sigmoidExp(x));
}


double RandomMath::getRandom(double start , double stop){
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> distr(start, stop);
    return distr(gen);
}