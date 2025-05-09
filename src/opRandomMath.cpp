#include "../include/opRandomMath.hpp"

std::mt19937 RandomMath::gen(std::random_device{}());

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
    std::uniform_real_distribution<double> distr(start, stop);
    return distr(gen);
}


std::mt19937 RandomMath::getGenerator(){
    return gen;
}