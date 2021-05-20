/*
** EPITECH PROJECT, 2021
** cpp_poolday16
** File description:
** BF_Translator
*/

#include "BF_Translator.hpp"

BF_Translator::BF_Translator()
{
    _methods['+'] = "++*mem;";
    _methods['-'] = "--*mem;";
    _methods['>'] = "++mem;";
    _methods['<'] = "--mem;";
    _methods['.'] = "putchar(*mem);";
    _methods[','] = "*mem=getchar();";
    _methods['['] = "while (*mem) {";
    _methods[']'] = "}";
}

int BF_Translator::translate(const std::string &in, const std::string &out)
{
    std::fstream fileIn(in);
    std::fstream fileOut(out, std::fstream::out);

    fileOut << "#include <stdio.h>\n#include <stdlib.h>\nint main(void) {\nchar *mem = (char *)calloc(60000, 1);\n";
    char content = fileIn.get();
    while (fileIn.good()) {
        if (this->_methods[content] == "" && !isspace(content))
            return (1);
        fileOut << _methods[content] << std::endl;
        content = fileIn.get();
    }
    fileOut << "}" << std::endl;
    fileOut.close();
    return (0);
}

BF_Translator::~BF_Translator()
{
}
