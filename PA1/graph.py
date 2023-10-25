import matplotlib.pyplot as plt

with open(r'D:\\Programming\\C++\\Algorithms\\PA1\\io\\out\\5000.out', 'r') as f:
    lines = f.readlines()
    x = [int(line.split()[0]) for line in lines]
    # draw
    plt.plot(x)
    plt.xlabel('n')
    plt.ylabel('value')
    plt.show()
