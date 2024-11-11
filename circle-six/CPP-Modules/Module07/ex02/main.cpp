#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Array.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define MAX_VAL 10
int main(int, char **)
{
    srand(time(NULL));
    {
        std::cout << GREEN << "==={MAIN SUBJECT}===" << RESET << std::endl;
        Array<int> numbers(MAX_VAL);
        int *mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        // SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete[] mirror; //
    }
    {
        std::cout << GREEN << "==={MY TESTS}===" << RESET << std::endl;
        unsigned int size = rand() % 20;
        size++;
        std::cout << "size = " << size << std::endl;
        Array<float> numbers(size);
        float *mirror = new float[size];
        for (unsigned int i = 0; i < size; i++)
        {
            numbers[i] = (rand() % 10000) + (rand() % 10) / 10.0;
            mirror[i] = numbers[i];
        }
        std::cout << YELLOW;
        std::cout << "modfiy numbers" << std::endl;
        {
            unsigned int modify = rand() % size;
            std::cout << "    modify " << modify << " values" << std::endl;
            for (unsigned int i = 0; i < modify; i++)
            {
                unsigned int index = rand() % size;
                std::cout << "        before : numbers[" << index << "] = " << numbers[index] << std::endl;
                numbers[index] = (rand() % 10000) + (rand() % 10) / 10.0;
                std::cout << "        after  : numbers[" << index << "] = " << numbers[index] << std::endl;

            }
        }
        std::cout << RESET;
        //visua; part
        std::cout << "comparaison" << std::endl;
        std::cout << BLUE;
        std::cout << "+----+----------+----------+" << std::endl;
        std::cout << "|slot|    mirror" << "|" << "number    |" << std::endl;
        std::cout << "+----+----------+----------+-----+" << std::endl;
        std::cout << RESET;
        for (unsigned int i = 0; i < size; i++)
        {
            //visual part
            std::cout << BLUE << "|" << std::setw(4) << std::right << i << "|";
            //print part
            std::cout << CYAN << std::setw(10) << std::right << mirror[i];
            //visual part
            std::cout << BLUE << "|";
            //print part
            std::cout << CYAN << std::setw(10) << std::left << numbers[i];
            //visual part
            std::cout << BLUE << "|";
            //comparaison part
            if (mirror[i] != numbers[i])
                std::cout << RED << "ERROR" << RESET;
            else
                std::cout << GREEN << "GOOD " << RESET;
            //visual part
            std::cout << BLUE << "|" << RESET;
            std::cout << std::endl;
        }
        std::cout << BLUE << "+----+----------+----------+-----+" << RESET << std::endl;
    }

    return 0;
}