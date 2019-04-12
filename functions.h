#include <stdio.h>

struct GstStaticCaps {
  double caps;
  const char *string;
};

inline void print_ptr(char* name, void * ptr)
{
	printf("----&%s:%p\n",name,&ptr);
	printf("----%s:%p\n",name,ptr);
}

inline void dump_caps(char* name, GstStaticCaps* scaps)
{
    printf(">>%s: %p\n",name,scaps);
    printf(">>%s: %f\n",name,scaps->caps);
    printf(">>%s: %s\n",name,scaps->string);
}

void check_struct(GstStaticCaps* a, GstStaticCaps* b);
