%% Atividade de EDO
% Edo = m * ((d^2)x)/(d(t^2)) + kx + u*(dx/dt) = x(t)

syms x(t)
Dx = diff(x);

% Valores das constantes
m = 2;
k = 1;
u = 1;

% EDO
edo = m*diff(x, t, 2) + u*diff(x, t) + k*x == 0;

% Condicoes de contorno
cond1 = x(0) == 0;
cond2 = Dx(0) == 1;

conds = [cond1 cond2];

r = dsolve(edo, conds);

disp(r);
ezplot(r, [-10 10]);
