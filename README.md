# fft-dft
Tasl describtion 

Fast Fourier Transform:

There is always a need to speed up the FT calculations. FFT is one of the famous established techniques in this direction. Do your own research on how FFT is designed. Pick one of the FFT implementations and implement it. You also need to implement the basic/standard FT function. i.e. you will deliver two functions: one for FT and one for FFT.

Your implementations will be in C/C++! C is the ultimate language when we look for speed and optimization.
Write your own C code. Do NOT write in python and translate it to C!
Each of your functions should take a signal (array of numbers) and return its FT (array of complex numbers, one array for real and one array for imaginary). NO other input or output argument should be exchanged.
You are free to look for open-source codes and copy from them into your implementation. The main constraint is that your own C function:
should be in one file, and
does NOT include any external headers/import from any other open-source code libraries.
Your C code should be compiled into binaries that can be called in Python. You need to research how to do this.
To validate your implementation, develop a simple program in python that can call your FT functions several times with different signal lengths (e.g N=101, 102, 103,  104, 105, 106). For each call, use python to calculate the time your function will take to return the results. Then, your phyton program should do the following:
Compare the return arrays from both FT and FFT and show the error between them (ideally the two should be identical but there might be some rounding errors in your code. This is okay. You just need to show it).
In one figure, plot the time your implementation takes in both FT and FFT for each N (N is the x-axis, and computation time is the y-axis). You need to show that FT is in the order of N2 while FFT is in the order of NlogN.
 
