#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    char input[256];
    char words[10][50];
    int wordCount = 0;
    
    cout << "Введите строку из 10 слов на латинице: ";
    cin.getline(input, 256);
    
   
    char *ptr = input;
    int charIndex = 0;
    
    while (*ptr != '\0' && wordCount < 10) {
        while (*ptr == ' ') {
            ptr++;
        }
        
        if (*ptr == '\0') break;

        charIndex = 0;
        while (*ptr != ' ' && *ptr != '\0' && charIndex < 49) {
            words[wordCount][charIndex] = *ptr;
            charIndex++;
            ptr++;
        }
        words[wordCount][charIndex] = '\0';
        wordCount++;
    }
    
    if (wordCount < 10) {
        cout << "Ошибка: введено только " << wordCount << " слов. Нужно 10 слов!" << endl;
        return 1;
    }
    
    // 1
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (words[i][0] == 'a' || words[i][0] == 'A') {
            count++;
        }
    }
    
    // 2
    int minLength = strlen(words[0]);
    for (int i = 1; i < 10; i++) {
        int len = strlen(words[i]);
        if (len < minLength) {
            minLength = len;
        }
    }
    
    // 3
    int countAInLastWord = 0;
    int lastWordLength = strlen(words[9]);
    for (int i = 0; i < lastWordLength; i++) {
        if (words[9][i] == 'a' || words[9][i] == 'A') {
            countAInLastWord++;
        }
    }
    
    // 4
    for (int i = 0; i < 10; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            words[i][j] = tolower(words[i][j]);
        }
    }
    
    // 5
    int countFirstLastMatch = 0;
    for (int i = 0; i < 10; i++) {
        int len = strlen(words[i]);
        if (len > 0 && words[i][0] == words[i][len - 1]) {
            countFirstLastMatch++;
        }
    }
    
    cout << "Количество слов, начинающихся с буквы 'a': " << count << endl;
    cout << "Длина самого короткого слова: " << minLength << endl;
    cout << "Количество букв 'a' в последнем слове: " << countAInLastWord << endl;
    cout << "Все слова в нижнем регистре:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "   " << (i + 1) << ": " << words[i] << endl;
    }
    cout << "Количество слов с одинаковыми первым и последним символом: " << countFirstLastMatch << endl;
    
    return 0;
}