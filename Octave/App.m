# GNU Octave
# Author: Any

function [] = printMenu()

  disp('Selecione uma opçao')
  disp('Questao 1')
  disp('Questao 2')
  disp('Questao 3')
  disp('Questao 4')
  disp('Questao 5')
  disp('Questao 6')

  option = input('Entre com uma opcao: ')
  
  if(option == 1)
    n = input('Digite um valor inteiro e positivo: ')
    soma = SomaInteiros(n);
    disp('Soma dos inteiros positivo ate '), disp(n)
    disp('e igual a '), disp(soma)
  endif
  
  if(option == 2)
    n = input('Digite um valor inteiro e positivo: ')
    Pares(n)
  endif
  
  if(option == 3)
    disp('Entre com tres valores: ')
    a = input('Digite um valor inteiro e positivo: ')
    b = input('Digite um valor inteiro e positivo: ')
    c = input('Digite um valor inteiro e positivo: ')
    Triangulo(a, b, c)
  endif
endfunction