num = [1 7 12]; % Numerator coefficients: k*(s+3)*(s+4)
den = [1 11 30]; % Denominator coefficients: (s+5)*(s+6)
sys=tf(num,den);  
sisotool(sys);