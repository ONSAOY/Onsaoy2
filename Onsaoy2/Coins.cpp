/*#include <iostream>
#include <string>
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian.UTF-8");
    
    int bronzCoin;
    cout << "Введите кол-во бронзовых монет: " << endl;
    cin >> bronzCoin;
    int silverCoin;
    cout << "Введите кол-во серебряных монет: " << endl;
    cin >> silverCoin;
    int goldCoin;
    cout << "Введите кол-во золотых монет: " << endl;
    cin >> goldCoin;
    int platineCoin;
    cout << "Введите кол-во платиновых монет: " << endl;
    cin >> platineCoin;
    
    int sum = bronzCoin + silverCoin * 100 + goldCoin * 10000 + platineCoin * 10000000; 
    
    int choice;
    
    cout << "Перевести волюту в бронзовые?: (1.Да | 2.Нет )";
    cin >> choice;
    
    if (choice == 1){
        cout << "Ваши монетки перевели в бронзовые, и того получилось: " << sum << endl;
    }
    if (choice == 2){
        cout << "Ну и иди нахуй из банка"<< endl;
    }
}*/