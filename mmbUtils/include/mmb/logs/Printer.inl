#ifndef MMB_UTILS_LOGS_PRINTER_INL
#define MMB_UTILS_LOGS_PRINTER_INL

#include <bitset>
#include <vector>
#include <iostream>

namespace mmb
{
    template<typename T>
    void printBits(T _value, bool _endNewLine)
    {
        std::cout << asBits(_value);
        if (_endNewLine) std::cout << std::endl;
    }

    template<typename T>
    std::string asBits(T _value)
    {
        std::string str;
        str.reserve(sizeof(T) * 9);

        unsigned char bytes[sizeof(T)];
        std::memcpy(bytes, &_value, sizeof(T));

        for (int i = sizeof(T) - 1; i >= 0; i--)
        {
            str += std::bitset<8>(bytes[i]).to_string();
            if (i > 0) str += ' ';
        }

        return str;
    }

    template<typename T>
    void printArray(T* _arr, size_t _size, bool _endNewLine, bool _newLine)
    {
        std::cout << '[';
        for (size_t i = 0; i < _size; i++)
        {
            if (_newLine) std::cout << "\n\t";
            std::cout << _arr[i];
            if (i < _size - 1) std::cout << ", ";
        }
        if (_newLine) std::cout << std::endl;
        std::cout << ']';
        if (_endNewLine) std::cout << std::endl;
    }

    template<typename T>
    void printVector(const std::vector<T>& _v, bool _endNewLine, bool _newLine)
    {
        printArray(_v.data(), _v.size(), _endNewLine, _newLine);
    }

    template<typename T>
    void printArrayAsBits(T* _arr, size_t _size, bool _endNewLine, bool _newLine)
    {
        std::cout << '[';
        for (size_t i = 0; i < _size; i++)
        {
            if (_newLine) std::cout << "\n\t";
            std::cout << asBits(_arr[i]);
            if (i < _size - 1) std::cout << ", ";
        }
        if (_newLine) std::cout << std::endl;
        std::cout << ']';
        if (_endNewLine) std::cout << std::endl;
    }

    template<typename T>
    void printVectorAsBits(const std::vector<T>& _v, bool _endNewLine, bool _newLine)
    {
        printArrayAsBits(_v.data(), _v.size(), _endNewLine, _newLine);
    }

} // namespace mmb

#endif // Include guard MMB_UTILS_LOGS_PRINTER_INL