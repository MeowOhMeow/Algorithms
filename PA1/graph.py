import matplotlib.pyplot as plt
import math

def get_line_loc(num_points, first, second):
    rad1 = first/num_points
    rad2 = second/num_points
    x1 = math.cos(rad1)
    y1 = math.sin(rad1)
    x2 = math.cos(rad2)
    y2 = math.sin(rad2)
    return (x1, y1, x2, y2)

with open(r'D:\\Programming\\C++\\Algorithms\\PA1\\io\\out\\5000.out', 'r') as f:
    data = f.readlines()
    num_points = int(data[0])
    lines = []
    for i in range(1, len(data)):
        line = data[i].split()
        lines.append((int(line[0]), int(line[1])))
    
    plt.figure(figsize=(8, 8))
    plt.axis('off')
    plt.xlim(-1.1, 1.1)
    plt.ylim(-1.1, 1.1)
    for i in range(len(lines)):
        line = get_line_loc(num_points, lines[i][0], lines[i][1])
        plt.plot([line[0], line[2]], [line[1], line[3]], 'b')
    plt.show()
    


