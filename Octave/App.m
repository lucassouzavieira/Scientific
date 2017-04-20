# GNU Octave
# Author: Any

function [] = printMenu()

  disp("Selecione uma opçao");
  disp("Questao 1");
  disp("Questao 2");
  disp("Questao 3");
  disp("Questao 4");
  disp("Questao 5");
  disp("Questao 6");

  option = input("Entre com uma opcao");
  
  if(option == 1)
    soma = SomaInteiros(input("Digite um valor inteiro e positivo"));
    disp(soma);
  endif
  
endfunction