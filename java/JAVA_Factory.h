#ifndef JAVA_FACTORY_H
#define JAVA_FACTORY_H

#include"JAVA_ClassUnit.h"
#include"JAVA_MethodUnit.h"
#include"JAVA_PrintOperatorUnit.h"
#include"AbstractFactory.h"

// Абстрактная фабрика для языка C++
class JAVA_AbstractFactory : public AbstractFactory
{
public:
    // cоздаёт smart ptr CPP_ClassUnit и возвращает его
    std::shared_ptr<ClassUnit> CreateClassUnit(const std::string& name) const override{
        return std::make_shared<JAVA_ClassUnit>(name);
    };

    // по аналогии
    std::shared_ptr<MethodUnit> CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override{
        return std::make_shared<JAVA_MethodUnit>(name, returnType, flags);
    };

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperatorUnit(const std::string& text) const override{
        return std::make_shared<JAVA_PrintOperatorUnit>(text);
    };

    ~JAVA_AbstractFactory() override = default;
};

#endif // JAVA_FACTORY_H
