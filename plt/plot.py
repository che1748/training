import matplotlib.pyplot as plt
import numpy as np

with open('../data/output.dat', 'r') as file:
    # create a dictionary to store the data
    data = {}
    
    # Read the data
    for line in file:
        cleaned_line = line.strip().split()
        float_line = [float(x) for x in cleaned_line[1:]]
        data[cleaned_line[0]] = float_line
    
    fig1 = plt.figure() # This figure shows all the solutions
    fig2 = plt.figure() # This figure shows the error for the numerical solutions compared to the analytical solution.
    ax1 = fig1.add_subplot()
    ax2 = fig2.add_subplot()

    # Plot the analytical solution
    xx = np.linspace(0,9,4000)
    f = lambda x: np.exp(-3*x)
    ax1.plot(xx, f(xx), label='analytical solution')

    # make a list so the iteration becomes easier
    xlist = ['x1', 'x2', 'x3', 'x4', 'x5', 'x6']
    ylist = ['y1', 'y2', 'y3', 'y4', 'y5', 'y6']

    # Plot the solution for different timesteps
    for i in range(0,6):
        x = np.array(data[xlist[i]])
        y = np.array(data[ylist[i]])
        
        err = abs(y - f(x))/f(x)*100
        tstep = x[1] - x[0]
        ax1.plot(x,y, label=f'tstep={tstep}')
        ax2.plot(x,err, label=f'tstep={tstep}')

    ax1.set_xlabel('x')
    ax1.set_ylabel('y')
    ax1.set_ylim(0,1)
    ax1.legend()
    fig1.savefig('odesolution.pdf')
    
    ax2.set_ylabel('percent error')
    ax2.set_xlabel('x')
    ax2.legend()
    fig2.savefig('error.pdf')
    
