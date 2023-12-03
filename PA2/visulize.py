import matplotlib.pyplot as plt
import numpy as np


def detect_overlaps(file_path, num_nets):
    lines = dict()
    with open(file_path, "r") as file:
        for line in file:
            line = line.strip().split()
            if len(line) == 2:
                pass
            else:
                x1, y1, x2, y2 = map(int, line)
                if (x1, y1, x2, y2) in lines:
                    lines[(x1, y1, x2, y2)] += 1
                elif (x2, y2, x1, y1) in lines:
                    lines[(x2, y2, x1, y1)] += 1
                else:
                    lines[(x1, y1, x2, y2)] = 1
    # iterate through the lines summing the number of times each line is used
    s = 0
    for line in lines:
        if lines[line] > num_nets:
            print(line, lines[line])
            s += 1
    return s


def read_file(file_path):
    nets = []

    with open(file_path, "r") as file:
        for line in file:
            line = line.strip().split()

            # Check if the line contains the net_id and the number of routes
            if len(line) == 2:
                net_id, num_routes = map(int, line)
                net = []
            else:
                # Parse the coordinates and add them to the net
                x1, y1, x2, y2 = map(int, line)
                net.append((x1, y1))
                net.append((x2, y2))

            # Check if the net is complete and add it to the list of nets
            if len(net) == num_routes * 2:
                nets.append(net)

    return nets


file_name = "out/10x10.out"
# Coordinates for each net
nets = read_file(file_name)
print(detect_overlaps(file_name, 3))


length = len(nets)
# Plotting each net with a small x-offset
for i, net in enumerate(nets):
    x, y = zip(*net)
    x_offset = np.ones_like(x) * 0.3 / length * i
    y_offset = np.ones_like(y) * 0.3 / length * i
    plt.plot(x + x_offset, y + y_offset, "o-", label="Net {}".format(i + 1))

# Set labels and title
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Lines Connecting Points in Nets with Offset")

# Display legend
plt.legend()

# Display the plot
plt.grid(True)
plt.show()
