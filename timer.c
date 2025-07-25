#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//   _________________________________
//  | Escape Code | Action           |
//  | ----------- | ---------------- |
//  | `\033[A`    | Up 1 line        |
//  | `\033[2A`   | Up 2 lines       |
//  | `\033[B`    | Down 1 line      |
//  | `\033[C`    | Right 1 column   |
//  | `\033[D`    | Left 1 column    |
//  | `\033[n;Cm` | Set color        |
//  | `\033[H`    | Move to top-left |
//  ---------------------------------


int banner(){
    // Bright Green Color
    // 1 for bold, 31 for red
    // 4 for underline, 32 for green
    printf("\033[1;32m                      d8,                               \033[0m \n");
    printf("\033[1;32m               d8P   `8P                                \033[0m \n");
    printf("\033[1;32m            d888888P                                    \033[0m \n");
    printf("\033[1;32m  d8888b      ?88'    88b  88bd8b,d88b  d8888b  88bd88b \033[0m \n");
    printf("\033[1;32m d8P' `P      88P     88P  88P'`?8P'?8bd8b_,dP  88P'  ` \033[0m \n");
    printf("\033[1;32m 88b          88b    d88  d88  d88  88P88b     d88      \033[0m \n");
    printf("\033[1;32m `?888P'      `?8b  d88' d88' d88'  88b`?888P'd88'      \033[0m \n");
    printf("\033[1;32m                                                        \033[0m \n");
    printf("                                            -By \033[4;34mAxait-th\033[0m \n"); // Red Color, for Creator.
    printf("                                                         \n");
    sleep(1);  // for UX
}


int timerShower(int Years ,int Months ,int Days ,int Hours , int Minutes ,int Seconds ){

    printf(" &&   \033[1;31m%d\033[0m  "   , Years    );
    printf(" &&   \033[1;31m%d\033[0m   "  , Months   );
    printf(" &&  \033[1;31m%d\033[0m  "    , Days     );
    printf(" &&   \033[1;31m%d\033[0m  "   , Hours    );
    printf(" &&    \033[1;31m%d\033[0m   " , Minutes  );
    printf(" &&    \033[1;31m%02d\033[0m  "  , Seconds  );
    printf(" && \n");
    printf(" ============================================================ \n");
    printf("\n  \n"); // Blank Line to easily remove ^C from stdout. Like if ^C does not shown in stdout in other OS.


    return 0;
}

int timerLayout( ){

    printf(" ============================================================ \n");
    printf(" && Years && Months && Days && Hours && Minutes && Seconds && \n");
    printf(" ============================================================ \n");
    timerShower( 0 ,0 ,0 ,0 , 0 ,0 );  // Just to Make Coder Mind Satisfied. Without this, moving Cursor up Require Extra Logic.


    return 0;
}


int timerUpdater( ){

    int Years   = 0 ; 
    int Months  = 0 ; 
    int Days    = 0 ; 
    int Hours   = 0 ; 
    int Minutes = 0 ; 
    int Seconds = 0 ; 

    // Sending Loop to Code to Start Timer.
    while (1){
        sleep(1);

        // To Update Seconds Just.
        Seconds++;
        
        
        // To Calculate All other Time Vars.
        if (Seconds>=60)
        {
            Seconds -= 60;
            Minutes++;
        }
        else if (Minutes>=60)
        {
            Minutes -= 60;
            Hours  += 1;
        }
        else if (Hours>=24 )
        {
            Hours -= 24;
            Days  += 1;
        }
        else if (Days>=30)
        {
            Days  -= 30;
            Months += 1;
        }
        else if (Days>=30)
        {
            Days  -= 30;
            Months += 1;
        }
        else if (Months>=12)
        {
            Months -= 12;
            Years += 1;
        }
        

        // To Change stdout
        printf("\033[4A");
        timerShower( Years, Months, Days, Hours, Minutes, Seconds );
        

    }

    return 0;
}


// Handler for SIGINT (Ctrl+C)
void handleSigint(int sig) {
    // To Remove ^C from stdout
    printf("\033[2D");
    // underlining Link with Yellow color (Better visibility).
    printf("🛑 Why not to vist \033[4;33mhttps://github.com/axait/\033[0m\n");
    printf(" Caught Ctrl+C ! Exiting ...\n");
    sleep(1);
    // You can do cleanup here
    exit(0);  // Exit gracefully by returning 0 to OS,
}

int main(){
    
    // banner();
    timerLayout();   // to set default value of layout at beginning

    signal(SIGINT, handleSigint);
    timerUpdater();  
 
    return 0;
}
