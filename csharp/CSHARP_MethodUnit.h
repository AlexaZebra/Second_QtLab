#ifndef CSHARP_METHODUNIT_H
#define CSHARP_METHODUNIT_H

#include"MethodUnit.h"

class CSHARP_MethodUnit: public MethodUnit
{
public:
    CSHARP_MethodUnit(const std::string& name, const std::string& returnType, const Flags& flags):
        MethodUnit( name, returnType, flags ) {};

    std::string compile(const unsigned int level = 0) const override{
        std::string result = "";

        if(_flags & PUBLIC)
            result += "public ";
        else if(_flags & PROTECTED)
            result += "protected ";
        else
            result += "private ";

        if (_flags & STATIC)                            // если бит флага установлен на STATIC,
            result += "static ";                        // то метод статичный
        else if (_flags & VIRTUAL)                      // иначе, если бит VIRTUAL,
            result += "virtual ";                       // то метод виртуальный

        result += _returnType + ' ' + _name + "()";     // добавляем возвращаемый тип и имя метода
                                                        // const для метода нет в C#
        result += " {\n";                               // открытая скобка определения метода
        for (const auto& it : _body)                    // производим генерацию тела метода с нужными отступами
            result += it->compile(level + 1);

        result += generateShift(level) + "}\n";         // закрытая скобка метода
        return result;                                  // возвращаем результат
    };
};

#endif // CSHARP_METHODUNIT_H
