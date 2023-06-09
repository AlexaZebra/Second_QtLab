#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

// Абстрактная фабрика с методами, возвращающие smart pointers (shared_ptr) на ClassUnit, MethodUnit, PrintUnit
class AbstractFactory
{
public:
    // возвращает smart ptr ClassUnit
    virtual std::shared_ptr<ClassUnit> CreateClassUnit(const std::string& name) const = 0;

    // возвращает smart ptr MethodUnit
    virtual std::shared_ptr<MethodUnit> CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0;

    // возвращает smart ptr PrintUnit
    virtual std::shared_ptr<PrintOperatorUnit> CreatePrintOperatorUnit(const std::string& text) const = 0;

    // деструктор виртуальный для правильного наследования (очищения памяти и вызов деструктора, исключение непредвиденных обстоятельств)
    virtual ~AbstractFactory() = default;
};
#endif // ABSTRACTFACTORY_H
