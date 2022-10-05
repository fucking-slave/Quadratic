#define TEST//comment to turn off testing system

#ifdef TEST
    #define TEST_SYSTEM tester();
#else
    #define TEST_SYSTEM ;
#endif
