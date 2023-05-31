#ifndef JAVA_PRINTOPERATORUNIT_H
#define JAVA_PRINTOPERATORUNIT_H
#include"PrintOperatorUnit.h"

class JAVA_PrintOperatorUnit : public PrintOperatorUnit
{
public:
    JAVA_PrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text){}

    std::string compile( unsigned int level = 0 ) const override{                   // генерация на языке Java вывода в консоль нужного текста
        return generateShift(level) + "System.out.println( \"" + _text + "\" );\n";
    }

};
#endif // JAVA_PRINTOPERATORUNIT_H
