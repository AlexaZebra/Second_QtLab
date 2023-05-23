#ifndef CPP_METHODUNIT_H
#define CPP_METHODUNIT_H

#include"MethodUnit.h"

class CPP_MethodUnit : public MethodUnit
{
public:
    CPP_MethodUnit(const std::string& name, const std::string& returnType, const Flags& flags):
        MethodUnit( name, returnType, flags ) {};

    std::string compile(const unsigned int level = 0) const {
        std::string result = generateShift(level);      // производим нужные сдвиги
        if (m_flags & STATIC)                           // если бит флага установлен на STATIC,
            result += "static ";                        // то метод статичный
        else if (m_flags & VIRTUAL)                     // если бит VIRTUAL,
            result += "virtual ";                       // то метод виртуальный

        result += m_returnType + ' ' + m_name + "()";   // добавляем возвращаемый тип и имя метода

        if (m_flags & CONST)                            // если имеет спецификатор CONST,
            result += " const";                         // то добавим const
        result += " {\n";

        for (const auto& it : m_body)                   // производим генерацию с нужными отступами
            result += it->compile(level + 1);

        result += generateShift(level) + "}\n";
        return result;                                  // возвращаем результат
    };
};

#endif // CPP_METHODUNIT_H
