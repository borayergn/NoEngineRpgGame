
int fun(int radius , char c){
    if(c == 'p'){
        return 2*radius;
    }
    else if(c =='a'){
        return pi * radius * radius;
    }
}

expected 2 * pi * 5

actual result 2 * pi


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>


int player_x_position = 0;
int player_y_position = 0;
int player_position[2];






void prepare_display_matrix(int column_size, int row_size , char d_matrix[row_size][column_size])
{
for(int i = 0;i<row_size;i++){
    for(int j = 0;j<column_size;j++){
        if(j == player_position[0] && i == player_position[1])
            d_matrix[i][j]='P';
        else
            d_matrix[i][j]=-78;

    }
}
d_matrix[player_y_position][player_x_position+1]=-80;
d_matrix[player_y_position+1][player_x_position+1]=-80;
d_matrix[player_y_position+1][player_x_position]=-80;

}



void prepare_placement_matrix(int column_size,int row_size, char p_matrix[row_size][column_size], int tree_count, int enemy_count)
{

for(int i = 0; i<row_size ; i++){
    for(int j = 0;j<column_size;j++){
        p_matrix[i][j]=' ';
    }
}

int random_xt,random_yt;
int random_xe,random_ye;
int fix_bug_random_xe;
int fix_bug_random_ye;
int fix_bug_random_xt;
int fix_bug_random_yt;

for (int i = 0;i<enemy_count;i++){



    random_xe= 3+ rand()%(29-3);


    random_ye= 3 + rand()%(19-3);

    if(p_matrix[random_ye][random_xe]!=' '){



        fix_bug_random_xe = 3+ rand()%(27-3);
        fix_bug_random_ye =  3 + rand()%(17-3);

        if(p_matrix[fix_bug_random_ye][fix_bug_random_xe]== ' ')
             p_matrix[fix_bug_random_ye][fix_bug_random_xe]='E';

        else if(p_matrix[fix_bug_random_ye][fix_bug_random_xe] != ' '){
            while(p_matrix[fix_bug_random_ye][fix_bug_random_xe]!=' '){

                fix_bug_random_xe = 3+ rand()%(27-3);
                fix_bug_random_ye =  3 + rand()%(17-3);


    }
             p_matrix[fix_bug_random_ye][fix_bug_random_xe]='E';


    }

        }
    else if(p_matrix[random_ye][random_xe]==' ')
     p_matrix[random_ye][random_xe]='E';
                                                //i use these if and else statements for fixing a bug that makes enemies or trees one less than decided number sometimes(with approximately 1/15 chance).

}

for (int i = 0;i<tree_count;i++){


    random_xt=3 + rand()%(27-3);

    random_yt=3+ rand()%(17-3);

    if(p_matrix[random_yt][random_xt]!=' '){

        fix_bug_random_xt = 3+ rand()%(27-3);
        fix_bug_random_yt =  3 + rand()%(17-3);

        if(p_matrix[fix_bug_random_yt][fix_bug_random_xt]== ' ')
             p_matrix[fix_bug_random_yt][fix_bug_random_xt]='T';

        else if(p_matrix[fix_bug_random_yt][fix_bug_random_xt] != ' '){
            while(p_matrix[fix_bug_random_yt][fix_bug_random_xt]!=' '){

                fix_bug_random_xt = 3+ rand()%(27-3);
                fix_bug_random_yt =  3 + rand()%(17-3);


    }
             p_matrix[fix_bug_random_yt][fix_bug_random_xt]='T';


    }

        }
    else if(p_matrix[random_yt][random_xt]==' ')
     p_matrix[random_yt][random_xt]='T';


}

}

void prepare_the_game(int column_size, int row_size, char d_matrix[row_size][column_size], char p_matrix[row_size][column_size], int tree_count, int enemy_count)
{

prepare_display_matrix(column_size,row_size,d_matrix);
srand(time(0));
prepare_placement_matrix(column_size,row_size,p_matrix,tree_count,enemy_count);



}

void update_function(int column_size,int row_size,char d_matrix[row_size][column_size],char p_matrix[row_size][column_size],char old_path_matrix[row_size][column_size],int counter_of_enemy){

char user_input;
int mode_counter=1; // i use a variable named mode_counter to use 'c' key as a switch button with taking modulus according to 2. and incrementing every time it pressed.


while(user_input != 'q' && counter_of_enemy > 0)
    {


    if(mode_counter==1){
        display(column_size,row_size,d_matrix);

    }
    else{
        if(mode_counter%2==0){
                display_god_mode(column_size,row_size,d_matrix,p_matrix);



    }
    else if(mode_counter%2==1){

        for(int i = 0;i<row_size;i++){
            for(int j = 0;j<column_size;j++){
                if(old_path_matrix[i][j]==0){

                    d_matrix[i][j]=-78;

                }
            }
        }
        display(column_size,row_size,d_matrix);

    }

    }


    user_input=getch();

    if(user_input=='c'){
        mode_counter++;
    }


    fight_with_enemy(column_size,row_size,d_matrix,p_matrix,user_input,&counter_of_enemy);

    update_display_matrix(column_size,row_size,d_matrix,p_matrix,old_path_matrix,user_input);


    }

    }


