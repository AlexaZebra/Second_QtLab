#include"Unit.h"
#include"ClassUnit.h"
#include"MethodUnit.h"
#include"PrintOperatorUnit.h"
#include"cpp/CPP_Factory.h"
#include"csharp/CSHARP_Factory.h"
#include"java/JAVA_Factory.h"

std::string generateProgram(std::shared_ptr<AbstractFactory>& factory){
    auto myClass = factory->CreateClassUnit("MyClass");
    myClass->add(factory->CreateMethodUnit("testFunc1", "void", 0),ClassUnit::PUBLIC);
    myClass->add(factory->CreateMethodUnit("testFunc2", "void", MethodUnit::STATIC),ClassUnit::PRIVATE);
    myClass->add(factory->CreateMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST),ClassUnit::PUBLIC);

    std::shared_ptr< MethodUnit > method = factory->CreateMethodUnit( "testFunc4", "void", MethodUnit::STATIC);
    method->add(factory->CreatePrintOperatorUnit( R"(Hello, world!)" ));
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}

void print(const std::string result, std::string name) {
    std::cout<< "Language " << name << '\n'<< result << std::endl;
    getchar();
}

int main() {
    std::string lang;

    for (int i = 0; i < 3; ++i){
        std::shared_ptr<AbstractFactory> factory;

        switch (i){
        case 0:
            factory = std::make_shared<CPP_AbstractFactory>();
            lang = "C++";
            break;

        case 1:
            factory = std::make_shared<CSHARP_AbstractFactory>();
            lang = "C#";
            break;

        case 2:
            factory = std::make_shared<JAVA_AbstractFactory>();
            lang = "Java";
            break;
        }

        print(generateProgram(factory), lang);
    }
    return 0;
}
