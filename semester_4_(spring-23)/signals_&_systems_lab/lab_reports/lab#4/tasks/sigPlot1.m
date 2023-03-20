%{
c) Design a function SigPlot that takes the original signals and their sum and product as input 
and plots them as:
i) Separate Figures,
ii) Single Figure overlapping all the signals, and
iiI) Single Figure with separate signal plots using subplots
%}

function sigPlot1(s1, s2, s3, s4)
    figure(1)
    plot(s1)
    xlabel('time')
    ylabel('signal 1')
    title('Graph 1')
    
    figure(2)
    plot(s2)
    xlabel('time')
    ylabel('signal 2')
    title('Graph 2')
    
    figure(3)
    plot(s3)
    xlabel('time')
    ylabel('Sum')
    title('Graph 3')
    
    figure(4)
    plot(s4)
    xlabel('time')
    ylabel('Product')
    title('Graph 4')
    
    figure(5)
    plot(s1,'r')
    hold on
    plot(s2, 'g')
    plot(s3, 'y')
    plot(s4, 'b')
    xlabel('time')
    ylabel('Signals')
    title('Single Figure overlapping all the signals')
    
    figure(6)
    subplot(4, 2, 1)
    plot(s1)
    xlabel('time')
    ylabel('signal 1')
    title('Graph 1')
    subplot(4,2,2)
    plot(s2)
    xlabel('time')
    ylabel('signal 2')
    title('Graph 2')
    subplot(4,2,3)
    plot(s3)
    xlabel('time')
    ylabel('Sum')
    title('Graph 3')
    subplot(4,2,4)
    plot(s4)
    xlabel('time')
    ylabel('Product')
    title('Graph 4')
end