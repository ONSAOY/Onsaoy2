#include <iostream>
#include <string>
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian.UTF-8");
    
    string playerName = "Oleg";
    int health = 100;
    bool hasPotion = false;
    
    cout << "Игрок: " << playerName << endl;
    cout << "Здоровье: " << health << endl;
    
    cout << "\nВы нашли зелье здоровья" << endl;
    hasPotion = true;
    
    if (hasPotion){
        health += 10;
        
        cout << "Вы похилились на 10, у вас: " << health << "Hp" << endl;
        
        hasPotion = false;
    }
    
    cout << "\n Вы подходите к лесу, тут развилка, куда идете? ---" << endl;
    cout << "1.Налево, в темный лес" << endl;
    cout << "2.Направо, к мосту" << endl;
    cout << "3.Прямо, в пещеру" << endl;
    
    int choice;
    
    cout << "Ваш выбор: ";
    cin >> choice;
    
    if (choice == 1){
        cout << "ты потерялся и умер" << endl;
        health - 100;
    }else if (choice == 2){
        cout << "на мосту вы нашли бутылку и взяли ее" << endl;
        hasPotion = true;
    }else {
        cout << "вы передумали , ничего не произошло" << endl;
    }
    
    cout << "Вы вышли из леса, у вас: " << health << "Hp" << endl;
    
    //switch - множественный выбор
    cout << "\n--- Выберете оружие ---" << endl;
    cout << "1.Меч" << endl;
    cout << "2.Лук" << endl;
    cout << "3.Посох" << endl;
    
    int weaponstyle;
    cout << "Введите выбор оружия: " << endl;
    cin >> weaponstyle;
    
    switch (weaponstyle){
        // case - метка выбора
        // case 1 выполнится, если weaponChoise == 1
    case 1:
        cout << "Вы вооружились мечом. +10 к атаке" << endl;
        // break - прерывание выполнения switch (переход к концу блоков)
        break;
    case 2:
        cout << "Вы взяли лук, +10 к дальней атаке" << endl;
        break;
    case 3:
        cout << "Вы выбрали посох, но у вас нет маны" << endl;
        break;
    // default - случай по умолчанию
    default:
        cout << "Вы не смогли определится, вас загрызли собаки" << endl;
        break;
        
    }
    // Консоль c++ по умолчанию закрыватся после конца потока
    // Для решения , надо ждать ввод от пользователя
    
    cout << "\n Нажмите Enter для выхода";
    
    // cin.ignore - игнорирует 1 символ из буфера ввода
    // Это нужно чтобы игнорировать символ \n который симулирует Enter
    cin.ignore();
    
    // cin.get ждет ввода Enter от пользователя
    // считает 1 символ из буфера ввода
    cin.get();
    
    //После выполнения return все локальные переменные(playerName, health и тд) 
    //автамотически уничтожаются - память в стеке освобождается
    // А string освобождает память в куче, которую он занимал
    
    return 0;
    
}