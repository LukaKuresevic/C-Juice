#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int randint(int min, int max) {
    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> gen(min, max);

    return gen(rng);
}

std::string get_random_line(const std::string &filename){
    std::ifstream infile(filename);

    std::string line;
    std::vector<std::string> lines;
    while (std::getline(infile, line))
    {
        lines.push_back(line);
    }

    return lines[randint(0, lines.size()-1)];
}

void print_creature(const std::string &creature, const std::string &attribute, const std::string &weapon){
    switch (randint(0, 3))
    {
    case 0:
        std::cout << "A " << attribute << " " << creature << " who is wielding a " << weapon << std::endl;
        break;
    case 1:
        std::cout << "A " << weapon << " wielding " << creature << " who is " << attribute << std::endl;
        break;
    case 2:
        std::cout << "A " << creature << " who is " << attribute << " and has a " << weapon << std::endl;
        break;
    case 3:
        std::cout << "A " << creature << " with a " << attribute << " additude " << "with an " << weapon << std::endl;
        break;
    }
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " creatures_file attributes_file weapons_file";
        return 1;
    }

    std::string creature = get_random_line(argv[1]);
    std::string attribute = get_random_line(argv[2]);
    std::string weapon = get_random_line(argv[3]);
    
    print_creature(creature, attribute, weapon);
    return 0;
}