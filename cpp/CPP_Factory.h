#ifndef CPP_FACTORY_H
#define CPP_FACTORY_H

#include"CPP_ClassUnit.h"
#include"CPP_MethodUnit.h"
#include"CPP_PrintOperatorUnit.h"
#include"AbstractFactory.h"

// Абстрактная фабрика для языка C++
class CPP_AbstractFactorty : public AbstractFactory
{
public:
    // cоздаёт smart ptr CPP_ClassUnit и возвращает его
    std::shared_ptr<ClassUnit> CreateClassUnit(const std::string& name) const override{
        return std::make_shared<CPP_ClassUnit>(name);
    };

    // по аналогии
    std::shared_ptr<MethodUnit> CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override{
        return std::make_shared<CPP_MethodUnit>(name, returnType, flags);
    };

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperatorUnit(const std::string& text) const override{
        return std::make_shared<CPP_PrintOperatorUnit>(text);
    };

    ~CPP_AbstractFactorty() override = default;
};

#endif // CPP_FACTORY_H
