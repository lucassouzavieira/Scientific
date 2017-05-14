# Gnu Octava
# Ordenacao

function [] = Ordenacao(a, b, c)
  if a < b
    if a < c
      disp(a)
      
      if b < c
        disp(b)
        disp(c)
       else
        disp(c)
        disp(b)
      endif
    elseif b < c
        disp(b)
      
      if a < c
        disp(a)
        disp(c)
       else
        disp(c)
        disp(a)
      endif
    endif
  endif
endfunction