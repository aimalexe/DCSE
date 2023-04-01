%{
Write matlab function zprint, which takes a complex number and returns it real part, imaginary 
part, magnitude, phase in radians, and phase in degrees.
%}

function [r, i, m, rad, deg, con, in] = zprint(comp)
    r = real(comp);
    i = imag(comp);
    m = abs(comp);
    rad = angle(comp);
    deg = angle(comp) * 180 / pi;
    %
    con = conj(comp);
    in = inv(comp);
end