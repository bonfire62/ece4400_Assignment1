#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0

    bool a_flag;
    bool b_flag;
    bool c_flag;
    bool t_flag;
    bool no_arg;
    int flag_count = 0;
int parse_algo(char target_string[])
{
    //-----------------------A mode test-------------------------------- 
    //printf("a_flag: %i b_flag: %i c_flag: %i\n", a_flag, b_flag, c_flag);
    if(a_flag)
    {
       //between 0 and 3 repetitions (inclusive) of the letter “e”;
        //any odd number of repetitions of the letter “z”; and
        //an odd number of uppercase letters.
        //printf("a flag hit");
        int i;
        int arg_len  = strlen(target_string);
        int e_count = 0;
        int z_count = 0;
        int upper_count = 0;

        bool prev_z_check = 0;
        bool z_check= 0;
        bool e_check = 0;
        bool u_check = 0;
        printf("%i", arg_len);
        // iterate collecting info
        for(i = 0; i < arg_len; i++)
        {
            if(target_string[i] == 'e')
                e_count = e_count + 1;
            if(target_string[i] == 'z')
                z_count++;
            if(prev_z_check)
                z_count++;
            else
                // if odd number check
                if((z_count & 1) == 1)
                    z_check = 1;
            prev_z_check = 0;
            // checks ascii for upper case
            if (target_string[i] >= 'A' && target_string[i] <= 'Z')
            {
                upper_count++;
                if(target_string[i] == 'D')
                    target_string[i] = 'H';                                                       
                else if(target_string[i] == 'H')                                        
                    target_string[i] = 'D';         
            }
            // else
            //printf("Character is Not Upper Case Letters");            //printf("%i\n", z_count);
        }
        // run checks on count and booleans
        if(e_count > 3) e_check = 0;
        else e_check = 1;


        //printf("z check: %i e check: %i", z_check, e_check);

        if(z_check && e_check)
        {
            //TODO check t flag for print 
            if(t_flag)
            {
                printf("%s ", target_string);
            }
            else
            {
                printf("%s", "yes "); 
            }
        }
        else
        {
            if(!t_flag)
                printf("%s", "no ");
        }
    }
    //-----------------------B mode test-------------------------------- 
    if(b_flag)
    {
        //printf("b flag test hit");
        b_flag = 0;

        bool upper_flag = 0;
        bool upper_count = 0;
        bool e_flag = 0;
        bool p_flag = 0;
        
        int j;
        int i;

        int p_count = 0;
        int dec_count = 0;
        const int length_int = strlen(target_string);

        char upper_string[100];

        printf("%i", length_int);

                
        //printf("%s", target_string);
        for(i = 0; i < length_int ; i++)
        {
            //printf("%s", "made it to for loop");
            //TODO write e repetition requirement
            
            if(target_string[i] == 'e')
                if(target_string[0] != 'e')
                    e_flag = 0;
            //checks for upper case string for 'X' 
            if (target_string[i] >= 'A' && target_string[i] <= 'Z')
            {
                //TODO
                upper_string[upper_count] = target_string[i];
                upper_count++;
            }
            // checks for p requirement
            if(target_string[i] == 'p')
            {
                p_count++;
            }
            // checks for decimal digit
            if(target_string[i]>= 48 && target_string[i] <= 57)
            {
                dec_count++;
            }

            
            
        }

        printf("%i", length_int);
        // number insertion based on index
        for(j = 0; j < length_int; j++)
        { 
            printf("%c", target_string[j]);
            printf("%i", j); 
        }
        
            //printf("%s", upper_string);


        // boolean checks
        if(upper_flag & 1 == 1)
            upper_flag = 1;
        if(p_count > 2 && p_count < 7)
        {
            p_flag = 1;
        }
    } 



    //-----------------------B mode test-------------------------------- 
    if(c_flag)
    {
        printf("c flag test hit");
        c_flag = 0;
    }



    return 0;
}



int main(int argc, char** argv)
{    
    int i;
    
/*printf("argc = %i", argc);*/
/*printf("0 arg: %s", argv[0]);*/
/*printf("1 arg: %s", argv[1]);*/
    // if more than one arg
    if(argc > 1)
    {
    // for each argument
        for(i=1; i < argc; i++)
        {   
            int j = 0;
            //No arguments check
            while(argv[i][j] != '\0')
            {
                if(argv[i][j] == '-')
                {
                    //printf("found dash\n");
                    //found dash, increment j
                    j++; 
                    switch(argv[i][j])
                    {
                        case 'a':
                            //printf("found a\n");
                            j++;
                            a_flag = true;
                            break;
                        case 'b':
                            //printf("found b\n");
                            j++;
                            b_flag = true;
                            break;
                        case 'c':
                            printf("found c\n");  
                            j++;
                            c_flag = true;
                            break;
                        case 't':
                            //printf("found t\n");
                            j++;
                            t_flag = true;
                            break;

                    }

                }
                else if(argv[i][j] != '-')
                {
                    //printf("argument found");
                    parse_algo(argv[i]);
                    break; 
                
                }

                /*printf("%s", argv[i]);*/

            }
        }
        
    }
    else
    {
    //run default
    printf("no-arg case hit");
    }

    /*char* amode*/

    return 0;

}
