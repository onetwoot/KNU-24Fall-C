#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <Windows.h>
#include <math.h>

int i, j, height = 20, width = 20;
// �������� �ý��ۿ� ���õ� ����
int gameover, score, stage, hiScore, nextstage = 50;
// Ư�� ���ſ� ���õ� ����
int power, tries = 0, isSpeed = 0, pCycle, sCycle, t;
int x, y, fruitx, fruity, flag;
float times;

// ���� ���� ���� �� �迭
int tailX[100], tailY[100]; // �ִ� 100���� �� ���� ����
int nTail = 0;             // �ʱ� ���� ����

// ��ֹ� ������ ���� ���� �� �迭
int n;
int obsX[50][5], obsY[50][5]; // �ִ� 50���� ��ֹ�
int nObs = 0;                 // ���� ��ֹ� ����
int obsType[50];              // ��ֹ��� ���
float proTimes;               // ��ֹ��� ������ϴ� �ð�

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

    pCycle = rand() % 11;        // power���� �ֱ� �ʱ�ȭ
    sCycle = rand() % 11 + 10;   // speed���� �ֱ� �ʱ�ȭ

    score = 0; // ���� �ʱ�ȭ
    stage = 1; // 1 ���������� �ʱ�ȭ
    nTail = 0; // ���� �ʱ�ȭ
    n = 1;     // ��ֹ� ���� �ʱ�ȭ
    nObs = 0;  // ��ֹ� �ʱ�ȭ
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
            newY == y - 5 && newY == y - 6) ||               // ���� �Ӹ��� ��ġ�� �ʰ�
            (newX == fruitx && newX == fruitx + 1 && newX == fruitx + 2 &&      
                newX == fruitx - 1 && newX == fruitx - 2 &&
                newY == fruity && newY == fruity + 1 && newY == fruity + 2 &&   
                newY == fruity - 1 && newY == fruity - 2));  // ���ϰ� ��ġ�� �ʰ�

        obsType[nObs] = rand() % 3;  // ��ֹ� ��� ����

        obsX[nObs][0] = newX;
        obsY[nObs][0] = newY;

        if (obsType[nObs] == 1) // X��� ��ֹ�
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
        else if (obsType[nObs] == 2) // +��� ��ֹ�
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
        else // o��� ��ֹ� (���� ����)
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
                printf("0"); // �Ӹ�
            }
            else {
                int isTail = 0, isObs = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == i && tailY[k] == j) {
                        printf("o"); // ����
                        isTail = 1;
                    }
                }
                for (int k = 0; k < nObs; k++) {
                    for (int z = 0; z < 5; z++) {
                        if (obsX[k][z] == i && obsY[k][z] == j && obsX[k][z] != 0) {
                            printf("X"); // ��ֹ�
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

    // ���̽��ھ� ������Ʈ
    if (score >= hiScore)
        hiScore = score;

    // ���� ��������
    if (score >= nextstage)
    {
        stage++;               // stage ����
        score -= nextstage;    // �䱸����ŭ score �� ����
        nextstage *= 2;        // �������� Ŭ���� �䱸�� 2�� ����
        power = 0;             // ���������� �Ѿ���Ƿ� power �ʱ�ȭ
        nTail = score / 10;    // ���� ������ ������ �°� ��ȯ
        if (stage >= 5)        // 5 �������� �̻��� �� ��ֹ� ��ȯ
        {
            n += 2;            // ���������� �ö� ������ ��ֹ� �� 2�� ����
            addObstacles(n);
        }
    }

    // ����â ���
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
        times = 0;   // �ð� �ʱ�ȭ

    if (stage < 5)
        proTimes = 0; // ��ֹ� ��ġ �ʱ�ȭ �ð��� �ʱ�ȭ

    if (proTimes > 20) // 20�ʰ� ������ �� ��ֹ� ��ġ �ʱ�ȭ
    {
        addObstacles(n);
        proTimes = 0;
    }

    // ���� ����
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

    // �Ӹ� �̵�
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

    // ���� ������ ���� ����
    if (x <= 0 || x >= height - 1 || y <= 0 || y >= width - 1)
        gameover = 1;

    // ��ֹ��� �浹�ϸ� ���� ����
    for (int k = 0; k < nObs; k++) {
        for (int z = 0; z < 5; z++) {
            if (obsX[k][z] == x && obsY[k][z] == y) {
                gameover = 1;
            }
        }
    }

    // ������ �浹�ϸ� ���� ����
    for (int k = 0; k < nTail; k++) {
        if (tailX[k] == x && tailY[k] == y) {
            gameover = 1;
        }
    }

    // ���Ÿ� ������ ������ ���� ���� ����
    if (x == fruitx && y == fruity) {
        if (tries == pCycle)                  // power ���Ÿ� �Ծ��� ��
        {
            if (power < 10)
                power++;                      // power ����
            pCycle = rand() % 11;             // power ���� �ֱ� �ʱ�ȭ
        }
        else if (tries == sCycle)             // speed ���Ÿ� �Ծ��� ��
        {
            isSpeed = 1;
            sCycle = rand() % 11 + 10;        // speed ���� �ֱ� �ʱ�ȭ
            tries = 0;                        // ���� ȸ�� �ʱ�ȭ
        }

        score += 10 * pow(2, power);
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;
        nTail++;                              // ���� ���� ����
        tries++;                              // ���� ȸ�� ����
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