#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
      int data;
} Element;

void clear()
{
      usleep(2 * 1000 * 1000); // 1,000,000 = 1초
      system("clear");
}

Element *InsertData(Element *_List)
{
      if (_List == NULL)
      {
            // 리스트에 아무런 값이 없는 경우
            _List = (Element *)malloc(sizeof(Element *) * 1);
            printf("데이터 입력 : ");
            scanf("%d", &_List[0].data);
            printf("데이터 입력 완료!!!\n");
      }
      else
      {
            // 이미 리스트에 값이 있는 경우
            Element *tmp;
            memcpy(&tmp, &_List, sizeof(_List));
            int Length = sizeof(tmp) / 8;

            for (int i = 0; i < Length; i++)
            {
                  tmp[i].data = _List[i].data;
            }

            _List = (Element *)malloc(sizeof(Element *) * (Length + 1));
            for (int i = 0; i < Length + 1; i++)
            {
                  if (i != Length)
                  {
                        _List[i].data = tmp[i].data;
                  }
                  else
                  {
                        printf("데이터 입력 : ");
                        scanf("%d", &_List[i].data);
                        printf("데이터 입력 완료!!!\n");
                  }
            }

            for (int i = 0; i < Length + 1; i++)
            {
                  printf("%d : %d\n", i, _List[i].data);
            }

            free(tmp);
      }
      return _List;
}

void getData(Element *_List)
{
      if (_List == NULL)
      {
            printf("아무런 입력 값이 없습니다.\n");
            return;
      }
      else
      {
            int Length = sizeof(_List) / 8;
            printf("길이 : %d\n", Length);
            return;
      }
}

Element *UpdateData(int index, Element *_List)
{
      return _List;
}

Element *DeleteData(int index, Element *_List)
{
      return _List;
}

int main()
{
      Element *List = NULL; // 리스트 선언
      int SelSwitch;        // 반복문 제어 변수
      system("clear");
      while (1)
      {
            printf("*********리스트구현체*********\n");
            printf("*       1. 데이터 입력       *\n");
            printf("*       2. 데이터 조회       *\n");
            printf("*       3. 데이터 수정       *\n");
            printf("*       4. 데이터 삭제       *\n");
            printf("*       5. 종료              *\n");
            printf("******************************\n");
            printf("입력> ");
            scanf("%d", &SelSwitch);
            if (SelSwitch == 1)
            {
                  List = InsertData(List);
            }
            else if (SelSwitch == 2)
            {
                  getData(List);
            }
            else if (SelSwitch == 3)
            {
                  int ixd;
                  printf("수정할 인덱스 : %d", ixd);
                  scanf("%d", &ixd);
                  List = UpdateData(ixd, List);
            }
            else if (SelSwitch == 4)
            {
                  int ixd;
                  printf("삭제할 인덱스 : %d", ixd);
                  scanf("%d", &ixd);
                  List = DeleteData(ixd, List);
            }
            else if (SelSwitch == 5)
            {
                  break;
            }
            else
            {
                  printf("잘못 된 입력입니다.\n");
                  clear();
            }
            clear();
      }

      // int _length;
      // setLength(&_length);
      // printf("배열 길이 : %d\n", _length);
      // List = initArray(_length);

      // // 구조체에 데이터 입력
      // for (int i = 0; i < _length; i++)
      // {
      //       char *input = malloc(sizeof(char) * 32);
      //       printf("%d번째 값 입력 : ", i + 1);
      //       scanf("%s", input);
      //       List[i].data = (char *)malloc(sizeof(char) * (int)strlen(input));
      //       strcpy(List[i].data, input);
      //       free(input);
      // }

      // for (int i = 0; i < _length; i++)
      // {
      //       printf("%d번재 값 : %s\n", i + 1, List[i].data);
      // }

      return 0;
}
