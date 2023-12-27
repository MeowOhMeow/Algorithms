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
    print("Overflows: ")
    overflows = 0
    overflows_lines = []
    max_capacity = 0
    max_lines = []
    for line in lines:
        if lines[line] > num_nets:
            overflows += 1
            overflows_lines.append(line)
        elif lines[line] == num_nets:
            max_capacity += 1
            max_lines.append(line)
    print("Total overflows: ", overflows)
    print("Overflows lines: ", overflows_lines)
    print("Max capacity: ", max_capacity)
    print("Max capacity lines: ", max_lines)


def read_file(file_path):
    nets = []
    total_length = 0

    with open(file_path, "r") as file:
        for line in file:
            line = line.strip().split()

            # Check if the line contains the net_id and the number of routes
            if len(line) == 2:
                net_id, num_routes = map(int, line)
                total_length += num_routes
                net = []
            else:
                # Parse the coordinates and add them to the net
                x1, y1, x2, y2 = map(int, line)
                net.append((x1, y1))
                net.append((x2, y2))

            # Check if the net is complete and add it to the list of nets
            if len(net) == num_routes * 2:
                nets.append(net)

    return nets, total_length


table = [
    {"file_name": "out/4x4.out", "max": 2, "draw": True},
    {"file_name": "out/5x5.out", "max": 3, "draw": True},
    {"file_name": "out/10x10.out", "max": 45, "draw": True},
    {"file_name": "out/20x20.out", "max": 45, "draw": False},
    {"file_name": "out/60x60.out", "max": 45, "draw": False},
]
config = table[2]

# Coordinates for each net
nets, total_length = read_file(config["file_name"])
print("Total length: ", total_length)
detect_overlaps(config["file_name"], config["max"])


if config["draw"]:
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
