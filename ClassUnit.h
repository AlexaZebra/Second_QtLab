#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include<vector>
#include"Unit.h"

// создание юнита "класс"
class ClassUnit : public Unit
{
public:
     enum AccessModifier {
         PUBLIC,
         PROTECTED,
         PRIVATE,
         INTERNAL,
         PROTECTED_INTERNAL,
         PRIVATE_PROTECTED
     };
    static const std::vector< std::string > ACCESS_MODIFIERS;

public:
    ClassUnit( const std::string& name ) : _name( name ) { // конструктор инициализирует имя класса
        _fields.resize( ACCESS_MODIFIERS.size() );                  // и вектор модификаторов класса
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override { // функция добавления юнита  вектор модификаторов класса
        int accessModifier = PRIVATE;                                       // по умолчанию модификатор private
        if( flags < ACCESS_MODIFIERS.size() ) {                             // если был передан другой из существующих модификаторов,
            accessModifier = flags;                                         // то присваиваем его
        }
        _fields[ accessModifier ].push_back( unit );                        // добавляем наш юнит в нужную область доступа
    }

protected:
    std::string _name;                                   // имя класса
    using Fields = std::vector< std::shared_ptr<Unit> >;
    std::vector< Fields > _fields;                       // модификаторы класса (вектор векторов)
};
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private",
                                                                 "internal", "protected_internal", "private_protected" };
#endif // CLASSUNIT_H
