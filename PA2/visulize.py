import matplotlib.pyplot as plt
import numpy as np

def count_segments(nets, theshold):
    count = 0
    for net in nets:
        for i in range(len(net)-1):
            if abs(net[i][0]-net[i+1][0]) + abs(net[i][1]-net[i+1][1]) > theshold:
                count += 1
    return count

# Coordinates for each net
nets = [
    [(3, 3), (3, 2), (3, 1), (3, 0)],
    [(3, 1), (3, 0), (4, 0)],
    [(1, 3), (0, 3), (0, 2)],
    [(3, 4), (2, 4), (1, 4), (0, 4), (0, 3)],
    [(0, 2), (0, 1), (0, 0)],
    [(4, 0), (3, 0), (2, 0), (1, 0), (0, 0), (0, 1), (0, 2), (0, 3), (0, 4)],
    [(3, 0), (3, 1), (3, 2), (3, 3), (3, 4)],
    [(4, 2), (3, 2), (2, 2), (2, 3), (2, 4)],
    [(0, 0), (0, 1), (0, 2), (0, 3), (0, 4), (1, 4), (2, 4)],
    [(3, 0), (4, 0)],
]

print(f'Overflows: {count_segments(nets, 3)}')

length = len(nets)
# Plotting each net with a small x-offset
for i, net in enumerate(nets):
    x, y = zip(*net)
    x_offset = np.ones_like(x) * 0.3/length * i
    y_offset = np.ones_like(y) * 0.3/length * i
    plt.plot(x + x_offset, y + y_offset, 'o-', label='Net {}'.format(i+1))

# Set labels and title
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Lines Connecting Points in Nets with Offset')

# Display legend
plt.legend()

# Display the plot
plt.grid(True)
plt.show()
