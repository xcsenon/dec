#include <iostream>

// Component
class Component {
public:
    virtual void operation() const = 0;
};

// ConcreteComponent
class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

// Decorator
class Decorator : public Component {
private:
    Component* component;

public:
    Decorator(Component* component) : component(component) {}

    void operation() const override {
        component->operation();
    }
};

// ConcreteDecoratorA
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    void operation() const override {
        Decorator::operation();
        addedBehaviorA();
    }

    void addedBehaviorA() const {
        std::cout << "ConcreteDecoratorA added behavior" << std::endl;
    }
};

// ConcreteDecoratorB
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    void operation() const override {
        Decorator::operation();
        addedBehaviorB();
    }

    void addedBehaviorB() const {
        std::cout << "ConcreteDecoratorB added behavior" << std::endl;
    }
};

int main() {
    ConcreteComponent concreteComponent;
    ConcreteDecoratorA decoratorA(&concreteComponent);
    ConcreteDecoratorB decoratorB(&decoratorA);

    decoratorB.operation();

    return 0;
}
