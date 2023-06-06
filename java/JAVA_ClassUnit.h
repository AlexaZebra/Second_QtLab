#ifndef JAVA_CLASSUNIT_H
#define JAVA_CLASSUNIT_H
#include"ClassUnit.h"

class JAVA_ClassUnit : public ClassUnit {
public:
  static const std::vector <std::string> ACCESS_MODIFIERS;    // Модификаторы доступа
public:
    JAVA_ClassUnit(const std::string& name): ClassUnit(name){};

    std::string compile(unsigned int level = 0) const override{
        std::string result = generateShift(level) + "class " + _name + " {\n";  // производим генерацию класса
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ){                  // проходимся по всем полям модификаторов

            if (_fields[i].empty())                                             // если в поле модификатора нет юнитов,
                continue;                                                       // то переходим на следующую итерацию

            for (const auto& it : _fields[i])                                   // проходимся по всем юнитам в поле модификатора
                result += generateShift(level+1) + ACCESS_MODIFIERS[i] + " " + it -> compile(level+1);// и генерируем можификаторы и юниты,
                                                                                //потом добавляем их

            result += '\n';
        }
        result += generateShift(level) + "};\n";                                // добавляем нужные отступы
        return result;                                                          // возвращаем результат
    }
};
const std::vector< std::string > JAVA_ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private"};
#endif // JAVA_CLASSUNIT_H
