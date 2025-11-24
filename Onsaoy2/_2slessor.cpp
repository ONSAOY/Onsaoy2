#include <iostream>
#include <string>
#include <cstdlib> // библиотека для рандома
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian.UTF-8");
    
    // for i in range(1, 10)
    for (int i = 1; i <= 10; i++){
        cout<<"Итерация цикла №: " << i << endl;
    }
    
    srand(time(0));
    int playerHp = 100;
    // случайное число от 5 до 23
    int playerDamage = rand() % 23 +5;
    int enemyHp = 80;
    int enemyDamage = rand() % 20 +3;
    
    cout << enemyDamage << endl;
    cout << playerDamage << endl;
    
    for (int raund = 1; raund <= 10; raund++){
        cout << "Раунд: " << raund << endl;
        enemyHp -= playerHp;
        cout << "Вы атакуете врага и наносите ему: " << playerDamage << endl;
        cout << "Здоровье врага: " << enemyHp << endl;

        if (enemyHp -= 0){
            cout << "\n Ура,победа!" << endl;
            break;
        }
        
        playerHp -= enemyDamage;
        cout << "Враг атакует вас и наносит вам: " << enemyDamage << endl;
        cout << "Ваше здоровье: " << playerHp << endl;
        
        if (playerHp -= 0){
            cout << "\n ты умэр" << endl;
            break;
        }
        
        cout << endl;
    }
    
    int randNum = rand() % 101;
    cout << "Я загадал число от 1 до 100, попробуй угадать: " << endl;
    int choice;
    do{
        cout << "Введи число: " << endl;
        cin >> choice;
        if (choice > randNum){
            cout << "Загаданное число меньше твоего" << endl;
        }else if (choice < randNum){
            cout << "Загаданное число больше твоего" << endl;
        }
    }
    while (choice != randNum);
    cout << "Ты победил! Я загадал: " << randNum << endl;
    
    return 0;
}