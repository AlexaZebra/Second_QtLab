#ifndef CPP_CLASSUNIT_H
#define CPP_CLASSUNIT_H
#include"ClassUnit.h"

class CPP_ClassUnit : public ClassUnit {
    CPP_ClassUnit(const std::string& name) : ClassUnit(name){};

    std::string compile(unsigned int level = 0) const{
        std::string result = generateShift(level) + "class " + m_name + " {\n"; // производим генерацию класса
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ){                  // проходимся по всем полям модификаторов

            if (m_fields[i].empty())                                            // если в поле модификатора ничего нет,
                continue;                                                       // то переходим на следующую итерацию

            result += ACCESS_MODIFIERS[i] + ":\n";                              // добавляем к result имя модификатора

            for (const auto& it : m_fields[i])                                  // проходимся по всем юнитам в поле модификатора
                result += it->compile(level + 1);                               // и генерируем модификаторы, потом добавляем их

            result += '\n';
        }
        result += generateShift(level) + "};\n";                                // производим нужную корректировку
        return result;                                                          // возвращаем результат
    }
};

#endif // CPP_CLASSUNIT_H
