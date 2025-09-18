#include <stdio.h>
#include "mp3view.h"
//#include "mp3edit.h"
#include "type.h"
#include<string.h>

int main(int argc,char *argv[])
{
    if(argv[1]==NULL || argv[2]==NULL)
    {
	printf("ERROR: ./a.out: INVALID ARGUMENTS\nUSAGE:\nTo view please pass like: ./a.out -v mp3filename\nTo edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\nTo get help pass like : ./a.out --help\n");
    }
    else
    {

	//checking it is encoding '-e'
	if(check_operation_type(argv)==v_view)
	{

	    //allocate memeory of structure
	    Viewmp3file view;
	    //check ID3
	    if(check(argv,&view) == e_success)
	    {
                 printf("\n———————————DETAILS DISPLAYED SUCCESSFULLY——————————-\n");
	    }
	    else
		printf("Check unsuccessfull\n");
	}

    }
    return 0;
}

OperationType check_operation_type(char *argv[])
{
 if(strcmp(argv[1],"-v")==0)
        return v_view;
    else if(strcmp(argv[1],"-e")==0)
        return e_edit;
    else
        return e_unsupported;
}

