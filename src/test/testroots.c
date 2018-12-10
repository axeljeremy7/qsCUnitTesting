#include "../include/quadFun.h"
#include "../include/header.h"
#include "../include/cunit.h"

int 
main(int argc, char const *argv[])
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
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "3.1");
    printf("\tfloat value saved:%.7f\n", root1);
    printf("\tfloat value calculated:%.7lf\n", root1v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "3.3");
    printf("\tfloat value saved:%.7f\n", root2);
    printf("\tfloat value calculated:%.7lf\n", root2v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");

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
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "6.78");
    printf("\tfloat value saved:%.7f\n", root1);
    printf("\tfloat value calculated:%.7lf\n", root1v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "8.05");
    printf("\tfloat value saved:%.7f\n", root2);
    printf("\tfloat value calculated:%.7lf\n", root2v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");

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
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "3.978E12");
    printf("\tfloat value saved:%g\n", root1);
    printf("\tfloat value calculated:%g\n", root1v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "9.95e12");
    printf("\tfloat value saved:%g\n", root2);
    printf("\tfloat value calculated:%g\n", root2v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    
    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);

    root1 = 3.9788777;
    root2 = 9.9599555;
    a = 1.0;
    b = -root1 - root2;
    c = root1 * root2;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    root1v = get_root_minus(a, b, c, d, log);
    root2v = get_root_plus(a, b, c, d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "3.9788777");
    printf("\tfloat value saved:%.7f\n", root1);
    printf("\tfloat value calculated:%.7lf\n", root1v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "9.9599555");
    printf("\tfloat value saved:%.7f\n", root2);
    printf("\tfloat value calculated:%.7lf\n", root2v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    
    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);

    root1 = 89.1234567;
    root2 = 999.7654321;
    a = 1.0;
    b = -root1 - root2;
    c = root1 * root2;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    root1v = get_root_minus(a, b, c, d, log);
    root2v = get_root_plus(a, b, c, d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "89.1234567");
    printf("\tfloat value saved:%.7f\n", root1);
    printf("\tfloat value calculated:%.7lf\n", root1v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "999.7654321");
    printf("\tfloat value saved:%.7f\n", root2);
    printf("\tfloat value calculated:%.7lf\n", root2v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    
    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);

    root1 = -89.1234567;
    root2 = -999.7654321;
    a = 1.0;
    b = -root1 - root2;
    c = root1 * root2;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    root1v = get_root_minus(a, b, c, d, log);
    root2v = get_root_plus(a, b, c, d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "-89.1234567");
    printf("\tfloat value saved:%.7f\n", root1);
    printf("\tfloat value calculated:%.7lf\n", root2v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "-999.7654321");
    printf("\tfloat value saved:%.7f\n", root2);
    printf("\tfloat value calculated:%.7lf\n", root1v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    
    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);

    root1 = 6.78;
    root2 = 8.05;
    a = 10.0;
    b = -root1 - root2;
    c = root1 * root2;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    assert_eq("No roots", pass, 0);

    root1 = 9.56;
    root2 = 9.95;
    a = 1.000399;
    b = -root1 - root2;
    c = root1 * root2;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    root1v = get_root_minus(a, b, c, d, log);
    root2v = get_root_plus(a, b, c, d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "9.56");
    printf("\tfloat value saved:%.7f\n", root1);
    printf("\tfloat value calculated:%.7lf\n", root1v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "9.95");
    printf("\tfloat value saved:%.7f\n", root2);
    printf("\tfloat value calculated:%.7lf\n", root2v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    
    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);


    root1 = 6.8;
    root2 = 5.7;
    b = -root1 - root2;
    c = root1 * root2;
    a = (b*b)/(4.0*c);
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    assert_eq("No roots", pass, 0);
    

    root1 = 9.56;
    root2 = 9.95;;
    a = 1.0004;
    b = -root1 - root2;
    c = root1 * root2;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    assert_eq("No roots", pass, 0);


    root1 = 6.8;
    root2 = 5.7;
    b = -root1 - root2;
    c = root1 * root2;
    a = 1.0078044;
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    root1v = get_root_minus(a, b, c, d, log);
    root2v = get_root_plus(a, b, c, d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "6.8");
    printf("\tfloat value saved:%.7f\n", root1);
    printf("\tfloat value calculated:%.7lf\n", root1v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "5.7");
    printf("\tfloat value saved:%.7f\n", root2);
    printf("\tfloat value calculated:%.7lf\n", root2v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    
    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);


    root1 = 4.0;
    root2 = 6.0;
    b = -root1 - root2;
    c = root1 * root2;
    a = (b*b)/(4.0*c);
    d = discrim(a, b, c, log);
    pass = check_discrim(d, log);
    root1v = get_root_minus(a, b, c, d, log);
    root2v = get_root_plus(a, b, c, d, log);
    printf("\t discriminant is %lf\n", d);
    printf("\t %d vs. %d, 2 means discriminant is ok\n", pass, 2);
    printf("\tRoot #1\n");
    printf("\tfloat value entered:%s\n", "4.0");
    printf("\tfloat value saved:%.7f\n", root1);
    printf("\tfloat value calculated:%.7lf\n", root1v);
    printf("\tRoot #2\n");
    printf("\tfloat value entered:%s\n", "6.0");
    printf("\tfloat value saved:%.7f\n", root2);
    printf("\tfloat value calculated:%.7lf\n", root2v);
    printf("Check ../logs/test2_logs.txt for the unit tests result\n\n");
    
    assert_eq("Two roots", pass, 2);
    assert_feqrerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqrerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 1", root1v, root1, 10.0 * cunit_dmacheps);
    assert_feqaerr("Root 2", root2v, root2, 10.0 * cunit_dmacheps);

 


    return 0;
}
