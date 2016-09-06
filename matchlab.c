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

    const int length_int = strlen(target_string);
    //-----------------------A mode test-------------------------------- 
    //printf("a_flag: %i b_flag: %i c_flag: %i\n", a_flag, b_flag, c_flag);
    if(a_flag)
    {
        //between 0 and 3 repetitions (inclusive) of the letter “e”;
        //any odd number of repetitions of the letter “z”; and
        //an odd number of uppercase letters.
        //printf("a flag hit");
        int i;
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

        /*printf("%i", length_int);*/

        // iterate collecting info
        for(i = 0; i < length_int; i++)
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
                for (i=0; i< length_int; i++)
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

        // boolean flags for final check
        bool upper_odd_flag = 0;
        bool upper_even_flag = 0;
        bool e_flag = 0;
        bool p_flag = 0;
        bool dec_flag = 0;
        bool u_flag = 0;

        //boolean checks for previous values (sequencing of regex expression)
        bool e_prev = 0;
        bool p_prev = 0;
        bool dec_prev = 0;
        bool upper_odd_prev = 0;
        bool upper_even_prev = 0;

        // misc counters
        int j;
        int i;
        int l;

        int upper_odd_count = 0;
        int upper_even_count = 0;
        int p_count = 0;
        int e_end = 0;
        int x_end = 0;
        int dec_count = 0;

        char upper_odd_string[100];
        char upper_even_string[100];

        //printf("%i", length_int);


        //printf("%s", target_string);
        for(i = 0; i < length_int ; i++)
        {
            //printf("%s", "made it to for loop");
            //TODO write e repetition requirement
            if(target_string[i] == 'e')
                if(i==0 || e_prev == 1)
                {
                    e_end++;
                    e_flag = 1; 
                    e_prev = 1;
                    dec_prev = 0;
                }
                else
                    e_flag = 0;


            //checks for upper case string for 'X' 
            if (target_string[i] >= 'A' && target_string[i] <= 'Z')
            {
                if(i >= e_end)
                    // if previous was e, put in upper odd string array
                    if(e_prev || i==0)
                    {
                        upper_odd_string[upper_odd_count] = target_string[i];
                        upper_odd_count++;
                        upper_odd_prev = 1;
                        upper_even_prev = 0;
                    }
                // else put in even string array (post decimals)
                    else if(dec_prev || upper_even_prev)
                    {
                        upper_even_string[upper_even_count] = target_string[i];
                        upper_even_count++;
                        upper_even_prev = 1;
                        upper_odd_prev = 0;
                    }
                    else
                        u_flag = 0;
                else
                    u_flag = 0;
            }
            // checks for p )equirement
            if(target_string[i] == 'p')
            {
                if(i>= upper_odd_count && upper_odd_prev)
                {
                    p_count++;
                    p_prev = 1;
                    p_flag = 1;
                }
                else
                    p_flag = 0;

            }
            // checks for decimal digit
            if(target_string[i]>= 48 && target_string[i] <= 57)
            {
                dec_count++;
                dec_prev = 1;
                e_prev = 0;
            }
            else
                dec_prev = 0;          
        }
        upper_odd_string[++upper_odd_count] = '\0';  
        upper_even_string[++upper_even_count] = '\0';

        // boolean and counter checks
        // checks caps
        int k = strlen(upper_odd_string);
        for(i = 0; i < k; i++ )
        { 
            if((i & 1)==0)
            { 
                j = i >> 1;
                //printf(" %c:%c ", upper_odd_string[i], upper_even_string[j]);
                if(upper_odd_string[i] == upper_even_string[j])
                {
                    u_flag = 1;
                }
                else
                    u_flag = 0;
            }

        }

        //checks number of deimals
        if(dec_count > 0 && dec_count < 4)
            dec_flag = 1;

        if(p_count > 2 && p_count < 5)
        {
            p_flag = 1;
        }
        else 
            p_flag = 0;
        // printf("ef: %i uof: %i pf: %i df: %i\n",e_flag, u_flag, p_flag, dec_flag);
        //TODO add -t flag check
        if(e_flag &&  p_flag && u_flag)
        {
            if(t_flag)
            {
                // number insertion based on index
                for(j = 0; j < length_int; j++)
                { 
                    printf("%c", target_string[j]);
                    l = j & 7;
                    printf("%i", l ); 
                }
            }
            else
                printf("%s", "yes");
        }
        else
            printf("%s", "no");
    } 



    //-----------------------C mode test-------------------------------- 
    if(c_flag)
    {      
        bool a_check; // broke naming convention because a_flag was used previously
        bool z_flag;
        bool dec_flag;
        bool upper_flag;

        bool a_prev;
        bool x_prev;
        bool x_rev_prev;
        bool z_prev;
        bool inp_flag;

        int i;
        int j;
        int a_count = 0;
        int x_count = 0;
        int x_rev_count = 0;
        int dec_count = 0;
        int z_count = 0;
        
        char x_string[100];
        char x_rev_string[100];
        
        for( i = 0; i < length_int; i++ )
        {
            if('a' == target_string[i])
            {
                //printf("%s", "found a");
                if(target_string[0] == 'a')
                    if(i == 0 || a_prev)
                    {
                        a_count++;
                        a_prev = 1;
                        if(a_count >= 3 && a_count <= 6)
                            a_check = 1;
                        else
                            a_check = 0;
                    }
                    
                else
                    a_check = 0;
                //printf("%d", a_count);
            }
            if(target_string[i] >= 'A' && target_string[i] <= 'Z')
            {
                if(a_prev || x_prev)
                {
                    x_string[x_count] = target_string[i];
                    x_count++;
                    x_prev = 1;
                    x_rev_prev = 0;
                    a_prev = 0;
                }
                else if(z_prev || x_rev_prev)
                {
                    x_rev_string[x_rev_count] = target_string[i];
                    x_rev_count++;
                    x_rev_prev = 1;
                    x_prev = 0;
                    a_prev = 0;
                }
                else
                {
                upper_flag = 0;
                a_prev = 0;
                z_prev = 0;
                }

            }
            if(target_string[i] == 'z')
            {
                if(x_prev || z_prev)
                {
                    z_count++;
                    z_prev = 1;
                    x_prev = 0;
                    a_prev = 0;
                }
                else
                    z_flag = 0;
            }
            if(target_string[i]>= '0' && target_string[i] <= '9')
                if(x_rev_prev)
                {
                    ++dec_count;
                    if(dec_count >=1 && dec_count <=3)
                        {
                           dec_flag = 1;
                        }
                    else
                        dec_flag = 0;
                }
                else 
                    dec_flag = 0;
            }
        //checks for input outside allowed scope
        if(target_string != '\0'){    
            if(target_string[i] != 'a' && (target_string[i] < 'A' || target_string[i] > 'Z') && (target_string[i] < '0' || target_string[i] > '9') && target_string[i] != 'z' && target_string[i] != '\0')
                inp_flag = 0;
            else inp_flag = 1;
        }

        //printf("%i: %i", x_count, x_rev_count);
        // checks string for reversal
        if(x_count == x_rev_count)
        {
            //printf("%s", "counts equal");
            j = x_rev_count-1;
            for(i = 0; i < x_count; i++)
            {
                //printf("i: %i:%c, j: %i:%c", i, x_string[i], j, x_rev_string[j]);
                if(x_string[i] == x_rev_string[j])
                    upper_flag = 1;
                else
                    upper_flag = 0;
                j--;
                
            }
        }
        else upper_flag = 0;
        //boolean checks
        // odd check for x string
        if((x_count & 1) == 0)
            upper_flag = 0;
        // odd check for z 
        if((z_count & 1)==0)
            z_flag = 0;
        
        
       printf("acheck: %i uppercheck: %i inp_flag: %i", a_check, upper_flag, inp_flag); 
        if(a_check && upper_flag && inp_flag)
        {
            printf("%s\n", target_string);
        }
        //TODO odd z check
        //TODO digit check
        //TODO cap letter comparison
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
                            //printf("found c\n");  
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

                    //printf("%s", argv[i]);
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
