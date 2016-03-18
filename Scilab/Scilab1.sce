//                      SCILAB                //
//          Funções de Entrada e Saída      //

whos; // Exibe as constantes do programa

//          FUNÇÕES DE SAÍDA        // 
// Exibir variáveis na tela do console
disp(%pi);

// Imprime variáveis em um arquivo (a variável deve ser definida pelo usuário)
piNumber = %pi;
//print('piConstant.txt',piNumber);

// Saída formatada de Sistemas Lineare
a=[1 1;0 1];b=[0 1;1 0];c=[1,1];d=[3,2];
ssprint(syslin('c',a,b,c,d))
ssprint(syslin('d',a,b,c,d))

// Saída formatada na tela do console
mprintf("Bem-vindo ao Scilab");

//Formata dados para uma string
str = msprintf('%5.3f %5.3f', 123, 0.763);
disp(str);

// Retorna uma representação em LaTex do texto (prettyprint)
s=poly(0,'s'); G=[1,s;1+s^2,3*s^3];
xstring(0.2,0.2,prettyprint(G*s-1)); // Show a polynom through a LaTeX representation

// Salva arquivos com uma varíavel
save("piConstant.dat",'piNumber');
load("piConstant.dat",piNumber);
