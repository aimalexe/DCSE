num = [1  -2];
denum = [1  2  4  8];
sys = tf(num,denum);
k = [0:1:10];
rlocus(sys,k);
title('Root Locus Plot of G(S)H(S)=K(S-2)/(S+2)(S+2j)(S-2j), for "K=  0 to  10"');