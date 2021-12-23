#include<stdio.h>
#include<conio.h>
#include<windows.h>
// #include<graphics.h>
#include<string.h>
#include<stdlib.h>
struct Point
{
    int x,y;
    int x0,y0;
};

struct hightScores{
    char name[100]="truong hoang ha";
    int scores;
    int highscores;
};

void clrscr();
void BOX();
void gotoXY(int column, int line);
void MOVE();
void FOOD(Point &food);
void snakeMove(int &key);
void ShowCur(bool CursorVisibility);
void Color(int backgound_color, int text_color);
void drawSnake();
void Scores();
int Mode();
int process();
void Level(int &level, bool &a);

struct Point snake[100];
struct Point food;
struct hightScores s; 

int lenght=2;
int mode;
int level;
FILE *f;

int main(){ 
    f=fopen("C:\\Users\\Ha\\Desktop\\subline\\HightScores.txt", "a");
    bool b=true;
    while(b){
    int a, options;
    printf("\n");
    printf("              1.Play             \n");
    printf("              2.Options             \n");
    printf("              0.Exit             \n");
    printf("\n Choose your choice: ");
    scanf("%d", &a);
    printf("\n");
    switch (a){
        case 1:
            // clrscr();
            // printf("\nEnter your name: ");
            // fflush(stdin);
            // gets(s.name);
            // fprintf(f, "%s\n", s.name);
            fclose(f);
            clrscr();
            printf("\n        1.Classic       ");
            printf("\n        2.Modern        ");
            printf("\n         0.Back         ");
            printf("\nChoose your choice: ");
            scanf("%d", &mode);
            if(mode==0){
                clrscr();
                break;
             }
            clrscr();
            MOVE();
            getch();
            clrscr();
            break;
        case 2:
            clrscr();
            Color(0,2);
            printf("\n         1.Hight Scores        ");
            printf("\n         2.Sound         ");
            printf("\n         0.Back         ");
            printf("\nChoose your choice: ");
            scanf("%d", &options);
            switch (options){
                case 1:
                    printf("\n          1.Easy");
                    printf("\n          2.Normal");
                    printf("\n          3.Hard");
                    printf("\nChoose your choice: ");
                    scanf("%d", &level);
                    printf("\nSucess, press any key to back!");
                    getch();
                    break;
                case 2:
        
                    printf("\nSucess, press any key to back!");
                    getch();
                    clrscr();
                    break;
                case 0:
                    clrscr();
                    break;
                      }
           break;
        case 0:
        printf("\n SEE YA!");
        getch();
        b=false;
        break;
    }
   }
}

void BOX(){
    Color(0,14);
    for(int i=0; i<79; i++){
        printf("-");
    }
    printf("\n");
    for(int i=0; i<25; i++){
        for(int a=0; a<79; a++){
        if(a==0 || a==78){
            printf("-");
        }else{
            printf(" ");
        }
    }
        printf("\n");
    }
    for(int i=0; i<79; i++){
        printf("-");
    }
    Color(0,15);
}

void MOVE(){
    int key;
    bool a=true;
    ShowCur(0);
    bool b=true;
    snake[0].x=2;
    snake[0].y=2;
    clrscr();
    BOX();
    while(1){
        int m=Mode(); 
        int p=process();
        Scores();
        Color(0,0);
        drawSnake();
        Color(0,2);
        if(snake[0].x==food.x && snake[0].y==food.y){
            lenght++;
            s.scores++;
            b=true;
        }
        if(b){
            FOOD(food);
            b=false;
        }
        gotoXY(food.x, food.y);
        printf("%c", 177);
        snakeMove(key);     
        Mode();
        // process();
        if(m==-1 || p==-1){
            return ;
        }
        if(key==27)
            return ;
        drawSnake();     
        // Level(level, a);
        Sleep(50);
    }
}

void FOOD(Point &food){
    food.x=1 + rand()%77;
    food.y=1 + rand()%25;
}

void snakeMove(int &key){
     for(int i=lenght-1; i>0; i--){
        snake[i]=snake[i-1];
    }
     if(_kbhit()){
            key=getch();
        }
        if(key==97 || key==65 || key==75){
            snake[0].x--; //left
        }if(key==119 || key==87 || key ==72){
            snake[0].y--; //up
        }if(key==115 || key==83 || key==80){
            snake[0].y++; //down
        }if(key==100 || key==68 || key==77){
            snake[0].x++; //right
        }
}

void drawSnake(){
    for(int i=0; i<lenght-1; i++){
        gotoXY(snake[i].x, snake[i].y);
        if(i==0)
            putchar(2);
        else
            putchar('*');
    }
}

void Scores(){
    gotoXY(85,2);
    Color(0,9);
    printf("Scores: ");
    Color(0,12);
    printf("%d", s.scores);
    Color(0,15);
}

int Mode(){
    if(mode==2){
            if(snake[0].y==0 || snake[0].y==25 || snake[0].x==0 || snake[0].x==78){
                gotoXY(82,11);
                Color(0,6);
                printf("Game Over, liu liu");
                gotoXY(83,12);
                printf("Enter your name: ");
                fflush(stdin);
                gets(s.name);
                fprintf(f,"%s%10d", s.name, s.scores);
                fclose(f);
                s.scores=1;
                lenght=2;
                // getch();
                return -1;
            }
        }
        if(mode==1){
            if(snake[0].y==0 && 0<=snake[0].x<=78){
                snake[0].y=25;
            }if(snake[0].x==0 && 0<=snake[0].y<=25){
                snake[0].x=76;
            }if(snake[0].x==78 && 0<=snake[0].y<=25){
                snake[0].x=1;
            }if(snake[0].y==26 && 0<=snake[0].x<=78){
                snake[0].y=1;
            }
        }
    return 0;
}

void Level(int &level, bool &a){
    
    // if(level==1){
    //     Sleep(200);
    //     a=false;
    // }
    // if(level==2){
    //     Sleep(100);
    //     a=false;
    // }
    // else{
    //     Sleep(50);
    //     a=false;
    // }
    if(a){
        if(lenght<=5)
            Sleep(200);
        if(lenght>5 && lenght<=10)
            Sleep(100);
        if(lenght>10 && lenght<=20)
            Sleep(50);
        if(lenght>20);
            Sleep(25);
    }
}

int process(){
    if(lenght>=1){
        for(int i=1; i<lenght-1; i++){  
            if(snake[0].x==snake[i].x && snake[0].y==snake[i].y){
                gotoXY(82,11);
                Color(0,6);
                printf("Game Over, liu liu");
                // fflush(stdin);
                fprintf(f,"%10d", s.scores);
                fclose(f);
                s.scores=1;
                lenght=2;
                // getch();
                return -1;
                }
            }
        }
    return 0;
}

void clrscr()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;                  
    HANDLE  hConsoleOut;
    COORD   Home = {0,0};
    DWORD   dummy;

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

    FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

void gotoXY (int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;
    
    SetConsoleCursorInfo(handle, &ConCurInf);
}

void Color(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}