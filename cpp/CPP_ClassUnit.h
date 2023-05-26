#ifndef CPP_CLASSUNIT_H
#define CPP_CLASSUNIT_H
#include"ClassUnit.h"

class CPP_ClassUnit : public ClassUnit {
public:
  static const std::vector <std::string> ACCESS_MODIFIERS;    // Модификаторы доступа для С++

public:
    CPP_ClassUnit(const std::string& name): ClassUnit(name){};

    std::string compile(unsigned int level = 0) const override{
        std::string result = generateShift(level) + "class " + m_name + " {\n"; // производим генерацию класса
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ){                  // проходимся по всем полям модификаторов

            if (m_fields[i].empty())                                            // если в поле модификатора нет юнитов,
                continue;                                                       // то переходим на следующую итерацию

            result += ACCESS_MODIFIERS[i] + ":\n";                              // иначе добавляем к result имя модификатора

            for (const auto& it : m_fields[i])                                  // проходимся по всем юнитам в поле модификатора
                result += it->compile(level + 1);                               // и генерируем модификаторы, потом добавляем их

            result += '\n';
        }
        result += generateShift(level) + "};\n";                                // добавляем нужные отступы
        return result;                                                          // возвращаем результат
    }
};
const std::vector< std::string > CPP_ClassUnit::ACCESS_MODIFIERS = { "public",
"protected", "private" };
#endif // CPP_CLASSUNIT_H
