# import numpy as np
# import matplotlib.pyplot as plt

# Fs = 100                  # samples per second
# dt = 1 / Fs               # seconds per sample
# StopTime = 1              # seconds
# t = np.arange(0, StopTime + dt/2, dt)   # seconds

# # cosine wave:
# Fc = 5                    # hertz
# x = np.cos(2 * np.pi * Fc * t)

# # Plot the signal versus time:
# plt.figure()
# plt.plot(t, x)
# plt.xlabel('time (in seconds)')
# plt.title('Signal versus Time')
# plt.show()
import numpy as np
import matplotlib.pyplot as plt

Fs = 100               # samples per second
dt = 1 / Fs
StopTime = 1              # seconds
t = np.arange(0, StopTime + dt/2, dt)   # seconds

Fc = 5
x = np.cos(2 * np.pi * Fc * t)
plt.subplot(2,1,1); plt.plot(t, x);  plt.title('Continuous')
plt.subplot(2,1,2); plt.stem(t, x);  plt.title('Discrete')
plt.show()