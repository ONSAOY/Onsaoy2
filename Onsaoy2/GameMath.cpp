// Реализация нешаблонных функций 
// Подключаем заголовочный файл GameMath.h
// #include "" - для пользовательских файлов в той же папке что и файл где мы подключаем 
// #include <> - для системных файлов и библиотек внутри c++

#include "GameMath.h"
#include <iostream>
#include <cmath>
// Для математических функций c++
using namespace std;

// Определяем функкции из пространства имен GameMath
namespace GameMath{
    
    // ===  Релизация перегруженных функций ===
    
    //Версия 1:
    int calculateDamage(int attackPower, int defense){
        // Простая логика формула: урон = атака - защита
        int damage = attackPower - defense;
        
        // Проверка отрицательного урона
        if (damage < 0){
            damage = 0;
        }
        
        // Оптимизация: кампилятор может использовать RVO (Return value Optimization)
        // чтобы избежать лишнего копирования возвратного значения
        return damage;
    }
    
    // Верисия 2:
    float calculateDamage(float magicPower, float magicResistance, int spellLevel){
        // Сложная формула с учетом уровня заклинания 
        // magicResistance в диапозоне 0.0 - 1.0
        float basedamage = magicPower * (1.0f - magicResistance);
        float levelMultiplier = 1.0f + (spellLevel * 0.1f); // +10% урона за каждый уровень
        
        float damage = basedamage * levelMultiplier;
        
        cout << "Магический урон: сила = " << magicPower 
        << ",Сопротивление: " << magicResistance 
        << ",Уровень: "<< spellLevel 
        <<",Урон: "<< damage<< endl;
        
        return damage;
    }
    
    // Версия 3:
    int calculateDamage(int attackPower, int defense, float criticalMultiplier){
        // высчитать базовый урон
        int damage = attackPower - defense;
        
        // проверить что не < 0
        if (damage < 0){
            damage = 0;
        }
        
       // применить множитель критического урона
        int damageSum = criticalMultiplier * damage;
        static_cast<int>(damageSum);
       
       // static_cast - преобразование типа данных static_cast<int> //
       
       // Вывоб крит удара и его подсчет
        cout << "Критический урон =" << criticalMultiplier << " .Итоговый урон:" << damageSum << endl;
       
       // Вывод урона
    }
    
    // Версия 4:
    float calculateDamage(int physicalPower, int defense, float magicPower, float magicResistance){
        int FinalDamage = physicalPower - defense;
        float basedamage = magicPower * (1.0f - magicResistance);
        
        
        float damage = basedamage + FinalDamage;
    }
}