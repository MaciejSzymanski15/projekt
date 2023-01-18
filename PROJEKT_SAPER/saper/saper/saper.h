#pragma once
#include<SFML/Graphics.hpp>
#include<time.h>
#include <vector>
#include <random>
#include <iostream>
#include <fstream>

using namespace sf;

using std::vector, std::endl, std::string, std::cout;

class Board {
public:
    int value{};
    int discovered{};
};


using Vac = vector <Board>;
using Mac = vector <Vac>;

