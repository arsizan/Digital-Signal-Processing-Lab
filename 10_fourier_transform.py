import numpy as np
import matplotlib.pyplot as plt

# ---------------------------------------------------------
# DIRECT TRANSLATION OF MATLAB SCRIPT
# ---------------------------------------------------------
Fs = 100                   # samples per second[cite: 2]
dt = 1 / Fs                # seconds per sample[cite: 2]
StopTime = 1               # seconds[cite: 2]

# np.arange(start, stop, step) excludes the stop value, 
# so we add 'dt' to include StopTime, matching MATLAB's 0:dt:StopTime[cite: 2]
t = np.arange(0, StopTime + dt, dt) 

## cosine wave:[cite: 2]
Fc = 5                     # hertz[cite: 2]
x = np.cos(2 * np.pi * Fc * t) #[cite: 2]
X = np.fft.fft(x)          #[cite: 2]


# ---------------------------------------------------------
# FINISHING THE UNFINISHED SCRIPT (Visualization)
# ---------------------------------------------------------
# 1. Calculate the frequency axis matching the FFT output
N = len(X)
f = np.fft.fftfreq(N, d=dt)

# 2. Shift zero-frequency components to the center of the spectrum
f_shifted = np.fft.fftshift(f)
X_shifted = np.fft.fftshift(X)

# 3. Calculate normalized magnitude
magnitude = np.abs(X_shifted) / N 

# 4. Plot the time-domain signal and frequency-domain spectrum
plt.figure(figsize=(10, 6))

# Time Domain Plot
plt.subplot(2, 1, 1)
plt.plot(t, x, color='b')
plt.title(f'Time Domain Signal (Fc = {Fc} Hz)')
plt.xlabel('Time (seconds)')
plt.ylabel('Amplitude')
plt.grid(True)

# Frequency Domain Plot (Magnitude Spectrum)
plt.subplot(2, 1, 2)
# Using a stem plot is standard for discrete frequency spectra
plt.stem(f_shifted, magnitude, basefmt=" ", linefmt='r-', markerfmt='ro')
plt.title('Frequency Domain: Magnitude Spectrum')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.xlim(-10, 10) # Zoomed in to clearly show the peaks at +5Hz and -5Hz
plt.grid(True)

plt.tight_layout()
plt.show()