void dgemm2(double *C,double *A,double *B,int n)
{
    // 12 registers
    int i, j, k;
    for (i=0; i<n; i+=2){
        for (j=0; j<n; j+=2){
            register int t = i*n+j;
            register int tt = t+n;

            register double c00 = C[t];
            register double c01 = C[t+1];
            register double c10 = C[tt];
            register double c11 = C[tt+1];

            for (k=0; k<n; k+=2){
                register int ta = i*n+k;
                register int tta = ta+n;
                register int tb = k*n+j;
                register int ttb = tb+n;

                register double a00 = A[ta];
                register double a01 = A[ta+1];
                register double a10 = A[tta];
                register double a11 = A[tta+1];

                register double b00 = B[tb];
                register double b01 = B[tb+1];
                register double b10 = B[ttb];
                register double b11 = B[ttb+1];

                c00 += a00*b00 + a01*b10;
                c01 += a00*b01 + a01*b11;
                c10 += a10*b00 + a11*b10;
                c11 += a10*b01 + a11*b11;
            }

            C[t] = c00;
            C[t+1] = c01;
            C[tt] = c10;
            C[tt+1] = c11;

        }
    }
}
