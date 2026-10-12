import numpy as np
import matplotlib.pyplot as plt

Fs = 100                  # samples per second
dt = 1 / Fs               # seconds per sample
StopTime = 1              # seconds
t = np.arange(0, StopTime + dt/2, dt)   # seconds

# cosine wave:
Fc = 5                    # hertz
x = np.cos(2 * np.pi * Fc * t)

# Plot the signal versus time:
plt.figure()
plt.plot(t, x)
plt.xlabel('time (in seconds)')
plt.title('Signal versus Time')
plt.show()