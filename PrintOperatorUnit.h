#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include"Unit.h"
#include"ClassUnit.h"

// вывод юнита
class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : _text( text ) { }

protected:
    std::string _text;
};
#endif // PRINTOPERATORUNIT_H
