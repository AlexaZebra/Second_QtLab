//#include <QCoreApplication>
#include"Unit.h"
#include"ClassUnit.h"
#include"MethodUnit.h"
#include"PrintOperatorUnit.h"
#include"cpp/CPP_Factory.h"
#include"csharp/CSHARP_Factory.h"

/*std::string generateProgram() {
     ClassUnit myClass( "MyClass" );
     myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
     );

     myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
     );

     myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL |
        MethodUnit::CONST ),
        ClassUnit::PUBLIC
     );

     auto method = std::make_shared< MethodUnit >( "testFunc4", "void",
        MethodUnit::STATIC );

     method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
     myClass.add( method, ClassUnit::PROTECTED );

     return myClass.compile();
}
*/

std::string generateProgram(const std::shared_ptr< AbstractFactory >& factory) {
    auto myClass = factory->CreateClassUnit("MyClass");
    myClass->add(factory->CreateMethodUnit("testFunc1", "void", 0),ClassUnit::PUBLIC);
    myClass->add(factory->CreateMethodUnit("testFunc2", "void", MethodUnit::STATIC),ClassUnit::PRIVATE);
    myClass->add(factory->CreateMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST),ClassUnit::PUBLIC);

    std::shared_ptr< MethodUnit > method = factory->CreateMethodUnit( "testFunc4", "void", MethodUnit::STATIC );
    method->add(factory->CreatePrintOperatorUnit( R"(Hello, world!\n)" ));
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}

int main() {
    //std::cout << generateProgram(std::make_shared< CPP_AbstractFactorty >()) << std::endl;
    std::cout << generateProgram(std::make_shared< CSHARP_AbstractFactorty >()) << std::endl;

    return 0;
}
