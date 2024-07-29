#ifndef IOC_H
#define IOC_H


#include <functional>
#include <iostream>
#include <memory>
#include <map>
#include <string>
using namespace std;


class IOC
{
    static int s_nextTypeId;
    template<typename T>
    static int GetTypeID()
    {
        static int typeId = s_nextTypeId++;
        return typeId;
    }

public:
    //Создание typeid для типа
    /*
     * В предлагаемой реализации контейнера IOC  есть статическая целочисленная переменная,
     * указывающая идентификатор следующего типа, который будет выделен,
     * и экземпляр статической локальной переменной для каждого типа,
     * доступ к которому можно получить, вызвав метод GetTypeID.
    */

    /*
     * Получение экземпляров объекта
     * Теперь, когда у нас есть идентификатор типа,
     * мы должны иметь возможность хранить какой-то фабричный объект,
     * чтобы представить тот факт, что мы не знаем, как создать этот объект.
     * Поскольку я хочу хранить все фабрики в одной коллекции,
     * я выбираю абстрактный базовый класс, от которого будут производными фабрики,
     * и реализацию, которая фиксирует функтор для последующего вызова.
     * Для краткости я использовал std::map для хранения фабрик, однако
     * вы можете рассмотреть и другие варианты для повышения эффективности.
     */

// Абстрактный базовый класс для всех фабрик,
//которые предоставляют способы создания объектов
    class FactoryRoot
    {
    public:
        virtual ~FactoryRoot() {}
    };

// Коллекция фабрик для определенных типов объектов в формате: ключ - значение
    std::map<int, std::shared_ptr<FactoryRoot>> m_factories;

// Фабрика определенного типа T
    template<typename T>
    class CFactory : public FactoryRoot
    {
    //Объявление переменной m_functor типа function, которая представляет функциональный объект,
    //способный создавать и возвращать объект типа T. Этот объект будет храниться внутри фабрики.
        std::function<std::shared_ptr<T>()> m_functor;

    public:
        ~CFactory() {}

        CFactory(std::function<std::shared_ptr<T>()> functor)
            : m_functor(functor)
        {}

        std::shared_ptr<T> GetObject() {
            return m_functor();
        }
    };

//Получить экземпляр объекта из контейнера
    template<typename T>
    std::shared_ptr<T> GetObject()
    {
        // Получаем typeId фабрики
        auto typeId = GetTypeID<T>();
        // Получаем необходимую нам фабрику
        auto factoryBase = m_factories[typeId];
        // Приводим указатель к типу конкретной фабрики
        auto factory = std::static_pointer_cast<CFactory<T>>(factoryBase);
        // Возвращаем объект созданный с использованием заданного функтора фабрики
        return factory->GetObject();
    }

//Регистрация экземпляров

//Самая простая реализация - зарегистрировать функтор
//Регистрируем функтор в IoC_контейнере для создания объектов типа TInterface
    template<typename TInterface, typename... TS>
    void RegisterFunctor(
        std::function<std::shared_ptr<TInterface>(std::shared_ptr<TS>... ts)> functor) {
        m_factories[GetTypeID<TInterface>()] = std::make_shared<CFactory<TInterface>>(
                [ = ] { return functor(GetObject<TS>()...); });
    }

//Регистрация одного экземпляра объекта
    template<typename TInterface>
    void RegisterInstance(std::shared_ptr<TInterface> t) {
        m_factories[GetTypeID<TInterface>()] = std::make_shared<CFactory<TInterface>>(
                [ = ] { return t; });
    }

//Подаем указатель на функцию
    template<typename TInterface, typename... TS>
    void RegisterFunctor(std::shared_ptr<TInterface> (*functor)(std::shared_ptr<TS>... ts)) {
        RegisterFunctor(
            std::function<std::shared_ptr<TInterface>(std::shared_ptr<TS>... ts)>(functor));
    }

//Фабрика, которая будет вызывать конструктор, для каждого экземпляра
//Регистрация фабрики для создания объектов, где TInterface - интерфейс,
//TConcrete  - конкретная реализация интерфейса, TArguments - набор параметор передаваемых в конструктор TConcrete
    template<typename TInterface, typename TConcrete, typename... TArguments>
    void RegisterFactory() {
        RegisterFunctor(
            std::function<std::shared_ptr<TInterface>(std::shared_ptr<TArguments>... ts)>(
        [](std::shared_ptr<TArguments>... arguments) -> std::shared_ptr<TInterface> {
            return std::make_shared<TConcrete>(
                std::forward<std::shared_ptr<TArguments>>(arguments)...);
        }));
    }

//Фабрика, которая будет возвращать один экземпляр
    template<typename TInterface, typename TConcrete, typename... TArguments>
    void RegisterInstance() {
        RegisterInstance<TInterface>(std::make_shared<TConcrete>(GetObject<TArguments>()...));
    }
};

#endif // IOC_H
