%{
Design a function SigPlot that takes the original signals as input from the main calling program 
and plots them as:
i) Separate Figures using stem command,
ii) Single Figure overlapping both the signals using multiple stem commands with hold on,
iii) Single Figure with separate signal plots using subplots and stem commands.
%}

function sigPlot3(s1, s2)
    figure(1)
    stem(s1)
    xlabel('time')
    ylabel('signal 1')
    title('Graph 1')
    
    figure(2)
    stem(s2)
    xlabel('time')
    ylabel('signal 2')
    title('Graph 2')
    
    figure(3)
    stem(s1)
    xlabel('time')
    ylabel('signal 1')
    hold on
    stem(s2)
    xlabel('time')
    ylabel('signal 2')
    title('Graph 3')
    
    figure(4)
    subplot(2, 4, 1)
    stem(s1)
    xlabel('time')
    ylabel('signal 1')
    subplot(2, 4, 2)
    stem(s2)
    xlabel('time')
    ylabel('signal 2')
end
    