import ctypes
import numpy as np
import matplotlib.pyplot as plt
from numpy.ctypeslib import ndpointer
import random
import time
lib = ctypes.CDLL('D:/desk/dsp3/final/final.so')
x=[]
num=[64,256,1024,2048,4096,8192]
time2=[]
time1=[]
error=[]
for i in num:
    x = random.sample(range(i), i)
    # print(x)
    lzero = [0] * i
    real_input = np.array(x, dtype=np.double)
    imaginary_input = np.array(lzero, dtype=np.double)
    size= len(real_input)
    dft_real_output = np.array(imaginary_input, dtype=np.double)
    dft_imaginary_output = np.array(imaginary_input, dtype=np.double)
    dft_complex_output = np.array(imaginary_input, dtype=np.complex_)
    fft_real_output = np.array(imaginary_input, dtype=np.double)
    fft_imaginary_output = np.array(imaginary_input , dtype=np.double)
    fft_complex_output = np.array(imaginary_input, dtype=np.complex_)
    lib.DFT.restype = None
    lib.fft.restype = None
    lib.DFT.argtypes = [ndpointer(flags="C"), ctypes.c_int, ndpointer(flags="C"), ndpointer(flags="C"), ndpointer(flags="C")]
    lib.fft.argtypes = [ndpointer(flags="C"),ndpointer(flags="C"),ctypes.c_int, ndpointer(flags="C"), ndpointer(flags="C"), ndpointer(flags="C")]
    start_time = time.time()
    lib.DFT(real_input, size, dft_real_output, dft_imaginary_output, dft_complex_output)
    end_time = time.time()
    time1.append(end_time - start_time)
    start_time1 = time.time()
    lib.fft(real_input, imaginary_input, size, fft_real_output, fft_imaginary_output,fft_complex_output)
    end_time1 = time.time()
    time2.append(end_time1 - start_time1)
    error.append(abs((np.square(dft_complex_output - fft_complex_output)).mean()))
plt.figure(figsize=(12,6))
plt.subplot(1,3,1)
plt.plot(num,time1)
plt.plot(num,time2)
# plt.subplot(1,3,2)
plt.plot(num,time2)
plt.subplot(1,3,3)
plt.plot(num,error)
plt.show()