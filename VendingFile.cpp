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
            std::cout << "��������� ����!" << std::endl;
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
        
    std::cout << "����� ����������! ��� ���� ���� ���������:\n";
    std::cout << "1. ������� - $1.00\n";
    std::cout << "2. ����� - $1.50\n";
    std::cout << "3. ������ - $0.75\n";
    std::cout << "4. ������� - $2.00\n";

    int choice;
    
    std::cout << "�������� ������� (1-4): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= 4) {
        int selectedCost = 0;
        std::string productName;

        switch (choice) {
        case 1:
            selectedCost = 1.00;
            productName = "�������";
            break;
        case 2:
            selectedCost = 1.50;
            productName = "�����";
            break;
        case 3:
            selectedCost = 0.75;
            productName = "������";
            break;
        case 4:
            selectedCost = 2.00;
            productName = "�������";
            break;
        }

        std::cout << "�� ������� " << productName << " �� $" << selectedCost << std::endl;
        std::cout << "������� ������: ";

        float money;
        std::cin >> money;

        if (money >= selectedCost) {
           // register.acceptAmount(selectedCost);
            //candyDispenser.makeSale();
            std::cout << "������� �� �������! �������� ��� " << productName << std::endl;
        }
        else {
            std::cout << "������������ �������. ���������� �����." << std::endl;
        }
    }
    else {
        std::cout << "�������� ����� ��������." << std::endl;
    }

    return 0;
}
