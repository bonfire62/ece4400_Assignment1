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
        int z_count = 0;
        int upper_count = 0;
        int e_end = 0;
        int z_end = 0;

        bool prev_z_check = 0;
        bool z_check= 0;
        bool e_check = 1;
        bool u_check = 0;
        bool e_prev = 0;
        bool z_prev = 0;
        bool cap_prev = 0;

        /*printf("%i", arg_len);*/

        // iterate collecting info
        for(i = 0; i < arg_len; i++)
        {
            // e check
            if(target_string[i] == 'e' )
            {
                //checks for prev e or position
                if(e_prev == 1 || i == 0)
                {
                // checks position of e  
                    if(i <= 2)
                    {
                        e_check = 1;
                        e_end++;
                        e_prev = 1;
                    }
                    else 
                        e_check = 0;
                }
                else
                    e_check = 0;
            }
            else
                e_prev = 0;
            // z check
            if(target_string[i] == 'z')
            {
                //checks for characters before position (e check)
                if(i < e_end)
                    z_check = 0;
                // if z was previous or start of z section
                else if(z_prev || i == e_end )
                { 
                    z_count++;
                    if((z_count & 1) != 1)
                        z_check = 0;
                    else
                        z_check = 1;
                    z_prev = 1;
                }
                //check for odd amount of z's

            }
            // start check at end of z's and e's
            z_end = e_end + z_count;
            if(target_string[i] >= 'A' && target_string[i] <= 'Z')
            {
                upper_count++;
                if(i >= z_end || cap_prev)
                {
                    cap_prev = 1;
                    if((upper_count & 1) == 1)
                        u_check = 1;
                    else 
                        u_check = 0;
                }

                
            }

        }
    //printf("echeck: %i zcheck: %i ucheck: %i", e_check, z_check, u_check);
    //
    if(e_check && z_check && u_check)
    {
        if(t_flag)
        {
            for (i=0; i< arg_len; i++)
                if(target_string[i] == 'D')
                    printf("%c", 'H');
                else if(target_string[i] == 'H')
                    printf("%c", 'D');
                else
                    printf("%c", target_string[i]);
        }
        else
            printf("%s", "yes");
    }
    else
        printf("%s", "no");
    }
    //-----------------------B mode test-------------------------------- 
    if(b_flag)
    {
        //printf("b flag test hit");
        b_flag = 0;

        bool upper_odd_flag = 0;
        bool upper_count = 0;
        bool e_flag = 0;
        bool e_prev = 0;
        bool p_flag = 0;
        bool even_upper_flag = 0;
        bool dec_flag = 0;

        int j;
        int i;

        int p_count = 0;
        int e_end = 0;
        int X_end;
        int dec_count = 0;
        const int length_int = strlen(target_string);

        char upper_string[100];

        //printf("%i", length_int);

                
        //printf("%s", target_string);
        for(i = 0; i < length_int ; i++)
        {
            //printf("%s", "made it to for loop");
            //TODO write e repetition requirement
            if(target_string[i] == 'e')
                if(i==0 || e_prev == 1)
                {
                    e_prev = 1;
                    e_end++;
                    e_flag = 1;
                }
                else
                    e_flag = 0;
            
            //checks for upper case string for 'X' 
            if (target_string[i] >= 'A' && target_string[i] <= 'Z')
            {
                if(i >= e_end)
                {
                    upper_string[upper_count] = target_string[i];
                    upper_count++;
                }
                else
                    u_check = 0;
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
        
            //printf("%s", upper_string);


        // boolean checks
        if(upper_odd_flag & 1 == 1)
            upper_odd_flag = 1;
        if(dec_count > 0 && dec_count < 4)
            dec_flag = 1;

        if(p_count > 2 && p_count < 5)
        {
            p_flag = 1;
        }
        //printf("uf: %i pf: %i df: %i", upper_odd_flag, p_flag, dec_flag);
        //TODO add -t flag check
        if(e_flag)
        {
            // number insertion based on index
        for(j = 0; j < length_int; j++)
        { 
            printf("%c", target_string[j]);
            printf("%i", j); 
        }
        }
    } 



    //-----------------------C mode test-------------------------------- 
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
                    // if no flags default a
                    if(!(a_flag || b_flag || c_flag))
                    {
                        a_flag = 1;
                    }
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
