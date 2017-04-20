# GNU Octave
# Author: Any

function [] = Pares(n)
   
   if n < 0
    disp('Numero precisa ser positivo');
    return;
   endif
   
   for i = 1 : n
      if( mod(i, 2) == 0)
        disp(i);
      endif
   endfor
endfunction