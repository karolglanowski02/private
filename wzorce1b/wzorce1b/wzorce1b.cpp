#include <iostream>
#include <string>

// Product class
class Pizza {
public:
    void setDough(const std::string& dough)
    {
        this->dough = dough;
    }

    void setSauce(const std::string& sauce)
    {
        this->sauce = sauce;
    }

    void setTopping(const std::string& topping)
    {
        this->topping = topping;
    }

    void displayPizza() const
    {
        std::cout << "Pizza with Dough: " << dough
            << ", Sauce: " << sauce
            << ", Topping: " << topping << std::endl;
    }

private:
    std::string dough;
    std::string sauce;
    std::string topping;
};

// Abstract builder class
class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getPizza() const = 0;
};

// Concrete builder for a specific type of pizza - Hawaiian Pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override
    {
        pizza.setDough("Pan Dough");
    }

    void buildSauce() override
    {
        pizza.setSauce("Hawaiian Sauce");
    }

    void buildTopping() override
    {
        pizza.setTopping("Ham and Pineapple");
    }

    Pizza getPizza() const override { return pizza; }

private:
    Pizza pizza;
};

// Concrete builder for another type of pizza - Spicy Pizza
class SpicyPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override
    {
        pizza.setDough("Thin Dough");
    }

    void buildSauce() override
    {
        pizza.setSauce("Spicy Tomato Sauce");
    }

    void buildTopping() override
    {
        pizza.setTopping("Pepperoni and Jalapenos");
    }

    Pizza getPizza() const override { return pizza; }

private:
    Pizza pizza;
};

// Concrete builder for a new type of pizza - Glanowski Pizza
class GlanowskiPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override
    {
        pizza.setDough("Whole Wheat Dough");
    }

    void buildSauce() override
    {
        pizza.setSauce("Garlic Parmesan Sauce");
    }

    void buildTopping() override
    {
        pizza.setTopping("Spinach and Feta Cheese");
    }

    Pizza getPizza() const override { return pizza; }

private:
    Pizza pizza;
};

// Director class that orchestrates the construction
class Cook {
public:
    void makePizza(PizzaBuilder& builder)
    {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

int main()
{
    Cook cook;

    HawaiianPizzaBuilder hawaiianBuilder;
    cook.makePizza(hawaiianBuilder);
    Pizza hawaiianPizza = hawaiianBuilder.getPizza();
    std::cout << "Hawaiian Pizza Configuration:" << std::endl;
    hawaiianPizza.displayPizza();

    std::cout << "\n";

    SpicyPizzaBuilder spicyBuilder;
    cook.makePizza(spicyBuilder);
    Pizza spicyPizza = spicyBuilder.getPizza();
    std::cout << "\nSpicy Pizza Configuration:" << std::endl;
    spicyPizza.displayPizza();

    std::cout << "\n";

    GlanowskiPizzaBuilder glanowskiBuilder;
    cook.makePizza(glanowskiBuilder);
    Pizza glanowskiPizza = glanowskiBuilder.getPizza();
    std::cout << "\nGlanowski Pizza Configuration:" << std::endl;
    glanowskiPizza.displayPizza();

    return 0;
}
