// Заголовочный файл с обьявлением функции
// Защита от многократного включения (include guard)
// #ifndef проверяет, не определен ли уже макрос GAMEMATH_H
// Если не определен, определяем и включаем содержимое файла
// Это предотвратит ошибки повторного включения (не будет повторно инклюдится)

#ifdef GAMMAMATH_H
#define GAMMAMATH_H

#include <string>

// Обьявляем пространство имен GameMath
namespace GameMath{
    
    // === ПЕРЕГРУЗКА ФУНКЦИИ ===
    // Перегрузка - несколько функций с одинаковым именем но разными параметрами
    // Компилятор выбирает нужную функцию на основе переданных параметров
    
    // Функция calculateDamage с разными типами атаки
    // Вариант 1: для обычной физ атаки
    int calculateDamage(int attackPower, int defense);
    
    // Вариант 2: для магической атаки
    float calculateDamage(float magicPower, float magicResistance, int spellLevel);
    
    // Вариант 3: для критической атаки
    int calculateDamage(int attackPower, int defense, float criticalMultiplier);
    
    // Вариант 4: для комбы 
    float calculateDamage(int physicalPower, int defense, float magicPower, float magicResistance, int magicResistance);
    
    // === РЕКУРСИВНЫЕ ФУНКЦИИ === 
    // Рекурсия - функция которая вызывает сама себя
    // Рекурсия должна иметь условие выхода
    
    // Рекурсивныц расчет факториала
    unsigned long long factorial(int n);
    
    // Рекурсивный расчет суммы геометрическо прогресии
    float geometricSeriesSun(float first, float ratio, int terms);
    
    // Рекурсивный поиск в дереве навыков
    int findSkillValue(int skillTree[], int target, int current index = 0);
    
    // === Шаблонная функция ===
    // Шаблоны позволяют создавать обобщенные функции для разных типов данных
    template <typename T> 
    void swapValues(T& a, T& b);
    
} // Конец пространства имен GameMath

// Включаем реализацию шаблонных функций (обычно это делается в .h файле)
// Для шаблонов реализация должна быть в момент компиляции кода файла

#include "GamaMath.tpp"
#endif // завершение GAMEMATH_H
