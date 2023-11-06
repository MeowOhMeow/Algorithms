import matplotlib.pyplot as plt
import math
from tkinter.filedialog import askopenfilename
import os

def get_line_loc(num_points, first, second):
    rad1 = first/num_points*math.pi*2
    rad2 = second/num_points*math.pi*2
    x1 = math.cos(rad1)
    y1 = math.sin(rad1)
    x2 = math.cos(rad2)
    y2 = math.sin(rad2)
    return (x1, y1, x2, y2)

path = askopenfilename(initialdir=os.getcwd(), title='Select file', filetypes=(('Text files', '*.out'), ('All files', '*.*')))

if path == '':
    print('No file selected')
else:
    with open(path, 'r') as f:
        data = f.readlines()
        num_lines = int(path.split('/')[-1].split('.')[0])
        lines = []
        for i in range(1, len(data)):
            line = data[i].split()
            lines.append((int(line[0]), int(line[1])))
        
        plt.figure(figsize=(8, 8))
        plt.axis('off')
        plt.xlim(-1.1, 1.1)
        plt.ylim(-1.1, 1.1)
        for i in range(len(lines)):
            line = get_line_loc(num_lines, lines[i][0], lines[i][1])
            plt.plot([line[0], line[2]], [line[1], line[3]], 'b')
        plt.show()
        


