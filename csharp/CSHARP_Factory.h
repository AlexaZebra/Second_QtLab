#ifndef CSHARP_FACTORY_H
#define CSHARP_FACTORY_H

#include "AbstractFactory.h"
#include "csharp/CSHARP_ClassUnit.h"
#include "csharp/CSHARP_MethodUnit.h"
#include "csharp/CSHARP_PrintOperatorUnit.h"

// Абстрактная фабрика для языка C#
class CSHARP_AbstractFactorty : public AbstractFactory
{
public:
    // cоздаёт smart ptr CSHARP_ClassUnit и возвращает его
    std::shared_ptr<ClassUnit> CreateClassUnit(const std::string& name) const override{
        return std::make_shared<CSHARP_ClassUnit>(name);
    };

    // по аналогии
    std::shared_ptr<MethodUnit> CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override{
        return std::make_shared<CSHARP_MethodUnit>(name, returnType, flags);
    };

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperatorUnit(const std::string& text) const override{
        return std::make_shared<CSHARP_PrintOperatorUnit>(text);
    };

    ~CSHARP_AbstractFactorty() override = default;
};

#endif // CSHARP_FACTORY_H
