# GNU Octave
# Soma de inteiros positivos

function [soma] = SomaInteiros(n)
  soma = 0;
  
  if n < 0
    disp("Numero precisa ser positivo");
    return;
  endif
  
  for i = 1 : n
    soma = soma + i;
  endfor  
endfunction