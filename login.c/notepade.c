#include<stdio.h>
#include<windows.h>

void main(){
// char a =219;

//  gotoxy(23,9);set(0,14); printf(" %c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c   %c%c%c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);                                                                         


// // printf("%c%c       %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c%c    %c%c     %c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);45
// // printf("%c%c      %c%c    %c%c %c%c       %c%c %c%c%c%c   %c%c     %c%c    %c%c %c%c      %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);28
// // printf("%c%c      %c%c    %c%c %c%c   %c%c%c %c%c %c%c %c%c  %c%c     %c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c   %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// // printf("%c%c      %c%c    %c%c %c%c    %c%c %c%c %c%c  %c%c %c%c     %c%c    %c%c      %c%c %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// // printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c   %c%c%c%c      %c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

// // printf("%c%c%c    %c%c%c %c%c%c%c%c%c%c %c%c%c    %c%c %c%c    %c%c      %c%c%c%c%c  %c%c%c%c%c%c  %c%c%c    %c%c%c %c%c %c%c%c    %c%c "    ,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// // printf("%c%c%c%c  %c%c%c%c %c%c      %c%c%c%c   %c%c %c%c    %c%c     %c%c   %c%c %c%c   %c%c %c%c%c%c  %c%c%c%c %c%c %c%c%c%c   %c%c "      ,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// // printf("%c%c %c%c%c%c %c%c %c%c%c%c%c   %c%c %c%c  %c%c %c%c    %c%c     %c%c%c%c%c%c%c %c%c   %c%c %c%c %c%c%c%c %c%c %c%c %c%c %c%c  %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// // printf("%c%c  %c%c  %c%c %c%c      %c%c  %c%c %c%c %c%c    %c%c     %c%c   %c%c %c%c   %c%c %c%c  %c%c  %c%c %c%c %c%c  %c%c %c%c "          ,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// // printf("%c%c      %c%c %c%c%c%c%c%c%c %c%c   %c%c%c%c  %c%c%c%c%c%c      %c%c   %c%c %c%c%c%c%c%c  %c%c      %c%c %c%c %c%c   %c%c%c%c "     ,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
                                                                                  
                                                                           
// printf("%c%c%c    %c%c%c %c%c%c%c%c%c%c %c%c%c    %c%c %c%c    %c%c     %c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// printf("%c%c%c%c  %c%c%c%c %c%c      %c%c%c%c   %c%c %c%c    %c%c     %c%c    %c%c %c%c      %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// printf("%c%c %c%c%c%c %c%c %c%c%c%c%c   %c%c %c%c  %c%c %c%c    %c%c     %c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c   %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// printf("%c%c  %c%c  %c%c %c%c      %c%c  %c%c %c%c %c%c    %c%c     %c%c    %c%c      %c%c %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// printf("%c%c      %c%c %c%c%c%c%c%c%c %c%c   %c%c%c%c  %c%c%c%c%c%c       %c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

// printf("%c%c%c%c%c%c%c %c%c  %c%c%c%c%c%c  %c%c%c    %c%c     %c%c    %c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);   30
// printf("%c%c      %c%c %c%c       %c%c%c%c   %c%c     %c%c    %c%c %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// printf("%c%c%c%c%c%c%c %c%c %c%c   %c%c%c %c%c %c%c  %c%c     %c%c    %c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// printf("     %c%c %c%c %c%c    %c%c %c%c  %c%c %c%c     %c%c    %c%c %c%c      ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// printf("%c%c%c%c%c%c%c %c%c  %c%c%c%c%c%c  %c%c   %c%c%c%c      %c%c%c%c%c%c  %c%c      ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

// printf("████████  █████  ███    ███ ██████   █████  ██   ██ ");
// printf("   ██    ██   ██ ████  ████ ██   ██ ██   ██ ██   ██ ");
// printf("   ██    ███████ ██ ████ ██ ██████  ███████ ███████ ");
// printf("   ██    ██   ██ ██  ██  ██ ██   ██ ██   ██ ██   ██ ");
// printf("   ██    ██   ██ ██      ██ ██████  ██   ██ ██   ██ ");

// printf("██████   █████  ██████   █████  ███    ██  ██████   ");
// printf("██   ██ ██   ██ ██   ██ ██   ██ ████   ██ ██        ");
// printf("██████  ███████ ██████  ███████ ██ ██  ██ ██   ███  ");
// printf("██   ██ ██   ██ ██   ██ ██   ██ ██  ██ ██ ██    ██  ");
// printf("██████  ██   ██ ██   ██ ██   ██ ██   ████  ██████   ");

//     gotoxy(19,4);  set(0,11); printf("%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c\n",m,m,187,m,m,187,m,m,m,m,m,m,m,187,m,m,187,m,m,m,m,m,m,187,m,m,m,m,m,m,187,m,m,m,187,m,m,m,187,m,m,m,m,m,m,m,187);
//     gotoxy(19,5);  set(0,11); printf("%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c\n",m,m,186,m,m,186,m,m,201,205,205,205,205,188,m,m,186,m,m,201,205,205,205,205,188,m,m,201,205,205,205,m,m,187,m,m,m,m,187,m,m,m,m,186,m,m,201,205,205,205,205,188);
//     gotoxy(19,6);  set(0,11); printf("%c%c%c %c%c %c%c%c%c%c%c%c%c%c  %c%c%c     %c%c%c     %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  \n",m,m,186,m,187,m,m,186,m,m,m,m,m,187,m,m,186,m,m,186,m,m,186,m,m,186,m,m,201,m,m,m,m,201,m,m,186,m,m,m,m,m,187);
//     gotoxy(19,7);  set(0,11); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c%c%c     %c%c%c     %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  \n",m,m,186,m,m,m,187,m,m,186,m,m,201,205,205,188,m,m,186,m,m,186,m,m,186,m,m,186,m,m,186,200,m,m,201,188,m,m,186,m,m,201,205,205,188);
//     gotoxy(19,8);  set(0,11); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c %c%c%c%c%c%c%c%c%c%c%c\n",200,m,m,m,201,m,m,m,201,188,m,m,m,m,m,m,m,187,m,m,m,m,m,m,m,187,200,m,m,m,m,m,m,187,200,m,m,m,m,m,m,201,188,m,m,186, 200,205,188, m,m,186,m,m,m,m,m,m,m,187);
//     gotoxy(19,9);  set(0,11); printf(" %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c     %c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,188,200,205,205,188, 200,205,205,205,205,205,205,188,200,205,205,205,205,205,205,188, 200,205,205,205,205,205,188, 200,205,205,205,205,205,188, 200,205,188,200,205,188,200,205,205,205,205,205,205,188);  

// gotoxy(15,5);   set(0,14);printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c      %c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
// gotoxy(15,5);   set(0,14);printf("%c%c      %c%c      %c%c %c%c   %c%c %c%c          %c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
// gotoxy(15,5);   set(0,14);printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c   %c%c %c%c%c%c%c        %c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
// gotoxy(15,5);   set(0,14);printf("     %c%c %c%c      %c%c %c%c   %c%c %c%c           %c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
// gotoxy(15,5);   set(0,14);printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c      %c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a); 

// gotoxy(15,5);   set(0,14); printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// gotoxy(15,5);   set(0,14); printf("%c%c      %c%c      %c%c %c%c   %c%c %c%c               %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// gotoxy(15,5);   set(0,14); printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c   %c%c %c%c%c%c%c        %c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// gotoxy(15,5);   set(0,14); printf("     %c%c %c%c      %c%c %c%c   %c%c %c%c          %c%c      ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// gotoxy(15,5);   set(0,14); printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c%c%c%c%c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
                                               
                                               
// gotoxy(25,5);   set(0,14); printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// gotoxy(25,6);   set(0,14); printf("%c%c      %c%c      %c%c %c%c   %c%c %c%c               %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// gotoxy(25,7);   set(0,14); printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c   %c%c %c%c%c%c%c        %c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// gotoxy(25,8);   set(0,14); printf("     %c%c %c%c      %c%c %c%c   %c%c %c%c               %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
// gotoxy(25,9);   set(0,14); printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

//  printf("acbatbatb  ab acbtcbacbabaacb");
//  printf("ecf jj jj  egbecfetiecfjjjj t");
//  printf("g gcgicgi  hcig gghcg gihihci ");

//  gotoxy(95,4);    set(0,15);printf("%c%c%c%c%c%c%c%c%c  %c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",a,c,b,a,d,b,a,d,b,a,b,a,c,b,d,c,b,a,c,b,a,b,a,a,c,b);
//  gotoxy(95,4);    set(0,15);printf("%c%c%c %c%c %c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c",e,c,f,j,j,j,j,e,g,b,e,c,f,e,d,i,e,c,f,j,j,j,j,d);
//  gotoxy(95,4);    set(0,15);printf("%c %c%c%c%c%c%c%c  %c%c%c%c %c%c%c%c%c %c%c%c%c%c%c%c ",g,g,c,g,i,c,g,i,h,c,i,g,g,g,h,c,g,g,i,h,i,h,c,i);  




// gotoxy(95,5);set(9,15);printf("%c %c%c%c%c%c%c%c%c %c%c%c%c  %c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",d,d,a,c,b,a,c,b,d,d,a,c,b,a,b,a,c,b,d,c,b,a,c,b,a,b,a,a,c,b);
// gotoxy(95,6);set(9,15);printf("%c%c%c%c%c%c%c%c%c%c %c%c%c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c",e,c,f,e,c,f,e,c,i,j,j,h,c,b,e,g,b,e,c,f,e,d,i,e,c,f,j,j,j,j,d);
// gotoxy(95,7);set(9,15);printf("%c %c%c %c%c  %c%c%c%c%c%c  %c%c%c%c %c%c%c%c%c %c%c%c%c%c%c%c",g,g,g,g,g,h,c,i,h,c,i,h,c,i,g,g,g,h,c,g,g,i,h,i,h,c,i);    

 //            char  a = 201,b = 187,c = 205,d = 203,e = 204,f = 185,g = 202,h = 200,i = 188,j = 186, k = 220, l=223  ;   
                 //┌ =201, ┐ =187, ─ =205, ┬ =203, ├ =204, ┤ =185, ┴ =202, └ =200, ┘ =188, │ = 186  ▄ = 220  ▀ = 223


 
   
  

// printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,d,b,a,c,b,d,c,b,d,d,a,c);
// printf(" %c %c%c%c%c%c%c%c%c%c%c\n",j,e,c,c,f,e,d,i,j,e,g,b);
// printf(" %c %c %c%c%c%c%c%c %c\n",g,g,g,g,h,c,g,g,g);


// ╔═╗╔═╗╦  ╔╦╗╔═╗
// ╚═╗╠═╣║   ║║║ ║
// ╚═╝╩ ╩╩═╝═╩╝╚═╝




        
    //    char input;
    // char tamp[100] = {};
    // int index = 0,at = 0,under = 0;
    // while((input = getch()) != 13 || index < 3 || tamp[index-1] == '@' || tamp[index-1] == '_'){
    //     if(index < 15 && (input >= 'a' && input <= 'z' || input >= 'A' && input <= 'Z' || input >= '0' && input <='9' || input == '@' && at == 0 || input == '_' && under == 0 && index != 0)){
    //         printf("%c",input);
    //         tamp[index] = input;
    //         index++;
    //         if(input == '@'){
    //             at++;
    //         }
    //         else if(input == '_'){
    //             under++;
    //         }
    //     }
    //     else if(input == 8 && index != 0){
    //         printf("\b \b");
    //         index--;
    //         if(tamp[index] == '@'){
    //             at--;
    //         }
    //         else if(tamp[index] == '_'){
    //             under--;
    //         }
    //         tamp[index] = '\0';  
    //     }
    // }

int batas;

printf("masukan batas : "); scanf("%d",&batas);

for(int a = 0 ; a < batas ; a++ ){
    for(int b = 0 ; b < batas ; b ++){
        if(a+b>=batas || a+b==batas){
            printf("* ");
        }else{
            printf(" ");
        }
    }
    printf("\n");
}



}