void update_display_matrix(int column_size,int row_size,char d_matrix[row_size][column_size],char p_matrix[row_size][column_size],char old_path_matrix[row_size][column_size],char user_input){
int old_position_x=player_x_position;
int old_position_y=player_y_position;

if(user_input == 'd'){

    player_x_position += 1;
    player_position[0] = player_x_position;

}
else if(user_input == 'a'){
    player_x_position -= 1;
    player_position[0] = player_x_position;
}
else if(user_input == 'w'){
    player_y_position -= 1;
    player_position[1] = player_y_position;
}
else if(user_input == 's'){
    player_y_position += 1;
    player_position[1] = player_y_position;
}


if((player_x_position > 29 || player_x_position<0)||(player_y_position>19 || player_y_position < 0)|| p_matrix[player_y_position][player_x_position]!= ' '){
    player_y_position=old_position_y;
    player_x_position=old_position_x;
    if((player_y_position==19 && player_x_position==8)){
        player_y_position=19;
        player_x_position=8;
    }                                                           //i wrote this statements for fixing a bug that i don't know its reason.
    else if((player_y_position==19 && player_x_position == 9)){
            player_y_position=19;
            player_x_position=9;
            }
}




if(player_x_position == 29){
    d_matrix[player_y_position][player_x_position]='P';
    d_matrix[player_y_position+1][player_x_position]=-80;
    d_matrix[player_y_position-1][player_x_position]=-80;          //at very first i just had the bottom else conditions(with no else) but there was a bug occured about the fog of war. so i add if and else statements to fix that bug.
    d_matrix[player_y_position-1][player_x_position-1]=-80;
    d_matrix[player_y_position+1][player_x_position-1]=-80;
    d_matrix[player_y_position][player_x_position-1]=-80;
    if(player_y_position == 0){
        old_path_matrix[player_y_position+1][player_x_position]=1;
        old_path_matrix[player_y_position+1][player_x_position+1]=1;

    }
    else{
        old_path_matrix[player_y_position+1][player_x_position]=1;
        old_path_matrix[player_y_position-1][player_x_position]=1;
        old_path_matrix[player_y_position-1][player_x_position-1]=1;
        old_path_matrix[player_y_position+1][player_x_position-1]=1;
        old_path_matrix[player_y_position][player_x_position-1]=1;
    }


}
else if(player_x_position == 0){

    d_matrix[player_y_position][player_x_position]='P';
    d_matrix[player_y_position+1][player_x_position]=-80;
    d_matrix[player_y_position+1][player_x_position+1]=-80;
    d_matrix[player_y_position][player_x_position+1]=-80;
    d_matrix[player_y_position-1][player_x_position+1]=-80;
    d_matrix[player_y_position-1][player_x_position]=-80;
    if(player_y_position == 0){
        old_path_matrix[player_y_position+1][player_x_position]=1;
        old_path_matrix[player_y_position+1][player_x_position+1]=1;
        old_path_matrix[player_y_position][player_x_position+1]=1;

    }
    else{
        old_path_matrix[player_y_position+1][player_x_position]=1;
        old_path_matrix[player_y_position+1][player_x_position+1]=1;
        old_path_matrix[player_y_position][player_x_position+1]=1;
        old_path_matrix[player_y_position-1][player_x_position+1]=1;
        old_path_matrix[player_y_position-1][player_x_position]=1;
    }





}
else{
    d_matrix[player_y_position][player_x_position]='P';
    d_matrix[player_y_position+1][player_x_position]=-80;
    d_matrix[player_y_position+1][player_x_position+1]=-80;
    d_matrix[player_y_position][player_x_position+1]=-80;
    d_matrix[player_y_position-1][player_x_position+1]=-80;
    d_matrix[player_y_position-1][player_x_position]=-80;
    d_matrix[player_y_position-1][player_x_position-1]=-80;
    d_matrix[player_y_position+1][player_x_position-1]=-80;
    d_matrix[player_y_position][player_x_position-1]=-80;
    if(player_y_position == 0){
        old_path_matrix[player_y_position+1][player_x_position]=1;
        old_path_matrix[player_y_position+1][player_x_position+1]=1;
        old_path_matrix[player_y_position][player_x_position+1]=1;

    }
    else{
        old_path_matrix[player_y_position+1][player_x_position]=1;
        old_path_matrix[player_y_position+1][player_x_position+1]=1;
        old_path_matrix[player_y_position][player_x_position+1]=1;
        old_path_matrix[player_y_position-1][player_x_position+1]=1;
        old_path_matrix[player_y_position-1][player_x_position]=1;
        old_path_matrix[player_y_position-1][player_x_position-1]=1;
        old_path_matrix[player_y_position+1][player_x_position-1]=1;
        old_path_matrix[player_y_position][player_x_position-1]=1;
    }

}


for(int i = 0;i<row_size;i++){
    for(int j = 0;j<column_size;j++){
        if(d_matrix[i][j] == -80 && p_matrix[i][j]!= ' '){
            d_matrix[i][j]=p_matrix[i][j];
        }
    }
}


printf("\n\n");

}

