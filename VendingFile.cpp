#include <iostream>
#include <string>
#include <vector>

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister() : cashOnHand(500) {}

    cashRegister(int initialAmount) : cashOnHand(initialAmount) {}

    int getCurrentBalance() {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int itemCost;

public:
    dispenserType() : numberOfItems(50), itemCost(0) {}

    dispenserType(int items, int cost) : numberOfItems(items), itemCost(cost) {}

    int getNoOfItems() {
        return numberOfItems;
    }

    int getCost() {
        return itemCost;
    }

    void makeSale() {
        if (numberOfItems > 0) {
            numberOfItems--;
        }
        else {
            std::cout << "Диспенсер пуст!" << std::endl;
        }
    }
};

int main() {

    setlocale(LC_ALL, "russian");
    cashRegister register;
    
    dispenserType candy(100, 50);
    dispenserType chips(100, 65);
    dispenserType gum(75, 45);
    dispenserType cookies(50, 85);
        
    std::cout << "Добро пожаловать! Вот наше меню продуктов:\n";
    std::cout << "1. Конфеты - $1.00\n";
    std::cout << "2. Чипсы - $1.50\n";
    std::cout << "3. Жвачка - $0.75\n";
    std::cout << "4. Печенье - $2.00\n";

    int choice;
    
    std::cout << "Выберите продукт (1-4): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= 4) {
        int selectedCost = 0;
        std::string productName;

        switch (choice) {
        case 1:
            selectedCost = 1.00;
            productName = "Конфеты";
            break;
        case 2:
            selectedCost = 1.50;
            productName = "Чипсы";
            break;
        case 3:
            selectedCost = 0.75;
            productName = "Жвачка";
            break;
        case 4:
            selectedCost = 2.00;
            productName = "Печенье";
            break;
        }

        std::cout << "Вы выбрали " << productName << " за $" << selectedCost << std::endl;
        std::cout << "Введите деньги: ";

        float money;
        std::cin >> money;

        if (money >= selectedCost) {
           // register.acceptAmount(selectedCost);
            //candyDispenser.makeSale();
            std::cout << "Спасибо за покупку! Получите ваш " << productName << std::endl;
        }
        else {
            std::cout << "Недостаточно средств. Попробуйте снова." << std::endl;
        }
    }
    else {
        std::cout << "Неверный выбор продукта." << std::endl;
    }

    return 0;
}
