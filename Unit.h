#ifndef UNIT_H
#define UNIT_H
#include<iostream>
#include<memory>

/*
 * Основной абстрактный класс, от которого наследуются ClassUnit, MethodUnit, PrintUnit
 * Имеет вирутальные функции add(добавление юнита, области класса, метода или вывода)
 * compile(формирование юнита в виде текста и возврат строки)
*/

class Unit {
public:
    using Flags = unsigned int;

public:
     virtual ~Unit() = default;
     virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
     }
     virtual std::string compile( unsigned int level = 0 ) const = 0;

protected:
    virtual std::string generateShift( unsigned int level ) const
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H