void display(int column_size,int row_size,char d_matrix[row_size][column_size])
{

system("cls");

for(int i = 0;i<row_size;i++){
    for(int j = 0;j<column_size;j++){
        printf("%c",d_matrix[i][j]);
    }
    printf("\n");
}

}



void fight_with_enemy(int column_size,int row_size,char d_matrix[row_size][column_size] , char p_matrix[row_size][column_size] , char user_input , int *remaining_enemies){


if(user_input == 'h'){

    if(p_matrix[player_y_position+1][player_x_position]=='E'){

        p_matrix[player_y_position+1][player_x_position]=' ';
        *remaining_enemies=*remaining_enemies-1;

    }
   else if(p_matrix[player_y_position+1][player_x_position+1]=='E'){

        p_matrix[player_y_position+1][player_x_position+1]=' ';
        *remaining_enemies=*remaining_enemies-1;

    }
   else if(p_matrix[player_y_position][player_x_position+1]=='E'){

        p_matrix[player_y_position][player_x_position+1]=' ';
        *remaining_enemies=*remaining_enemies-1;

    }
    else  if(p_matrix[player_y_position-1][player_x_position+1]=='E'){

        p_matrix[player_y_position-1][player_x_position+1]=' ';
        *remaining_enemies=*remaining_enemies-1;

    }
    else  if(p_matrix[player_y_position-1][player_x_position]=='E'){

        p_matrix[player_y_position-1][player_x_position]=' ';
        *remaining_enemies=*remaining_enemies-1;

    }
    else  if(p_matrix[player_y_position-1][player_x_position-1]=='E'){

        p_matrix[player_y_position-1][player_x_position-1]=' ';
        *remaining_enemies=*remaining_enemies-1;

    }
    else if(p_matrix[player_y_position][player_x_position-1]=='E'){

        p_matrix[player_y_position][player_x_position-1]=' ';
        *remaining_enemies=*remaining_enemies-1;

    }
    else if(p_matrix[player_y_position+1][player_x_position-1]=='E'){

        p_matrix[player_y_position+1][player_x_position-1]=' ';
        *remaining_enemies=*remaining_enemies-1;

    }
}

}


void display_god_mode(int column_size,int row_size,char d_matrix[row_size][column_size] , char p_matrix[row_size][column_size] ){

    system("cls");

    for(int i = 0;i<row_size;i++){
        for(int j = 0;j<column_size;j++){
            if(d_matrix[i][j]==-78){
                d_matrix[i][j]=-80;
            }
        }
}
    for(int i = 0;i<row_size;i++){
        for(int j = 0;j<column_size;j++){
            if(d_matrix[i][j] == -80 && p_matrix[i][j]!= ' '){          //I wrote these lines for fixing a bug that makes the cheat mode not to show enemy and trees until move at least one time.
                d_matrix[i][j]=p_matrix[i][j];
            }
        }


    }
    for(int i = 0; i<row_size;i++){
        for(int j = 0; j<column_size;j++){
            printf("%c",d_matrix[i][j]);
        }
        printf("\n");
    }

}

int main(void){

int row=20;
int column=30;


player_position[0]=player_x_position;
player_position[1]=player_y_position;


char display_matrix[row][column];
char placement_matrix[row][column];

int old_path_matrix[row][column];
/*
here I defined a 2D array.

This integer array holds 0 for non-discovered places and holds 1 for discovered places.
and i update this array in every game loop according to player position.

in this way i can use this discovered and undiscovered places when i return normal mode from cheat mode.

*/

for(int i = 0;i<row;i++){
    for(int j = 0;j<column;j++){
        old_path_matrix[i][j]=0;
    }
}

int enemy_number;
int tree_number;

srand(time(0));

enemy_number = 5+ rand()%(12-5);

tree_number = 5+ rand()%(12-5);

//I gave random numbers for trees and enemies 5 to 12 because i did not want this game to be so linear.

int enemy_counter = enemy_number;


prepare_the_game(column,row,display_matrix,placement_matrix,tree_number,enemy_number);

update_function(column,row,display_matrix,placement_matrix,old_path_matrix,enemy_counter);

return 0;
}
