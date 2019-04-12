#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <signal.h>



void erase_mem(void * ptr)
{
	printf("----&ptr:%p\n",&ptr);
	printf("----ptr:%p\n",ptr);


	GstStaticCaps* b = (GstStaticCaps*)ptr;
	printf("\n----&b:%p\n",&b);
	printf("----b:%p\n",b);
	printf("----*b:%p\n",*b);

    //memset(ptr+1, 0, 1);
	//memset(ptr, 0x179, 10);
    printf("----memset ----\n");
    printf("----b:%p\n",b);
	printf("----*b:0x%x\n",*b);
	printf("----b->caps:%s\n",b->caps);
	//raise (SIGABRT);
}

void erase_ptrptr(void ** ptr)
{
	printf("----&ptrptr:%p\n",&ptr);
	printf("----ptrptr:%p\n",ptr);
	printf("----*ptrptr:%p\n",*ptr);
	print_ptr("*ptr",*ptr);

	int volatile * const p_reg = (int *) *(ptr);
	// p_reg+=11;
	// *p_reg = 0x179;
    for (int i=0; i<4; i++) {
    	//printf(">i:%d",i);
    	printf("%p:%x ",p_reg+i,*(p_reg+i));
    	//*p_reg = 0x179;
    	//p_reg++;
    }

    GstStaticCaps* b = (GstStaticCaps *) *(ptr);
    dump_caps("passed caps_2b",b);
}


void check_struct(GstStaticCaps* a, GstStaticCaps* b)
{
    printf("--param a:%p\n",&a);
    printf("--val a:%p\n",a);
    printf("--param b:%p\n",&b);
    printf("--val b:%p\n",b);
    print_ptr("a",a);
    print_ptr("b",b);
    
    //memset(b, 0, 888);
    void* ptr = &b;
    void** ptrptr = (void**) &b;
    erase_ptrptr(ptrptr);
    //erase_mem(ptr);
    
    printf("--param b:%p\n",&b);
    printf("--val b:%p\n",b);
}


