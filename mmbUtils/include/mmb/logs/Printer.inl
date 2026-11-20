#ifndef MMB_UTILS_LOGS_PRINTER_INL
#define MMB_UTILS_LOGS_PRINTER_INL

#include <iostream>
#include <vector>

namespace mmb
{
    template<typename T>
    void printVector(const std::vector<T>& _v, bool _endNewLine = false, bool _newLine = false)
    {
        std::cout << '[';
        for (size_t i = 0; i < _v.size(); i++)
        {
            if (_newLine) std::cout << "\n\t";
            std::cout << _v[i];
            if (i < _v.size() - 1) std::cout << ", ";
        }
        if (_newLine) std::cout << std::endl;
        std::cout << ']';
        if (_endNewLine) std::cout << std::endl;
    }

    template<typename T>
    void printVectorAsBits(const std::vector<T>& _v, bool _endNewLine = false, bool _newLine = false)
    {
        std::cout << '[';
        for (size_t i = 0; i < _v.size(); i++)
        {
            if (_newLine) std::cout << "\n\t";
            printBits(_v[i], false);
            if (i < _v.size() - 1) std::cout << ", ";
        }
        if (_newLine) std::cout << std::endl;
        std::cout << ']';
        if (_endNewLine) std::cout << std::endl;
    }

} // namespace mmb

#endif // Include guard MMB_UTILS_LOGS_PRINTER_INL