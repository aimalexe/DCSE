function num3=myThird(num1, num2)
    %This function is a demo
    [r, c] = size(num1)
    num3 = zeros(r, c)
    
    while (c < 3)
    disp('The value is lesser')
    num3(r,l) = num1(r,c)+num2(r,c)
    c = c+l
    end
    