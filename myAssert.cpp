#define NDEBUG //comment to turn off developer's security

#ifdef NDEBUG
    #define ASSERT(condition); if(!(condition)){printf("ERROR, THERE IS A MISTAKE IN THE CODE");abort();}
#else
    #define ASSERT(condition) ;
#endif


