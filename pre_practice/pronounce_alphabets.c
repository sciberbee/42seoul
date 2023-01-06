#include <stdio.h>
int main() {
    char input;

    printf("소문자 알파벳 abc를 읽어드립니다.\n");
    printf("알파벳을 입력해주세요");

    scanf("%c", &input);

    switch (input) {
        case 'a':
            printf("엣\n");
            break;

        case 'b':
            printf("비이\n");
            break;
        
        case 'c':
            printf("씨이이\n");
            break;
        
        default:
            printf("죄송해요.. 그 글자는 읽지 못해요.\n");
            break;
    }
    return 0;
}