#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include<vector>
#include"Unit.h"

// создание юнита "класс"
class ClassUnit : public Unit
{
public:
     enum AccessModifier {
         PUBLIC,             // C# C++ JAVA
         PROTECTED,          // C# C++ JAVA
         PRIVATE,            // C# C++ JAVA
         INTERNAL,           // C#
         PROTECTED_INTERNAL, // C#
         PRIVATE_PROTECTED,  // C#
     };
    static const std::vector< std::string > ACCESS_MODIFIERS;

public:
    explicit ClassUnit( const std::string& name ) : m_name( name ) { // конструктор инициализирует имя класса
        m_fields.resize( ACCESS_MODIFIERS.size() );                  // и вектор модификаторов класса
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) { // функция добавления юнита в вектор модификаторов класса
        int accessModifier = PRIVATE;                              // по умолчанию модификатор private (если вдруг передали ошибочное значение)
        if( flags < ACCESS_MODIFIERS.size() ) {                    // если был передан другой из существующих модификаторов,
            accessModifier = flags;                                // то присваиваем его
        }
        m_fields[ accessModifier ].push_back( unit );              // добавляем наш юнит в нужную область доступа
    }

       /*std::string result = generateShift( level ) + "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {continue;}

            result += ACCESS_MODIFIERS[ i ] + ":\n";

            for( const auto& f : m_fields[ i ] ) {
                result += f->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    } */
protected:
    std::string m_name;                                   // имя класса
    using Fields = std::vector< std::shared_ptr<Unit> >;
    std::vector< Fields > m_fields;                       // модификаторы класса (вектор векторов)
};
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public",
"protected", "private", "internal", "protected_internal", "private_protected" };
#endif // CLASSUNIT_H
