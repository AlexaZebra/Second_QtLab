#ifndef FACTORY_H
#define FACTORY_H

#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

// Абстрактная фабрика с дефолтным конструктором и методами, возвращающие smart pointers (shared_ptr) на ClassUnit, MethodUnit, PrintUnit
class AbstractFactory
{
public:
    // Возвращает smart ptr ClassUnit
    // flags в параметрах, потому что C# и Java имеют модификаторы доступа к классу. C++ игнорирует его.
    virtual std::shared_ptr<ClassUnit> CreateClassUnit(const std::string& name, Unit::Flags flags = 0) const = 0;

    // Возвращает smart ptr MethodUnit
    virtual std::shared_ptr<MethodUnit> CreateMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0;

    // Возвращает smart ptr PrintUnit
    virtual std::shared_ptr<PrintOperatorUnit> CreatePrintOperatorUnit(const std::string& text) const = 0;

    // деструктор виртуальнй для правильного наследования (очищения памяти и вызов деструктора, исключение непредвиденных обстоятельств)
    virtual ~AbstractFactory() = default;
};
#endif // FACTORY_H
