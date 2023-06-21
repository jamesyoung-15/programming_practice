#include <iostream>

//Simple ATM machine that allows user to store, withdraw, and check balance.

void showMenu()
{
    std::cout<<"\n -----Menu------ \n";
    std::cout<<"1. Deposit: \n";
    std::cout<<"2. Withdraw: \n";
    std::cout<<"3. Check Balance: \n";
    std::cout<<"4. Exit: \n";
}

int main()
{
    int option;
    double balance=250;
    do{
        showMenu();
        std::cout<<"Choose option:";
        std::cin>>option;
        switch(option)
        {
            case 1:
                std::cout<<"Enter amount to deposit: $";
                double deposit;
                std::cin>>deposit;
                balance+=deposit;
                break; 
            case 2:
                std::cout<<"Enter amount to withdraw: $";
                double withdraw;
                std::cin>>withdraw;
                if(withdraw<=balance)
                    balance-=withdraw;
                else
                    std::cout<<"Not enough balance in account. \n";
                break;
            case 3:
                std::cout<<"Account balance: $" << balance <<"\n";
                break;
            case 4:
                std::cout<<"Thanks for using this service \n";
                break;
            default:
                std::cout<<"Not valid option. \n";
        }
    }
    while(option!=4);
    return 0;
}