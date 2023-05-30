#ifndef CSHARP_PRINTOPERATORUNIT_H
#define CSHARP_PRINTOPERATORUNIT_H

#include"PrintOperatorUnit.h"

class CSHARP_PrintOperatorUnit : public PrintOperatorUnit
{
public:
    CSHARP_PrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text){}

    std::string compile( unsigned int level = 0 ) const override{                   // генерация на языке C# вывода в консоль нужного текста
        return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
    }

};

#endif // CSHARP_PRINTOPERATORUNIT_H
