#include <iostream>
#include <string>
#include <vector>

std::string SAMPLE_CODE = "++++++++[>+>++>+++>++++>+++++>++++++>+++++++>++++++++>+++++++++>++++++++++>+++++++++++>++++++++++++>+++++++++++++>++++++++++++++>+++++++++++++++>++++++++++++++++<<<<<<<<<<<<<<<<-]>>>>>>>>>++.--<<<<<<<<<>>>>>>>>>>>>>---.+++<<<<<<<<<<<<<>>>>>>>>>>>>>>--.++<<<<<<<<<<<<<<>>>>>>>>>>>>>>--.++<<<<<<<<<<<<<<>>>>>>>>>>>>>>>+.-<<<<<<<<<<<<<<<>>>>.<<<<>>>>>>>>>>---.+++<<<<<<<<<<>>>>>>>>>>>>>---.+++<<<<<<<<<<<<<>>>>>>>>>>>>>+.-<<<<<<<<<<<<<>>>>.<<<<>>>>>>>>>>>>++.--<<<<<<<<<<<<>>>>>>>>>>>>>---.+++<<<<<<<<<<<<<>>>>>>>>>>>>>>+++.---<<<<<<<<<<<<<<>>>>>>>>>>>>>>>----.++++<<<<<<<<<<<<<<<>>>>.<<<<>>>>>>>>>++.--<<<<<<<<<>>>>>>>>>>>>>---.+++<<<<<<<<<<<<<>>>>>>>>>>>>>>--.++<<<<<<<<<<<<<<>>>>>>>>>>>>>>--.++<<<<<<<<<<<<<<>>>>>>>>>>>>>>>+.-<<<<<<<<<<<<<<<.";

int execute(std::string input)
{
    std::vector<char> memory(30001);
    const char *s = input.c_str();
    int ptr = 0;

    while (*s)
    {
        if (*s == '>')
            ptr++;
        if (*s == '<')
            ptr--;
        if (*s == '+')
            memory[ptr]++;
        if (*s == '-')
            memory[ptr]--;
        if (*s == '.')
            putchar(memory[ptr]);
        if (*s == ',')
            memory[ptr] = getchar();
        if (*s == '[')
        {
            if (memory[ptr] == 0)
            {
                int brackets = 1;
                while (*s != ']' || brackets > 0)
                {
                    s++;
                    if (*s == '[')
                        brackets++;
                    else if (*s == ']')
                        brackets--;
                }
            }
        }
        if (*s == ']')
        {
            if (memory[ptr] != 0)
            {
                int brackets = 1;
                while (*s != '[' || brackets > 0)
                {
                    s--;
                    if (*s == ']')
                        brackets++;
                    else if (*s == '[')
                        brackets--;
                }
            }
        }
        s++;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    for (;;)
    {
        std::cout << std::endl << "bfuck> ";
        std::string input;
        getline(std::cin, input);
        if (input == "sample")
        {
            input = SAMPLE_CODE;
            std::cout << SAMPLE_CODE << std::endl;
        }
        execute(input);
    }
    return 0;
}
