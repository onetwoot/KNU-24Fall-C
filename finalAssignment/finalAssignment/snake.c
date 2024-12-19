#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <Windows.h>
#include <math.h>

int i, j, height = 20, width = 20;
// 스테이지 시스템에 관련된 변수
int gameover, score, stage, hiScore, nextstage = 50;
// 특수 열매에 관련된 변수
int power, tries = 0, isSpeed = 0, pCycle, sCycle, t;
int x, y, fruitx, fruity, flag;
float times;

// 뱀의 꼬리 변수 및 배열
int tailX[100], tailY[100]; // 최대 100개의 몸 길이 지원
int nTail = 0;             // 초기 꼬리 길이

// 장애물 생성을 위한 변수 및 배열
int n;
int obsX[50][5], obsY[50][5]; // 최대 50개의 장애물
int nObs = 0;                 // 현재 장애물 개수
int obsType[50];              // 장애물의 모양
float proTimes;               // 장애물을 재생성하는 시간

// Function to generate the fruit 
// within the boundary 
void setup()
{
    gameover = 0;

    // Stores height and width 
    x = height / 2;
    y = width / 2;

    fruitx = rand() % (height - 2) + 1;
    fruity = rand() % (width - 2) + 1;

    pCycle = rand() % 11;        // power열매 주기 초기화
    sCycle = rand() % 11 + 10;   // speed열매 주기 초기화

    score = 0; // 점수 초기화
    stage = 1; // 1 스테이지로 초기화
    nTail = 0; // 꼬리 초기화
    n = 1;     // 장애물 개수 초기화
    nObs = 0;  // 장애물 초기화
}

void addObstacles(int n)
{
    nObs = 0;

    for (int k = 0; k < n; k++) {
        int newX, newY;
        do {
            newX = rand() % (height - 2) + 1;
            newY = rand() % (width - 2) + 1;
        } while ((newX == x && newX == x + 1 && newX == x + 2 && newX == x + 3 &&   
            newX == x + 4 && newX == x + 5 && newX == x + 6 &&  newX == x - 1 &&
            newX == x - 2 && newX == x - 3 && newX == x - 4 && newX == x - 5 &&    
            newX == x - 6 && newY == y && newY == y + 1 && newY == y + 2 && 
            newY == y + 3 && newY == y + 4 && newY == y + 5 && newY == y + 6 && 
            newY == y - 1 && newY == y - 2 && newY == y - 3 && newY == y - 4 && 
            newY == y - 5 && newY == y - 6) ||               // 뱀의 머리와 겹치지 않게
            (newX == fruitx && newX == fruitx + 1 && newX == fruitx + 2 &&      
                newX == fruitx - 1 && newX == fruitx - 2 &&
                newY == fruity && newY == fruity + 1 && newY == fruity + 2 &&   
                newY == fruity - 1 && newY == fruity - 2));  // 과일과 겹치지 않게

        obsType[nObs] = rand() % 3;  // 장애물 모양 결정

        obsX[nObs][0] = newX;
        obsY[nObs][0] = newY;

        if (obsType[nObs] == 1) // X모양 장애물
        {
            obsX[nObs][1] = newX - 1;
            obsY[nObs][1] = newY + 1;
            obsX[nObs][2] = newX + 1;
            obsY[nObs][2] = newY + 1;
            obsX[nObs][3] = newX - 1;
            obsY[nObs][3] = newY - 1;
            obsX[nObs][4] = newX + 1;
            obsY[nObs][4] = newY - 1;
        }
        else if (obsType[nObs] == 2) // +모양 장애물
        {
            obsX[nObs][1] = newX;
            obsY[nObs][1] = newY + 1;
            obsX[nObs][2] = newX + 1;
            obsY[nObs][2] = newY;
            obsX[nObs][3] = newX;
            obsY[nObs][3] = newY - 1;
            obsX[nObs][4] = newX - 1;
            obsY[nObs][4] = newY;
        }
        else // o모양 장애물 (오류 방지)
        {
            for (int z = 1; z < 5; z++)
            {
                obsX[nObs][z] = 0;
                obsY[nObs][z] = 0;
            }
        }
        nObs++;
    }
}

