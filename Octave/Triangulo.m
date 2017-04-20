# GNU Octave
# Author: any

function [] = Triangulo(a, b, c)
  if a < b + c
    if b < a + c
      if c < a + b
        disp('Formam triangulo')
        return
      endif 
    endif 
  endif
  
  disp('Nao formam triangulo')
endfunction