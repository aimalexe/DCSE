function plotCircle()
    x = input('Enter value of x: ');
    y = input('Enter value of y: ');
    r = input('Enter value of radius: ');
    
    theta = 0 : 1/1000 : 2*pi;
    x = r*cos(theta) + x;
    y = r * sin(theta) + y;
    
    figure (1)
    plot(x, y)