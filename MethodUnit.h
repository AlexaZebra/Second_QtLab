#ifndef METHODUNIT_H
#define METHODUNIT_H
#include"Unit.h"
#include"ClassUnit.h"

// создание юнита "метод"
class MethodUnit : public Unit {
public:
     enum Modifier {
         STATIC = 1,
         CONST = 1 << 1,
         VIRTUAL = 1 << 2,
         FINAL = 1 << 3,
         ABSTRACT = 1 << 4,
         PUBLIC = 1 << 5,
         PROTECTED = 1 << 6,
         PRIVATE  = 1 << 7
     };
public:
     MethodUnit( const std::string& name, const std::string& returnType, Flags flags):
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { } // конструктор принимает имя, возвращаемый тип и флаги модификаторов

     void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {// добавляет юнит в тело метода
        m_body.push_back( unit );
     }
     //virtual std::string compile( unsigned int level = 0 ) const = 0;
     /*std::string compile( unsigned int level = 0 ) const {
         std::string result = generateShift( level );

         if( m_flags & STATIC ) {
            result += "static ";
         }
         else if( m_flags & VIRTUAL ) {
            result += "virtual ";
         }

         result += m_returnType + " ";
         result += m_name + "()";

         if( m_flags & CONST ) {
            result += " const";
         }

         result += " {\n";

         for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
         }

         result += generateShift( level ) + "}\n";
         return result;
     }*/
protected:
     std::string m_name;                            // название метода
     std::string m_returnType;                      // возвращаемый тип метода
     Flags m_flags;                                 // модификаторы метода
     std::vector< std::shared_ptr< Unit > > m_body; // тело метода
};
#endif // METHODUNIT_H
