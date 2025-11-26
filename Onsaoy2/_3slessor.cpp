#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void showHealthBar(string name, int hp, int maxHp){
    cout << name << "[";
    
    // Вычисляем кол-во делений нашего бара
    int bars = (hp * 10) / maxHp;
    if (bars < 0) bars = 0;
    
    for (int i = 0; i < bars; i++){
        cout << "█"; 
    }
    for (int i = 0; i < 10; i++){
        cout << "░";
    }
    
    cout << "]" << hp << "/" << maxHp << "Hp" << endl;
}

int main(){
    setlocale(LC_ALL, "Russian.UTF-8");
    
    srand(time(0));
    
    // === НАЧАЛЬНЫЕ ХАРАКТЕРИСТЕКИ === //
    int playerHp = 80;
    int maxPlayerHp = 100;
    int enemyHp = 90;
    int maxEnemyHp = 110;
    int potions = 3;
    int round = 0;
    
    // === СТАТИСТИКА === //
    int totalDamageDealth = 0;
    int totalDamageTaken = 0;
    int totalHealing = 0;
    int poisonUsed = 0;
    int defendsUsed = 0;
    
    cout << "╔═════════════════════════════════╗" << endl;
    cout << "║   ЭПИЧЕСКАЯ БИТВА С ПРОВЕРКОЙ   ║" << endl;
    cout << "╚═════════════════════════════════╝" << endl;
    
    // ОСНОВНОЙ ИГРОВОЙ ПРОЦЕСС
    while (playerHp > 0 && enemyHp){
        round++;
        
        
        cout << "╔═══════ Раунд "<< round <<" ═══════╗" << endl;
        cout << endl;
        
        // === СТАТУС ИГРОКА === //
        showHealthBar("ИГРОК", playerHp, maxPlayerHp);
        showHealthBar("ВРАГ", enemyHp, maxEnemyHp);
        cout << "Зелий осталось: " << potions << endl;
        cout << endl;
        
        if (playerHp < maxPlayerHp){
            int regen = 8;
            playerHp += regen; //playerHp = playerHp + regen
            
            // ПРОВЕРКА НА ПРЕВЫШЕНИЕ МАКСИМУМА
            if (playerHp > maxPlayerHp){
                regen = regen - (playerHp - maxPlayerHp); // Корректировка указанного значения
                playerHp = maxPlayerHp;
            }
            cout << "РЕГЕНИРАЦИЯ: +" << regen << "Hp" << endl;
            totalHealing += regen;
            cout << endl;
        }
        
        // === МЕНЮ ДЕЙСТВИЙ (do-while) === //
        int choise;
        bool validChoise = false; // Флаг правильного выбора

        do{
            cout << "---- Твой ход ----" << endl;
            cout << "1.Атаковать" << endl;
            cout << "2.Защититься" << endl;
            cout << "3.Использовать зелье" << endl;
            if (potions == 0){
                cout << "Нет зелий" << endl;
            }
            cout << endl;
            cout << "Ваш выбор: ";
            cin >> choise;
            
            // Проверка ввода игрока
            if (choise >= 1 || choise <= 3){
                if (choise == 3 && potions == 0){
                    cout << "У тебя не осталось зелий, выбери другое действие";
                }
                else{
                    validChoise = true;
                }
            }
            else{
                cout << "Не верный выбор" << endl;
            }
        }
        while (!validChoise);
        
        cout << endl;
        
        // ОБРАБОТКА ВЫБОРА ИГРОКА
        int playerDamage = 0;
        bool isDefending = false; // Флаг защиты
        
        switch (choise){
            case 1:{ // АТАКА
                // Случайный урон от 15 до 25
                playerDamage = rand() % 25 + 15;
                // playerDamage = 15 + rand() % 11
                // rand() % 11 дает 0-11, +15 = 15-25
                
                enemyHp -= playerDamage;
                totalDamageTaken += playerDamage;
                cout << "Ты атакуешь !" << endl;
                cout << "Урон: " << playerDamage << endl;
                break;
            }
            case 2:{ // ЗАЩИТА
                isDefending = true;
                defendsUsed ++;
                cout << "Максимум защиты!" << endl;
                cout << "Ты дефаешь 50% урона" << endl;
                cout << "Регенирация в след раунде 2x" << endl;
                break;
            }
            case 3:{ // ЗЕЛЬЕ
                int healing = 20;
                playerHp += healing;
                if (playerHp > maxPlayerHp){
                    healing = healing - (playerHp - maxPlayerHp);
                    playerHp = maxPlayerHp;
                }
                
                potions--;
                poisonUsed++;
                totalHealing += healing;
                
                cout << "Ты пьешь зелье" << endl;
                cout << "Восстановленно: +" << healing << endl;
                break;
            }
        }
        cout << endl;
        showHealthBar("Враг", enemyHp, maxEnemyHp);
        
        if (playerHp <= 0){
            cout << endl;
            cout << "╔════════════════╗" << endl;
            cout << "║   УРА ПОБЕДА   ║" << endl;
            cout << "╚════════════════╝" << endl;
            break;
        }
        
        cout << endl;
        // ДЗ
        // ХОД ВРАГА:
        //  1.случайный урон врага от 10 до 20
        //  2.проверка если игрок защитится, то уменьшить урон в 2 раза
        //  3.нанести урон игроку + записать в статистику полученый урон
        //  4.Выводим инфу что нам наносит N-ое число урона 
        //  5.показываем здоровье игрока
        //  6.проверяем жив ли наш игрок(если нет прервать while)
        //  7.если да - новый раунд (итерация while)
        
    } 
    cout << "╚═══════════════╝" << endl << endl;
} 
