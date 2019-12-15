#include <iostream>
#include "brasss.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass piggy("Porcelot pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Depositiong $1000 into the Hogg Account: \n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl;
    piggy.Withdraw(4200.00);
    cout << "pigg account balance: $" << piggy.Balance() <<endl;
    cout << "Withdrawing $4200 from the Hogg Account: \n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();

    return 0;
}
