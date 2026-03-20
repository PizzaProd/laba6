#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    float temperature[12][31] =
    {
        {-5,-3,-17,-12,-14,-16,-21,-13,-5,-12,-4,-6,-3,-9,-7,-2,-4,-6,-11,-14,-15,-12,-14,-6,-3,-5,-7,-2,-4,-6,-8},
        {-3,-11,-14,-12,-5,-13,-11,-4,-2,-5,-3,-1,-4,-2,-5,-3,-11,-14,-2,-5,-3,-11,-4,-2,-5,-3,-1,-4},
        {2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,3},
        {8,10,7,9,11,8,10,7,9,11,8,10,7,9,11,8,10,7,9,11,8,10,7,9,11,8,10,7,9,11},
        {15,17,14,16,18,15,17,14,16,18,15,17,14,16,18,15,17,14,16,18,15,17,14,16,18,15,17,14,16,18,16},
        {20,22,19,21,23,20,22,19,21,23,20,22,19,21,23,20,22,19,21,23,20,22,19,21,23,20,22,19,21,23},
        {25,27,24,26,28,25,27,24,26,28,25,27,24,26,28,25,27,24,26,28,25,27,24,26,28,25,27,24,26,28,26},
        {24,26,23,25,27,24,26,23,25,27,24,26,23,25,27,24,26,23,25,27,24,26,23,25,27,24,26,23,25,27,25},
        {18,20,17,19,21,18,20,17,19,21,18,20,17,19,21,18,20,17,19,21,18,20,17,19,21,18,20,17,19,21},
        {10,12,9,11,13,10,12,9,11,13,10,12,9,11,13,10,12,9,11,13,10,12,9,11,13,10,12,9,11,13,11},
        {2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4,1,3,5,2,4,1,3,5},
        {-2,-4,-1,-3,-5,-2,-4,-1,-3,-5,-2,-4,-1,-3,-5,-2,-4,-1,-3,-5,-2,-4,-1,-3,-5,-2,-4,-1,-3,-5,-3}
    };

    float average[12];

    for (int month = 0; month < 12; month++)
    {
        float sum = 0;
        for (int day = 0; day < days[month]; day++)
        {
            sum += temperature[month][day];
        }
        average[month] = sum / days[month];
        printf("%s: %.1f degrees\n", months[month].c_str(), average[month]);
    }

    int coldest = 0;
    int warmest = 0;

    for (int i = 1; i < 12; i++) {
        if (average[i] < average[coldest]) coldest = i;
        if (average[i] > average[warmest]) warmest = i;
    }

    printf("\nColdest month: %s (%.1f degrees)\n", months[coldest].c_str(), average[coldest]);
    printf("Warmest month: %s (%.1f degrees)\n", months[warmest].c_str(), average[warmest]);
}

/*
    int main() 
    {
    

        string text, word, result;
        int M, N;
        cout << "Enter string: ";
        getline(cin, text); //этого не было в лекции, но gets_s не работает со string

        cout << "Enter M and N separated by a space: ";
        cin >> M >> N;

        text += " ";

        int wordCount = 0;
        word = "";
        result = "";

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ')
            {
                word += text[i];
            }
            else
            {
                wordCount++;

                if (wordCount < M || wordCount > N) {
                    result += word + " ";
                }

                word = "";
            }
        }

        cout << "Result: " << result << endl;

    }
    */
/*
Тест 1 — обычный случай
Строка : привет, друг, как твои дела ? M = 2, N = 4
Результат : привет, дела ?

Тест 2 — удаление первого слова
Строка : один два три четыре пять M = 1, N = 1
Результат : два три четыре пять

Тест 3 — удаление всех слов
Строка : один два три M = 1, N = 3
Результат : (пустая строка)

Тест 4 — удаление одного слова из середины
Строка : один два три четыре пять M = 3, N = 3
Результат : один два четыре пять
*/