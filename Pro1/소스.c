#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ITEM_COUNT 3 // 음료 개수

void showMenu(char* items[], int* prices, int money);
int buyDrink(int* money, int* prices, int choice);

int main() {
    char* items[ITEM_COUNT] = { "콜라", "사이다", "커피" };
    int prices[ITEM_COUNT] = { 1200, 1000, 800 };
    int money;
    int choice;

    printf("=== 포인터 자판기 ===\n");
    printf("금액을 넣어주세요: ");
    scanf("%d", &money);

    while (1) {
        showMenu(items, prices, money);
        printf("번호 선택 (0: 종료): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("프로그램 종료!\n");
            break;
        }

        if (choice < 1 || choice > ITEM_COUNT) {
            printf("잘못된 선택입니다.\n");
            continue;
        }

        if (buyDrink(&money, prices, choice - 1)) {
            printf("%s가 나왔습니다! 잔액: %d원\n", items[choice - 1], money);
        } else {
            printf("잔액이 부족합니다. 현재 잔액: %d원\n", money);
        }
    }

    return 0;
}

void showMenu(char* items[], int* prices, int money) {
    printf("\n--- 음료 목록 ---\n");
    for (int i = 0; i < ITEM_COUNT; i++) {
        printf("%d. %s - %d원\n", i + 1, *(items + i), *(prices + i));
    }
    printf("-----------------\n");
    printf("현재 잔액: %d원\n\n", money);
}

int buyDrink(int* money, int* prices, int choice) {
    if (*money >= *(prices + choice)) {
        *money -= *(prices + choice);
        return 1; // 성공
    }
    return 0; // 실패
}
