#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <conio.h>

/*  Source by CPPREference
    Modified For Learn by Rizky Khapidsyah 
    I.D.E : VS2019 */

int main(void) {
    printf("(1,1) cartesian is (%f,%f) polar\n", hypot(1, 1), atan2(1, 1));
    printf("hypot(NAN,INFINITY) = %f\n", hypot(NAN, INFINITY));

    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("hypot(DBL_MAX,DBL_MAX) = %f\n", hypot(DBL_MAX, DBL_MAX));

    if (errno == ERANGE) {
        perror("    errno == ERANGE");
    }

    if (fetestexcept(FE_OVERFLOW)) {
        puts("    FE_OVERFLOW raised");
    }

    _getch();
    return 0;
}