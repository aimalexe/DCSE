function ampScale(s, t)
   size = length(s);
   count = 0;
   ampSig = 0;
   for i = 1: size
       if( s(i) > t || s(i) < -t)
           count = count + 1;
           ampSig(1, count) = s(i);
       end
       stem(ampSig, '*', '-m')
   end
   disp('The number of count greater than t or less than -t are: ');
   disp(count);
end