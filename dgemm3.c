void dgemm3(double *C,double *A,double *B,int n)
{
    // 16 registers
    int i, j, k;
    for (i=0; i<n; i+=2){
        for (j=0; j<n; j+=2){
            register int t = i*n+j;
            register int tt = t+n;

            register double c00 = C[t];
            register double c01 = C[t+1];
            register double c10 = C[tt];
            register double c11 = C[tt+1];

            for (k=0; k<n; k+=3){
                register int ta = i*n+k;
                register int tta = ta+n;
                register int tb = k*n+j;
                register int ttb = tb+n;
                register int tttb = ttb+n;

                register double a000 = A[ta];
                register double a001 = A[ta+1];
                register double a010 = A[ta+2];
                register double a011 = A[tta];
                register double a100 = A[tta+1];
                register double a101 = A[tta+2];

                register double b000 = B[tb];
                register double b001 = B[tb+1];
                register double b010 = B[ttb];
                register double b011 = B[ttb+1];
                register double b100 = B[tttb];
                register double b101 = B[tttb+1];

                c00 += a000*b000 + a001*b010 + a010*b100;
                c01 += a000*b001 + a001*b011 + a010*b101;
                c10 += a011*b000 + a100*b010 + a101*b100;
                c11 += a011*b001 + a100*b011 + a101*b101;
            }

            C[t] = c00;
            C[t+1] = c01;
            C[tt] = c10;
            C[tt+1] = c11;

        }
    }
}