// Function to draw the boundaries 
void draw()
{
    system("cls");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");
            }
            else if (i == x && j == y) {
                printf("0"); // 머리
            }
            else {
                int isTail = 0, isObs = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == i && tailY[k] == j) {
                        printf("o"); // 꼬리
                        isTail = 1;
                    }
                }
                for (int k = 0; k < nObs; k++) {
                    for (int z = 0; z < 5; z++) {
                        if (obsX[k][z] == i && obsY[k][z] == j && obsX[k][z] != 0) {
                            printf("X"); // 장애물
                            isObs = 1;
                        }
                    }
                }
                if (!isTail && !isObs) {
                    if (i == fruitx && j == fruity) 
                    {
                        if (tries == pCycle)
                        {
                            printf("@");
                        }
                        else if (tries == sCycle)
                        {
                            printf("$");
                        }
                        else
                        {
                            printf("*");
                        }
                    }
                    else {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }

    // 하이스코어 업데이트
    if (score >= hiScore)
        hiScore = score;

    // 다음 스테이지
    if (score >= nextstage)
    {
        stage++;               // stage 증가
        score -= nextstage;    // 요구량만큼 score 수 감소
        nextstage *= 2;        // 스테이지 클리어 요구량 2배 증가
        power = 0;             // 스테이지를 넘어갔으므로 power 초기화
        nTail = score / 10;    // 꼬리 개수를 점수에 맞게 변환
        if (stage >= 5)        // 5 스테이지 이상일 때 장애물 소환
        {
            n += 2;            // 스테이지가 올라갈 때마다 장애물 수 2개 증가
            addObstacles(n);
        }
    }

    // 상태창 출력
    printf("Stage = %d\n", stage);
    printf("HiScore = %d\n", hiScore);
    printf("Score = %d / %d\n", score, nextstage);
    if (isSpeed)
    {
        if (times > 5)
        {
            if (times > 10) {
                isSpeed -= 1;
                t = 0;
            }

            if (times > 6 + t)
                t++;

            if (times > 5 + t && times < 5.5 + t)
            {
                printf("\n");
            }
            else
            {
                printf("Speed");
                printf("\n");
            }
        }
        else
        {
            printf("Speed");
            printf("\n");
        }
    }
    printf("Power = %d / 10\n", power);
    printf("Press X to quit the game\n");
}

// Function to take the input 
void input()
{
    if (_kbhit()) {
        switch (getch()) {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

// Function for the logic behind 
// each movement 
void logic()
{
    int prevX, prevY;
    int pprevX, pprevY;

    Sleep(200);
    times += 0.2;
    proTimes += 0.2;

    if (!isSpeed)
        times = 0;   // 시간 초기화

    if (stage < 5)
        proTimes = 0; // 장애물 위치 초기화 시간을 초기화

    if (proTimes > 20) // 20초가 지났을 시 장애물 위치 초기화
    {
        addObstacles(n);
        proTimes = 0;
    }

    // 꼬리 연결
    prevX = tailX[0];
    prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    for (int k = 1; k < nTail; k++)
    {
        pprevX = tailX[k];
        pprevY = tailY[k];
        tailX[k] = prevX;
        tailY[k] = prevY;
        prevX = pprevX;
        prevY = pprevY;
    }

    // 머리 이동
    switch (flag) {
    case 1:
        y -= 1 + isSpeed;
        break;
    case 2:
        x += 1 + isSpeed;
        break;
    case 3:
        y += 1 + isSpeed;
        break;
    case 4:
        x -= 1 + isSpeed;
        break;
    default:
        break;
    }

    // 벽에 닿으면 게임 종료
    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1)
        gameover = 1;

    // 장애물과 충돌하면 게임 종료
    for (int k = 0; k < nObs; k++) {
        for (int z = 0; z < 5; z++) {
            if (obsX[k][z] == x && obsY[k][z] == y) {
                gameover = 1;
            }
        }
    }

    // 꼬리와 충돌하면 게임 종료
    for (int k = 0; k < nTail; k++) {
        if (tailX[k] == x && tailY[k] == y) {
            gameover = 1;
        }
    }

    // 열매를 먹으면 점수와 꼬리 길이 증가
    if (x == fruitx && y == fruity) {
        if (tries == pCycle)                  // power 열매를 먹었을 때
        {
            if (power < 10)
                power++;                      // power 증가
            pCycle = rand() % 11;             // power 열매 주기 초기화
        }
        else if (tries == sCycle)             // speed 열매를 먹었을 때
        {
            isSpeed = 1;
            sCycle = rand() % 11 + 10;        // speed 열매 주기 초기화
            tries = 0;                        // 먹은 회수 초기화
        }

        score += 10 * pow(2, power);
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;
        nTail++;                              // 꼬리 길이 증가
        tries++;                              // 먹은 회수 증가
    }
}

void main()
{
    setup();

    while (!gameover) {
        draw();
        input();
        logic();
    }
}