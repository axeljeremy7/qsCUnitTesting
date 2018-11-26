#include "../include/quadFun.h"
#include "../include/header.h"
#include "../include/cunit.h"

int main(int argc, char const *argv[])
{
    FILE *log;
    log = stderr;
    float root1 = 3.1;
    float root2 = 3.3;
    float a = 1.0;
    float b = -root1 - root2;
    float c = root1 * root2;
    double d = discrim(a, b, c, log);
    int pass = check_discrim(d, log);
    double root1v = get_root_minus(a, b, c, d, log);
    double root2v = get_root_plus(a, b, c, d, log);

    printf("%d vs. %d\n", pass, 2);
    printf("%lf vs %f\n", root1v, root1);
    printf("%lf vs %f\n", root2v, root2);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n");

    cunit_init();

    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);

    root1 = 6.78;
    root2 = 8.05;
    a = 1.0;
    b = -root1 - root2;
    c = root1 * root2;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    root1v = get_root_minus(a, b, c, d, log);
    root2v = get_root_plus(a, b, c, d, log);
    printf("%d vs. %d\n", pass, 2);
    printf("%lf vs %f\n", root1v, root1);
    printf("%lf vs %f\n", root2v, root2);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n");

    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);

    root1 = 3.978E12;
    root2 = 9.95e12;
    a = 1.0;
    b = -root1 - root2;
    c = root1 * root2;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    root1v = get_root_minus(a, b, c, d, log);
    root2v = get_root_plus(a, b, c, d, log);
    printf("%d vs. %d\n", pass, 2);
    printf("%lf vs %f\n", root1v, root1);
    printf("%lf vs %f\n", root2v, root2);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n");
    
    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);


    return 0;
}
