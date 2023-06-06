#ifndef CSHARP_CLASSUNIT_H
#define CSHARP_CLASSUNIT_H
#include"ClassUnit.h"

class CSHARP_ClassUnit: public ClassUnit {
public:
  static const std::vector <std::string> ACCESS_MODIFIERS;    // Модификаторы доступа
public:
    CSHARP_ClassUnit(const std::string& name): ClassUnit(name){};

    std::string compile(unsigned int level = 0) const override{
        std::string result = generateShift(level) + "class " + _name + " {\n";  // производим генерацию класса
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ){                  // проходимся по всем полям модификаторов

            if (_fields[i].empty())                                             // если в поле модификатора нет юнитов,
                continue;                                                       // то переходим на следующую итерацию
            result += ACCESS_MODIFIERS[i] + " ";                                // иначе добавляем к result имя модификатора

            for (const auto& it : _fields[i])                                   // проходимся по всем юнитам в поле модификатора
                result += it->compile(level + 1);                               // и генерируем юниты, потом добавляем их

            result += '\n';
        }
        result += generateShift(level) + "};\n";                                // добавляем нужные отступы
        return result;                                                          // возвращаем результат
    }
};
const std::vector< std::string > CSHARP_ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private",
                                                                 "internal", "protected_internal", "private_protected" };
#endif // CSHARP_CLASSUNIT_H
