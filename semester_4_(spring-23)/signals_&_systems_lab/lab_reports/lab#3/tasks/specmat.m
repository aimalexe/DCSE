%{
Write matlab function that creates a special square matrix that has ones in the first row and first
column, and whose remaining elements are the sum of two elements i.e. the element above and the element
to the left, if the sum is less than 20. Otherwise, the element is the maximum of those two element values.
Name the function specmat with single input defining the matrix dimension
%}

function specmat(size)
for row=1 : size
    for column=1 : size
       if row==1 && column<=size
            matric(row,column) = 1;
       elseif row<=size && column==1
               matric(row,column) = 1;
       else
           temp = matric(row-1,column) + matric(row,column-1);
           if temp < 20
                matric(row, column) = temp;
           elseif matric(row-1,column) > matric(row,column-1)
               matric(row,column) = matric(row-1,column);
           else
               matric(row,column) = matric(row,column-1);
           end
       end
    end
end
disp('The requires matrix is: ');
disp(matric);