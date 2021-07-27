#include <iostream>
#include<math.h>
#include <iterator>
#include<complex>
#include <iostream>
using namespace std;
#define PI 3.141592653589793238460
typedef complex<double> Complex;


// extern "C"
// {
// void DFT(double input[], int size,double *a,double *b, complex<double> *c );    
// void fft(double y[], double z[], int size ,double *r, double *im,complex<double> *x);

// }

void DFT(double input[], int size,double *a,double *b, complex<double> *c ){    
// complex<double> c[size];
for (int k = 0; k <size ; k++) {   
    for (int i = 0; i < size; i++){
        auto phase = (2 * PI * k * i) / size;
         a[k] += cos(phase) * input[i];
         b[k] += - sin(phase) * input[i];
         } 
         c[k]= complex<double>(a[k],b[k]);
         cout<<c[k]<<endl;
}
   copy(a, a + size,ostream_iterator<double>(cout, " "));
   cout<<endl;
   copy(b, b + size ,ostream_iterator<double>(cout, " "));
   cout<<endl;
}


void fft(double y[], double z[], int size ,double *r, double *im, complex<double> *x)
{
	// DFT
    // Complex x[size];
    for (int i=0 ; i<size ; ++i)
    {
     x[i]=(z[i], y[i]);
    }
	unsigned int  k = size, n;
	double thetaT = 3.14159265358979323846264338328L / size;
	Complex phiT = Complex(cos(thetaT), -sin(thetaT)), T;
	while (k > 1)
	{
		n = k;
		k >>= 1;
		phiT = phiT * phiT;
		T = 1.0L;
		for (unsigned int l = 0; l < k; l++)
		{
			for (unsigned int a = l; a < size; a += n)
			{
				unsigned int b = a + k;
				Complex t = x[a] - x[b];//
				x[a] += x[b];
				x[b] = t * T;
			}
			T *= phiT;
		}
	}
	// Decimate
	unsigned int m = (unsigned int)log2(size);
	for (unsigned int a = 0; a < size; a++)
	{   
		unsigned int b = a;
		// Reverse bits
		b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
		b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
		b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
		b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
		b = ((b >> 16) | (b << 16)) >> (32 - m);
		if (b > a)
		{   
			Complex t = x[a];
			x[a] = x[b];
			x[b] = t;
            
		}
        std::cout<<x[b]<<std::endl;
        }

        for (int l=0; l<size ;++l){
            r[l]= real(x[l]);
            im[l]= imag(x[l]);
        }

        copy(r, r + size,std::ostream_iterator<double>(std::cout, " "));
        std::cout<<std::endl;
        copy(im, im + size,std::ostream_iterator<double>(std::cout, " "));
        std::cout<<std::endl;
         }


int main(){
double input[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
// double imag[]={0,0,0,0,0,0,0,0,0,0};
const int size = sizeof(input)/sizeof(input[0]);
double a[size];
double b[size];
complex<double> e[size];
DFT(input, size, a,b,e);
double test[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
double imaginary[]={0,0,0,0,0,0};
const int size1 = sizeof(test)/sizeof(test[0]);
double c[size1];
double d[size1];
complex<double> f[size];
fft(test, imaginary, size1,c,d,f);
}

// g++ -fPIC -shared -o lib.so final.cpp




 
//  int main()
// {
//     double test[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
//     double imaginary[]={0,0,0,0,0,0,0,0};
//     const int size = sizeof(test)/sizeof(test[0]);
//     double a[size];
//     double b[size];
//     fft(test, imaginary, size,a,b);
// }  


// #include <iostream>
// #include <complex>
// #include <cmath>
// #include <iterator>

// using namespace std;

// unsigned int bitReverse(unsigned int x, int log2n) {
//   int n = 0;
//   int mask = 0x1;
//   for (int i=0; i < log2n; i++) {
//     n <<= 1;
//     n |= (x & 1);
//     x >>= 1;
//   }
//   return n;
// }

// const double PI = 3.1415926536;

// template<class Iter_T>
// void fft(Iter_T a, Iter_T b, int log2n)
// {
//   typedef typename iterator_traits<Iter_T>::value_type complex;
//   const complex J(0, 1);
//   int n = 1 << log2n;
//   for (unsigned int i=0; i < n; ++i) {
//     b[bitReverse(i, log2n)] = a[i];
//   }
//   for (int s = 1; s <= log2n; ++s) {
//     int m = 1 << s;
//     int m2 = m >> 1;
//     complex w(1, 0);
//     complex wm = exp(-J * (PI / m2));
//     for (int j=0; j < m2; ++j) {
//       for (int k=j; k < n; k += m) {
//         complex t = w * b[k + m2];
//         complex u = b[k];
//         b[k] = u + t;
//         b[k + m2] = u - t;
//       }
//       w *= wm;
//     }

//   }
//         double r[8];
//         double im[8];
//         for (int l=0; l<8 ;++l){
//         r[l]= real(b[l]);
//         im[l]= imag(b[l]);}
//         copy(r, r + 8,std::ostream_iterator<double>(std::cout, " "));
//         std::cout<<std::endl;
//         copy(im, im + 8,std::ostream_iterator<double>(std::cout, " "));
//         std::cout<<std::endl;

// }

// int main() {
//   typedef complex<double> cx;
//   cx a[] = { cx(1,0), cx(2,0), cx(3,0), cx(4,0), 
//     cx(5, 0), cx(6, 0), cx(7,0), cx(8,0) };
//   cx b[8];
//   fft(a, b, 3);

// }

