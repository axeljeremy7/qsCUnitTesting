#include "main.h"
#include "test.h"

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void
test_discrim()
{
    double d1 = discrim(3.0, 4.0, 2.0);
    double d2 = discrim(9.0, 12.0, 4.0);
    double d3 = discrim(1.0, -9.0, 14.0);
    CU_ASSERT(0 > d1);
    CU_ASSERT(0 == d2);
    CU_ASSERT(0 < d3);

    CU_ASSERT(0 == check_discrim(d1));
    CU_ASSERT(1 == check_discrim(d2));
    CU_ASSERT(2 == check_discrim(d3));
}

void 
test_doubleroot(void)
{
    float a = (float)1.0;
    float b = (float)-10.0;
    float c = (float)25.0;
    double d = discrim(a, b, c);
    double target = 5.0;

    CU_ASSERT(target == get_root_minus(a, b, c, d));
    CU_ASSERT(target == get_root_plus(a, b, c, d));
}

void
test_singleroots(void)
{
    float a = (float)1.0;
    float b = (float)-9.0;
    float c = (float)14.0;
    double d = discrim(a, b, c);

    CU_ASSERT((float)2.0 == get_root_minus(a, b, c, d));
    CU_ASSERT((float)7.0 == get_root_plus(a, b, c, d));
}

int 
main (void)// Main function
{
    CU_pSuite pSuite1 = NULL;

    // Initialize CUnit test registry 
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add suite1 to registry 
    pSuite1 = CU_add_suite("qsTest", init_suite, clean_suite);
    if (NULL == pSuite1) 
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // add test1 to suite1 
    if ((NULL == CU_add_test(pSuite1, "", test_discrim)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite1, "", test_doubleroot)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite1, "", test_singleroots)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    CU_basic_set_mode(2);
    CU_basic_run_tests(); // OUTPUT to the screen
    CU_cleanup_registry();//Cleaning the Registry
    return CU_get_error();

}