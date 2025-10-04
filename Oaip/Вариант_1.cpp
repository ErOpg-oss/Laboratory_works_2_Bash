#include <iostream>
#include <cstring>
#include <cctype>

int splitString(char* str, char words[][100]) {
    int wordCount = 0;
    char* token = strtok(str, " ,.!?;:");
    
    while (token != nullptr && wordCount < 10) {
        std::strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(nullptr, " ,.!?;:");
    }
    
    return wordCount;
}

int countWordsStartingWithA(char words[][100], int wordCount) {
    int count = 0;
    for (int i = 0; i < wordCount; i++) {
        if (words[i][0] == 'a' || words[i][0] == 'A') {
            count++;
        }
    }
    return count;
}

int findShortestWordLength(char words[][100], int wordCount) {
    if (wordCount == 0) return 0;
    
    int minLength = std::strlen(words[0]);
    for (int i = 1; i < wordCount; i++) {
        int currentLength = std::strlen(words[i]);
        if (currentLength < minLength) {
            minLength = currentLength;
        }
    }
    return minLength;
}

int countAInLastWord(char words[][100], int wordCount) {
    if (wordCount == 0) return 0;
    
    int count = 0;
    char* lastWord = words[wordCount - 1];
    
    for (int i = 0; lastWord[i] != '\0'; i++) {
        if (lastWord[i] == 'a' || lastWord[i] == 'A') {
            count++;
        }
    }
    return count;
}

void convertToLowercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = std::tolower(str[i]);
    }
}

int countWordsWithMatchingEnds(char words[][100], int wordCount) {
    int count = 0;
    for (int i = 0; i < wordCount; i++) {
        int len = std::strlen(words[i]);
        if (len > 0 && words[i][0] == words[i][len - 1]) {
            count++;
        }
    }
    return count;
}

void findShortestCommonSubstring(char words[][100], int wordCount) {
    if (wordCount < 2) {
        std::cout << "Недостаточно слов для поиска общей подстроки" << std::endl;
        return;
    }
    
    char shortestSubstring[100] = "";
    int shortestLength = 100;
    
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            char word1[100], word2[100];
            std::strcpy(word1, words[i]);
            std::strcpy(word2, words[j]);
            
            for (int start1 = 0; word1[start1] != '\0'; start1++) {
                for (int end1 = start1; word1[end1] != '\0'; end1++) {
                    int length = end1 - start1 + 1;
                    char substring[100];
                    std::strncpy(substring, &word1[start1], length);
                    substring[length] = '\0';
                    
                    if (std::strstr(word2, substring) != nullptr && length < shortestLength && length > 0) {
                        shortestLength = length;
                        std::strcpy(shortestSubstring, substring);
                    }
                }
            }
        }
    }
    
    if (shortestLength < 100) {
        std::cout << "Самая короткая общая подстрока: '" << shortestSubstring << "' (длина: " << shortestLength << ")" << std::endl;
    } else {
        std::cout << "Общая подстрока не найдена" << std::endl;
    }
}

int main() {
    const int MAX_LENGTH = 1000;
    const int MAX_WORDS = 10;
    
    char input[MAX_LENGTH];
    char words[MAX_WORDS][100];
    char originalInput[MAX_LENGTH];
    
    std::cout << "Лабораторная работа №2: Работа со строками" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Введите строку из " << MAX_WORDS << " слов на латинице: ";
    
    std::cin.getline(input, MAX_LENGTH);
    std::strcpy(originalInput, input);
    
    int wordCount = splitString(input, words);
    
    std::cout << "\nРезультаты анализа строки:" << std::endl;
    std::cout << "============================" << std::endl;
    
    int wordsWithA = countWordsStartingWithA(words, wordCount);
    std::cout << "1. Количество слов, начинающихся с 'a': " << wordsWithA << std::endl;
    
    int shortestLength = findShortestWordLength(words, wordCount);
    std::cout << "2. Длина самого короткого слова: " << shortestLength << std::endl;
    
    int aInLastWord = countAInLastWord(words, wordCount);
    std::cout << "3. Количество букв 'a' в последнем слове: " << aInLastWord << std::endl;
    
    char lowerCaseStr[MAX_LENGTH];
    std::strcpy(lowerCaseStr, originalInput);
    convertToLowercase(lowerCaseStr);
    std::cout << "4. Строка в нижнем регистре: " << lowerCaseStr << std::endl;
    
    int matchingEnds = countWordsWithMatchingEnds(words, wordCount);
    std::cout << "5. Количество слов с совпадающими первым и последним символами: " << matchingEnds << std::endl;
    
    std::cout << "6. ";
    findShortestCommonSubstring(words, wordCount);
    
    std::cout << "\nВсе слова в строке:" << std::endl;
    for (int i = 0; i < wordCount; i++) {
        std::cout << (i + 1) << ". '" << words[i] << "' (длина: " << std::strlen(words[i]) << ")" << std::endl;
    }
    
    return 0;
}