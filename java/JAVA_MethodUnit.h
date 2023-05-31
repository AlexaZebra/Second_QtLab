#ifndef JAVA_METHODUNIT_H
#define JAVA_METHODUNIT_H
#include"MethodUnit.h"

class JAVA_MethodUnit : public MethodUnit
{
public:
    JAVA_MethodUnit(const std::string& name, const std::string& returnType, const Flags& flags):
        MethodUnit( name, returnType, flags ) {};

    std::string compile(const unsigned int level = 0) const override{
        std::string result = "";

        if(m_flags & PUBLIC)
            result += "public ";
        else if(m_flags & PROTECTED)
            result += "protected ";
        else
            result += "private ";


        if (m_flags & STATIC)                           // если бит флага установлен на STATIC,
            result += "static ";                        // то метод статичный
        else if (m_flags & FINAL)                       // final предотвращает метод от изменений в подклассе.
            result += "final ";
        else if (m_flags & ABSTRACT)                    // Методы abstract никогда не могут быть final
            result += "abstract ";

        result += m_returnType + ' ' + m_name + "()";   // добавляем возвращаемый тип и имя метода

        result += " {\n";                               // скобка метода

        for (const auto& it : m_body)                   // производим генерацию с нужными отступами
            result += it->compile(level + 1);

        result += generateShift(level) + "}\n";         // закрытая скобка метода
        return result;                                  // возвращаем результат
    };
};
#endif // JAVA_METHODUNIT_H
