//These are what we call libraries, or headers
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
//be aware you need to have installed 
#include <libdragon.h>

//int main is basically where the program starts
int main(void)
{
    //initializing the console and controllers and some other things
    console_init();
    //all functions have parenthessis and if they have perameters you input them there
    controller_init();
    timer_init();
    rtc_init();

    //set the way that the console renders graphics
    //note that this thing inside the parenthessis is a perameter of the function
    console_set_render_mode(RENDER_MANUAL);

    //time_t is a type that will keep track of the current time
    //after the type you name the variable, here i named it current_time
    time_t current_time = -1;

    //int is a kind of data that only stores whole numbers with no decimals,
    //also after each line add a semicolon

    //here I create what we call an array,
    //arrays can hold multiple values
    //here I create and array with 32 values of type uint8_t
    uint8_t data[32];

    //here I create a set of memory/data where I pass data and 0 and 32,
    //0 is the current value and 32 is the size
    memset( data, 0, 32);

    //A while loop will execute the code inside of it until the loop is broken
    //so either the expression is false or you type "break;"
    //this will execute forever until console is turned off
    while(1)
    {
        //cleaning
        console_clear();

        //initializing and scanning controller for inputs
        controller_scan();

        //basically I am creating a new type of data structure
        //I call it keys, keys are readable through libdragon (it is really controller input)
        struct controller_data keys = get_keys_down();

            if( keys.c[0].A)
            {
                //the \n just means go to the next line and %d and i means print i
                // also It should output "A button pressed on controller 1" if you press the a button on controller 1
                printf("A button pressed on controller 1\n");
            }//if statement curley braces
            else {
                printf("                                \n");
            }

            if( keys.c[0].Z)
            {
                //the \n just means go to the next line and %d and i means print i
                // also It should output "Z button pressed on controller 1" if you press the a button on controller 1
                printf("Z button pressed on controller 1\n");
            }//if statement curley braces 
            else {
                printf("                                \n");
            }

            //prints date and time
            //NULL means no value its just undefined

            current_time = time( NULL );
            if( current_time != -1 )
            {
                //prints it
                printf("date/time: %s\n\n", ctime( &current_time ));
            }

            //prints that data array that i created above
            for( int i = 0; i < 32; i++ )
            {
                printf( "%02X", data[i] );
            }

            //sees what controllers are plugged in
            int controller = get_controllers_present();
            //sees what controllers are plugged in and will print out if they are plugged in
            printf( "Controller %d %sconnected\n", controller, (controller & CONTROLLER_1_INSERTED) ? "" : "not " );
            //console loop/ render loop
            console_render();
    } //also each loop, if statement, function and so on have curly braces around it
}
