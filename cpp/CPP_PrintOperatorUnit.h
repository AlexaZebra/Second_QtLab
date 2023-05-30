#ifndef CPP_PRINTOPERATORUNIT_H
#define CPP_PRINTOPERATORUNIT_H
#include"PrintOperatorUnit.h"

class CPP_PrintOperatorUnit : public PrintOperatorUnit
{
public:
    CPP_PrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text){}

    std::string compile( unsigned int level = 0 ) const override{                   // генерация на языке C++ вывода в консоль нужного текста
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }

};
#endif // CPP_PRINTOPERATORUNIT_H
